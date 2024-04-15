﻿#include "SpacePropertyModel.h"

namespace Cavrnus
{
	SpacePropertyModel::SpacePropertyModel(){}

	SpacePropertyModel::~SpacePropertyModel(){}

	void SpacePropertyModel::UpdateServerPropVal(PropertyId fullPropertyId, FPropertyValue value)
	{
		if (!CurrServerPropValues.Contains(fullPropertyId))
		{
			CurrServerPropValues.FindOrAdd(fullPropertyId);
		}
		
		CurrServerPropValues[fullPropertyId] = value;
		TryExecPropBindings(fullPropertyId);
	}

	int SpacePropertyModel::SetLocalPropVal(PropertyId fullPropertyId, FPropertyValue value)
	{
		//We treat this like a has, but use a dict cuz stupid string comparison stuff
		if (CurrPropReadonlyMetadata.Contains(fullPropertyId)) 
		{
			return -1;
		}

		if (!CurrLocalPropValues.Contains(fullPropertyId))
		{
			CurrLocalPropValues.FindOrAdd(fullPropertyId);
			LocalPropValidationIds.FindOrAdd(fullPropertyId);
		}

		CurrLocalPropValues[fullPropertyId] = value;
		TryExecPropBindings(fullPropertyId);

		validationIdIncrementer++;
		LocalPropValidationIds[fullPropertyId] = validationIdIncrementer;
		return validationIdIncrementer;
	}

	FPropertyValue SpacePropertyModel::GetCurrentPropValue(PropertyId fullPropertyId)
	{
		//Returns an invalid value
		if (!PropValueExists(fullPropertyId))
			return FPropertyValue();

		if (!CurrServerPropValues.Contains(fullPropertyId))
			return CurrLocalPropValues[fullPropertyId];

		if (!CurrLocalPropValues.Contains(fullPropertyId))
			return CurrServerPropValues[fullPropertyId];

		if (CurrServerPropValues[fullPropertyId].Priority > CurrLocalPropValues[fullPropertyId].Priority)
			return CurrServerPropValues[fullPropertyId];

		return CurrLocalPropValues[fullPropertyId];
	}

	void SpacePropertyModel::InvalidateLocalPropValue(PropertyId fullPropertyId, int propValidationId)
	{
		if (LocalPropValidationIds.Contains(fullPropertyId) && LocalPropValidationIds[fullPropertyId] == propValidationId)
		{
			LocalPropValidationIds.Remove(fullPropertyId);

			const FPropertyValue& oldPropVal = GetCurrentPropValue(fullPropertyId);

			CurrLocalPropValues.Remove(fullPropertyId);
			
			const FPropertyValue& newPropVal = GetCurrentPropValue(fullPropertyId);

			bool changed = !(newPropVal == oldPropVal);
			if (changed)
				TryExecPropBindings(fullPropertyId);
		}
	}

	void SpacePropertyModel::UpdatePropMetadata(PropertyId fullPropertyId, bool isReadonly)
	{
		if (!isReadonly && CurrPropReadonlyMetadata.Contains(fullPropertyId)) 
		{
			CurrPropReadonlyMetadata.Remove(fullPropertyId);
		}
		else if (isReadonly && !CurrPropReadonlyMetadata.Contains(fullPropertyId)) 
		{
			CurrPropReadonlyMetadata.Add(fullPropertyId, true);
		}

		if (isReadonly && LocalPropValidationIds.Contains(fullPropertyId)) 
		{
			LocalPropValidationIds.Remove(fullPropertyId);

			const FPropertyValue& oldPropVal = GetCurrentPropValue(fullPropertyId);

			CurrLocalPropValues.Remove(fullPropertyId);

			const FPropertyValue& newPropVal = GetCurrentPropValue(fullPropertyId);

			bool changed = !(newPropVal == oldPropVal);
			if (changed)
				TryExecPropBindings(fullPropertyId);
		}
	}

	void SpacePropertyModel::TryExecPropBindings(PropertyId fullPropertyId)
	{
		const FPropertyValue& activePropVal = GetCurrentPropValue(fullPropertyId);

		//This shouldn't happen, but could potentially when handling oddly ordered stuff.
		//We'll ignore it since it shouldn't be the case for long.
		if (activePropVal.PropType == FPropertyValue::PropertyType::Invalid)
			return;

		if (activePropVal.PropType == FPropertyValue::PropertyType::String && StringPropBindings.Contains(fullPropertyId))
		{
			for (int i = 0; i < StringPropBindings[fullPropertyId].Num(); i++)
				(*StringPropBindings[fullPropertyId][i])(activePropVal.StringValue, fullPropertyId.ContainerName, fullPropertyId.PropValueId);
		}
		else if (activePropVal.PropType == FPropertyValue::PropertyType::Bool && BoolPropBindings.Contains(fullPropertyId))
		{
			for (int i = 0; i < BoolPropBindings[fullPropertyId].Num(); i++)
				(*BoolPropBindings[fullPropertyId][i])(activePropVal.BoolValue, fullPropertyId.ContainerName, fullPropertyId.PropValueId);
		}
		else if (activePropVal.PropType == FPropertyValue::PropertyType::Float && FloatPropBindings.Contains(fullPropertyId))
		{
			for (int i = 0; i < FloatPropBindings[fullPropertyId].Num(); i++)
				(*FloatPropBindings[fullPropertyId][i])(activePropVal.FloatValue, fullPropertyId.ContainerName, fullPropertyId.PropValueId);
		}
		else if (activePropVal.PropType == FPropertyValue::PropertyType::Color && ColorPropBindings.Contains(fullPropertyId))
		{
			for (int i = 0; i < ColorPropBindings[fullPropertyId].Num(); i++)
				(*ColorPropBindings[fullPropertyId][i])(activePropVal.ColorValue, fullPropertyId.ContainerName, fullPropertyId.PropValueId);
		}
		else if (activePropVal.PropType == FPropertyValue::PropertyType::Vector && VectorPropBindings.Contains(fullPropertyId))
		{
			for (int i = 0; i < VectorPropBindings[fullPropertyId].Num(); i++)
				(*VectorPropBindings[fullPropertyId][i])(activePropVal.VectorValue, fullPropertyId.ContainerName, fullPropertyId.PropValueId);
		}
		else if (activePropVal.PropType == FPropertyValue::PropertyType::Transform && TransformPropBindings.Contains(fullPropertyId))
		{
			for (int i = 0; i < TransformPropBindings[fullPropertyId].Num(); i++)
				(*TransformPropBindings[fullPropertyId][i])(activePropVal.TransformValue, fullPropertyId.ContainerName, fullPropertyId.PropValueId);
		}
	}

	bool SpacePropertyModel::PropValueExists(PropertyId fullPropertyId)
	{
		return CurrLocalPropValues.Contains(fullPropertyId) || CurrServerPropValues.Contains(fullPropertyId);
	}

#pragma region Bind Property
	FCavrnusBinding SpacePropertyModel::BindStringProperty(PropertyId fullPropertyId, const CavrnusStringFunction& callback)
	{
		if (PropValueExists(fullPropertyId))
			callback(GetCurrentPropValue(fullPropertyId).StringValue, fullPropertyId.ContainerName, fullPropertyId.PropValueId);

		using StringFunction = const CavrnusStringFunction;
		TSharedPtr<StringFunction> CallbackPtr = MakeShareable(new StringFunction(callback));

		StringPropBindings.FindOrAdd(fullPropertyId);
		StringPropBindings[fullPropertyId].Add(CallbackPtr);

		return FCavrnusBinding([this, fullPropertyId, CallbackPtr]() {
			StringPropBindings[fullPropertyId].Remove(CallbackPtr);
			if (StringPropBindings[fullPropertyId].IsEmpty())
				StringPropBindings.Remove(fullPropertyId);
		});
	}

	FCavrnusBinding SpacePropertyModel::BindBoolProperty(PropertyId fullPropertyId, const CavrnusBoolFunction& callback)
	{
		if (PropValueExists(fullPropertyId))
			callback(GetCurrentPropValue(fullPropertyId).BoolValue, fullPropertyId.ContainerName, fullPropertyId.PropValueId);

		using BoolFunction = const CavrnusBoolFunction;
		TSharedPtr<BoolFunction> CallbackPtr = MakeShareable(new BoolFunction(callback));

		BoolPropBindings.FindOrAdd(fullPropertyId);
		BoolPropBindings[fullPropertyId].Add(CallbackPtr);

		return FCavrnusBinding([this, fullPropertyId, CallbackPtr]() {
			BoolPropBindings[fullPropertyId].Remove(CallbackPtr);
			if (BoolPropBindings[fullPropertyId].IsEmpty())
				BoolPropBindings.Remove(fullPropertyId);
			});
	}

	FCavrnusBinding SpacePropertyModel::BindFloatProperty(PropertyId fullPropertyId, const CavrnusFloatFunction& callback)
	{
		if (PropValueExists(fullPropertyId))
			callback(GetCurrentPropValue(fullPropertyId).FloatValue, fullPropertyId.ContainerName, fullPropertyId.PropValueId);

		TSharedPtr<CavrnusFloatFunction> CallbackPtr = MakeShareable(new CavrnusFloatFunction(callback));

		FloatPropBindings.FindOrAdd(fullPropertyId);
		FloatPropBindings[fullPropertyId].Add(CallbackPtr);

		return FCavrnusBinding([this, fullPropertyId, CallbackPtr]() {
			FloatPropBindings[fullPropertyId].Remove(CallbackPtr);
			if (FloatPropBindings[fullPropertyId].IsEmpty())
				FloatPropBindings.Remove(fullPropertyId);
		});
	}

	FCavrnusBinding SpacePropertyModel::BindColorProperty(PropertyId fullPropertyId, const CavrnusColorFunction& callback)
	{
		if (PropValueExists(fullPropertyId))
			callback(GetCurrentPropValue(fullPropertyId).ColorValue, fullPropertyId.ContainerName, fullPropertyId.PropValueId);

		TSharedPtr<CavrnusColorFunction> CallbackPtr = MakeShareable(new CavrnusColorFunction(callback));

		ColorPropBindings.FindOrAdd(fullPropertyId);
		ColorPropBindings[fullPropertyId].Add(CallbackPtr);

		return FCavrnusBinding([this, fullPropertyId, CallbackPtr]() {
			ColorPropBindings[fullPropertyId].Remove(CallbackPtr);
			if (ColorPropBindings[fullPropertyId].IsEmpty())
				ColorPropBindings.Remove(fullPropertyId);
			});
	}

	FCavrnusBinding SpacePropertyModel::BindVectorProperty(PropertyId fullPropertyId, const CavrnusVectorFunction& callback)
	{
		if (PropValueExists(fullPropertyId))
			callback(GetCurrentPropValue(fullPropertyId).VectorValue, fullPropertyId.ContainerName, fullPropertyId.PropValueId);

		using VectorFunction = const CavrnusVectorFunction;
		TSharedPtr<VectorFunction> CallbackPtr = MakeShareable(new VectorFunction(callback));

		VectorPropBindings.FindOrAdd(fullPropertyId);
		VectorPropBindings[fullPropertyId].Add(CallbackPtr);

		return FCavrnusBinding([this, fullPropertyId, CallbackPtr]() {
			VectorPropBindings[fullPropertyId].Remove(CallbackPtr);
			if (VectorPropBindings[fullPropertyId].IsEmpty())
				VectorPropBindings.Remove(fullPropertyId);
			});
	}

	FCavrnusBinding SpacePropertyModel::BindTransformProperty(PropertyId fullPropertyId, const CavrnusTransformFunction& callback)
	{
		if (PropValueExists(fullPropertyId))
			callback(GetCurrentPropValue(fullPropertyId).TransformValue, fullPropertyId.ContainerName, fullPropertyId.PropValueId);

		using TransformFunction = const CavrnusTransformFunction;
		TSharedPtr<TransformFunction> CallbackPtr = MakeShareable(new TransformFunction(callback));

		TransformPropBindings.FindOrAdd(fullPropertyId);
		TransformPropBindings[fullPropertyId].Add(CallbackPtr);

		return FCavrnusBinding([this, fullPropertyId, CallbackPtr]() {
			TransformPropBindings[fullPropertyId].Remove(CallbackPtr);
			if (TransformPropBindings[fullPropertyId].IsEmpty())
				TransformPropBindings.Remove(fullPropertyId);
			});
	}

	FCavrnusBinding SpacePropertyModel::BindUserVideoTexture(const FCavrnusUser& User, FCavrnusUserVideoFrameEvent Callback)
	{
		FString UserConnectionId = User.UserConnectionId;

		if (CurrSpaceUsers.Contains(UserConnectionId))
			Callback.ExecuteIfBound(CurrSpaceUsers[UserConnectionId].VideoFrameTexture);

		UserVideoFrameBindings.FindOrAdd(UserConnectionId);
		UserVideoFrameBindings[UserConnectionId].Add(Callback);

		return FCavrnusBinding([this, UserConnectionId, Callback]() { UserVideoFrameBindings[UserConnectionId].Remove(Callback); });
	}
#pragma endregion

#pragma region Get Curr Prop Value
	FString SpacePropertyModel::GetStringPropValue(PropertyId fullPropertyId)
	{
		if (PropValueExists(fullPropertyId))
			return GetCurrentPropValue(fullPropertyId).StringValue;
		return "";
	}

	bool SpacePropertyModel::GetBoolPropValue(PropertyId fullPropertyId)
	{
		if (PropValueExists(fullPropertyId))
			return GetCurrentPropValue(fullPropertyId).BoolValue;
		return false;
	}

	float SpacePropertyModel::GetFloatPropValue(PropertyId fullPropertyId)
	{
		if (PropValueExists(fullPropertyId))
			return GetCurrentPropValue(fullPropertyId).FloatValue;
		return 0.0f;
	}

	FLinearColor SpacePropertyModel::GetColorPropValue(PropertyId fullPropertyId)
	{
		if (PropValueExists(fullPropertyId))
			return GetCurrentPropValue(fullPropertyId).ColorValue;
		return FLinearColor();
	}

	FVector4 SpacePropertyModel::GetVectorPropValue(PropertyId fullPropertyId)
	{
		if (PropValueExists(fullPropertyId))
			return GetCurrentPropValue(fullPropertyId).VectorValue;
		return FVector4();
	}

	FTransform SpacePropertyModel::GetTransformPropValue(PropertyId fullPropertyId)
	{
		if (PropValueExists(fullPropertyId))
			return GetCurrentPropValue(fullPropertyId).TransformValue;
		return FTransform();
	}

	void SpacePropertyModel::AddSpaceUser(FCavrnusUser user)
	{
		if (user.IsLocalUser)
		{
			LocalUser = &user;

			for (int i = 0; i < LocalUserArrivedCallbacks.Num(); i++)
			{
				LocalUserArrivedCallbacks[i].ExecuteIfBound(user);
			}
			LocalUserArrivedCallbacks.Empty();
		}

		CurrSpaceUsers.Add(user.UserConnectionId, user);
		for (int i = 0; i < UserAddedBindings.Num(); i++)
			UserAddedBindings[i].ExecuteIfBound(user);
	}

	void SpacePropertyModel::RemoveSpaceUser(FString userId)
	{
		if (CurrSpaceUsers.Contains(userId))
		{
			FCavrnusUser removedUser = CurrSpaceUsers[userId];
			CurrSpaceUsers.Remove(userId);

			for (int i = 0; i < UserRemovedBindings.Num(); i++)
				UserRemovedBindings[i].ExecuteIfBound(removedUser);
		}
	}

	void SpacePropertyModel::UpdateUserVideoTexture(FString userId, int ResX, int ResY, const TArray<uint8>& ByteArray)
	{
		if (FCavrnusUser* User = CurrSpaceUsers.Find(userId))
		{
			if (!User->VideoFrameTexture || User->VideoFrameTexture->GetSizeX() != ResX || User->VideoFrameTexture->GetSizeY() != ResY)
			{
				FName UniqueName = MakeUniqueObjectName(nullptr, UTexture2D::StaticClass(), "RTCStream");
				User->VideoFrameTexture = UTexture2D::CreateTransient(ResX, ResY, PF_B8G8R8A8, UniqueName);
			}

			void* TextureData = User->VideoFrameTexture->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
			FMemory::Memcpy(TextureData, ByteArray.GetData(), ByteArray.Num());
			User->VideoFrameTexture->GetPlatformData()->Mips[0].BulkData.Unlock();
			User->VideoFrameTexture->UpdateResource();

			if (UserVideoFrameBindings.Contains(userId))
			{
				for (auto& Binding : UserVideoFrameBindings[userId])
				{
					Binding.ExecuteIfBound(User->VideoFrameTexture);
				}
			}
		}
	}

	void SpacePropertyModel::AwaitLocalUser(FCavrnusSpaceUserEvent localUserArrived)
	{
		LocalUserArrivedCallbacks.Add(localUserArrived);
	}

	FCavrnusBinding SpacePropertyModel::BindSpaceUsers(FCavrnusSpaceUserEvent userAdded, FCavrnusSpaceUserEvent userRemoved)
	{
		UserAddedBindings.Add(userAdded);
		UserRemovedBindings.Add(userRemoved);

		for (auto& UserElem : CurrSpaceUsers)
			userAdded.ExecuteIfBound(UserElem.Value);

		return FCavrnusBinding([this, userAdded, userRemoved]()
			{
				UserAddedBindings.Remove(userAdded);
				UserRemovedBindings.Remove(userRemoved);
			});
	}
	
#pragma endregion

}