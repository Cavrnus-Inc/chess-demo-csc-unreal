#pragma once

#include <Containers/Map.h>
#include "../../Public/Types/CavrnusBinding.h"
#include "../../Public/Types/CavrnusCallbackTypes.h"

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

		void UpdateStringPropVal(FString fullPropertyId, FString value);
		void UpdateBoolPropVal(FString fullPropertyId, bool value);
		void UpdateFloatPropVal(FString fullPropertyId, float value);
		void UpdateColorPropVal(FString fullPropertyId, FLinearColor value);
		void UpdateVectorPropVal(FString fullPropertyId, FVector4 value);
		void UpdateTransformPropVal(FString fullPropertyId, FTransform value);

		FCavrnusBinding BindStringProperty(FString fullPropertyId, FStringPropertyUpdated callback);
		FCavrnusBinding BindBoolProperty(FString fullPropertyId, FBoolPropertyUpdated callback);
		FCavrnusBinding BindFloatProperty(FString fullPropertyId, FFloatPropertyUpdated callback);
		FCavrnusBinding BindColorProperty(FString fullPropertyId, FColorPropertyUpdated callback);
		FCavrnusBinding BindVectorProperty(FString fullPropertyId, FVectorPropertyUpdated callback);
		FCavrnusBinding BindTransformProperty(FString fullPropertyId, FTransformPropertyUpdated callback);
		FCavrnusBinding BindUserVideoTexture(FCavrnusUser& User, FCavrnusUserVideoFrameEvent callback);

		FString GetStringPropValue(FString fullPropertyId);
		bool GetBoolPropValue(FString fullPropertyId);
		float GetFloatPropValue(FString fullPropertyId);
		FLinearColor GetColorPropValue(FString fullPropertyId);
		FVector4 GetVectorPropValue(FString fullPropertyId);
		FTransform GetTransformPropValue(FString fullPropertyId);

		void AddSpaceUser(FCavrnusUser user);
		void RemoveSpaceUser(FString userId);
		void UpdateUserVideoTexture(FString userId, int ResX, int ResY, const TArray<uint8>& ByteArray);

		void AwaitLocalUser(FCavrnusSpaceUserEvent localUserArrived);
		FCavrnusBinding BindSpaceUsers(FCavrnusSpaceUserEvent userAdded, FCavrnusSpaceUserEvent userRemoved);

		TMap<FString, FCavrnusUser> CurrSpaceUsers;
		FCavrnusUser* LocalUser;

	private:
		CaseSensitiveMap<FString, bool> CurrDefinedProps;

		CaseSensitiveMap<FString, FString> CurrStringPropValues;
		CaseSensitiveMap<FString, bool> CurrBoolPropValues;
		CaseSensitiveMap<FString, float> CurrFloatPropValues;
		CaseSensitiveMap<FString, FLinearColor> CurrColorPropValues;
		CaseSensitiveMap<FString, FVector4> CurrVectorPropValues;
		CaseSensitiveMap<FString, FTransform> CurrTransformPropValues;

		CaseSensitiveMap<FString, TArray<FStringPropertyUpdated>> StringPropBindings;
		CaseSensitiveMap<FString, TArray<FBoolPropertyUpdated>> BoolPropBindings;
		CaseSensitiveMap<FString, TArray<FFloatPropertyUpdated>> FloatPropBindings;
		CaseSensitiveMap<FString, TArray<FColorPropertyUpdated>> ColorPropBindings;
		CaseSensitiveMap<FString, TArray<FVectorPropertyUpdated>> VectorPropBindings;
		CaseSensitiveMap<FString, TArray<FTransformPropertyUpdated>> TransformPropBindings;

		TArray<FCavrnusSpaceUserEvent> LocalUserArrivedCallbacks;

		TArray<FCavrnusSpaceUserEvent> UserAddedBindings;
		TArray<FCavrnusSpaceUserEvent> UserRemovedBindings;

		TMap<FString, TArray<FCavrnusUserVideoFrameEvent>> UserVideoFrameBindings;

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