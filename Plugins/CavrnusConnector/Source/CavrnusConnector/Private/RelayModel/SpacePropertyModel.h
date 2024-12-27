﻿// Copyright(c) Cavrnus. All rights reserved.
#pragma once

#include <Containers/Map.h>
#include "Types/CavrnusBinding.h"
#include "Types/CavrnusCallbackTypes.h"
#include "Types/AbsolutePropertyId.h"
#include "Types/CavrnusPropertyValue.h"
#include "Types/PropertiesContainer.h"
#include "Types/CavrnusSpaceConnection.h"
#include "SpaceChatModel.h"

namespace Cavrnus
{
	template<typename TValueType>
	struct FCaseSensitiveLookupKeyFuncs : BaseKeyFuncs<TValueType, FString>
	{
		static FORCEINLINE const FString& GetSetKey(const TPair<FString, TValueType>& Element)
		{
			return Element.Key;
		}
		static FORCEINLINE bool Matches(const FString& A, const FString& B)
		{
			return A.Equals(B, ESearchCase::CaseSensitive);
		}
		static FORCEINLINE uint32 GetKeyHash(const FString& Key)
		{
			return FCrc::StrCrc32<TCHAR>(*Key);
		}
	};

	template <typename K,typename T> using CaseSensitiveMap = TMap<K, T, FDefaultSetAllocator, FCaseSensitiveLookupKeyFuncs<T>>;

	class SpacePropertyModel
	{
	public:
		SpacePropertyModel();
		virtual ~SpacePropertyModel();

		SpaceChatModel* ChatModel = nullptr;

		void UpdateServerPropVal(FAbsolutePropertyId fullPropertyId, FPropertyValue value);
		int SetLocalPropVal(FAbsolutePropertyId fullPropertyId, FPropertyValue value);
		void InvalidateLocalPropValue(FAbsolutePropertyId fullPropertyId, int propValidationId);
		void UpdatePropMetadata(FAbsolutePropertyId fullPropertyId, bool isReadonly);

		UCavrnusBinding* BindProperty(FAbsolutePropertyId fullPropertyId, CavrnusPropertyFunction callback);

		UCavrnusBinding* BindUserVideoTexture(const FCavrnusUser& User, VideoFrameUpdateFunction callback);

		bool PropValueExists(FAbsolutePropertyId fullPropertyId);

		Cavrnus::FPropertyValue GetPropValue(FAbsolutePropertyId fullPropertyId);

		void SetIsDefined(FAbsolutePropertyId fullPropertyId);
		TArray<FAbsolutePropertyId> CurrDefinedProps;

		void AddSpaceUser(const FCavrnusUser& user);
		void RemoveSpaceUser(FString userId);
		void UpdateUserVideoTexture(FString userId, int ResX, int ResY, const TArray<uint8>& ByteArray);

		void AwaitLocalUser(CavrnusSpaceUserEvent localUserArrived);
		UCavrnusBinding* BindSpaceUsers(CavrnusSpaceUserEvent userAdded, CavrnusSpaceUserEvent userRemoved);

		CaseSensitiveMap<FString, FCavrnusUser> CurrSpaceUsers;
		CaseSensitiveMap<FString, UTexture2D*> CurrSpaceUsersVideoTextures;
		TMap<FPropertiesContainer, FCavrnusSpawnedObject> SpawnedObjects;

		FCavrnusUser LocalUser;
		bool hasLocalUser = false;

	private:
		TMap<FAbsolutePropertyId, FPropertyValue> CurrServerPropValues;
		TMap<FAbsolutePropertyId, FPropertyValue> CurrLocalPropValues;

		TMap<FAbsolutePropertyId, bool> CurrPropReadonlyMetadata;

		int validationIdIncrementer = 0;
		TMap<FAbsolutePropertyId, int> LocalPropValidationIds;
				
		TMap<FAbsolutePropertyId, TArray<CavrnusPropertyFunction*>> PropBindings;

		TArray<CavrnusSpaceUserEvent*> LocalUserArrivedCallbacks;

		TArray<CavrnusSpaceUserEvent*> UserAddedBindings;
		TArray<CavrnusSpaceUserEvent*> UserRemovedBindings;

		TMap<FString, TArray<VideoFrameUpdateFunction*>> UserVideoFrameBindings;

		FPropertyValue GetCurrentPropValue(FAbsolutePropertyId fullPropertyId);
		void TryExecPropBindings(FAbsolutePropertyId fullPropertyId);

		FString GetContainerName(FString fullPropId)
		{
			TArray<FString> split;
			fullPropId.ParseIntoArray(split, TEXT("/"), false);

			FString res;

			for (int i = 0; i < split.Num() - 1; i++)
			{
				res += split[i] + "/";
			}

			res.RemoveFromEnd("/");

			return res;
		}

		FString GetPropertyName(FString fullPropId)
		{
			TArray<FString> split;
			fullPropId.ParseIntoArray(split, TEXT("/"), false);
			return split.Last();
		}
	};

} // namespace CavrnusRelay