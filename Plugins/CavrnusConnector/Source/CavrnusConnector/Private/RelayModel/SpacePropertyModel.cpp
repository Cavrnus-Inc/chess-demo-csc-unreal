#include "SpacePropertyModel.h"

namespace Cavrnus
{

	SpacePropertyModel::SpacePropertyModel()
	{
	}

	SpacePropertyModel::~SpacePropertyModel()
	{

	}

#pragma region Update Curr Prop Value
	void SpacePropertyModel::UpdateStringPropVal(FString fullPropertyId, FString value)
	{
		bool exists = CurrStringPropValues.Contains(fullPropertyId);
		CurrStringPropValues.FindOrAdd(fullPropertyId);

		bool changed = !CurrStringPropValues[fullPropertyId].Equals(value);
		CurrStringPropValues[fullPropertyId] = value;

		if (StringPropBindings.Contains(fullPropertyId) && (!exists || changed))
		{
			for (int i = 0; i < StringPropBindings[fullPropertyId].Num(); i++)
				StringPropBindings[fullPropertyId][i].ExecuteIfBound(value, GetContainerName(fullPropertyId), GetPropertyName(fullPropertyId));
		}
	}

	void SpacePropertyModel::UpdateBoolPropVal(FString fullPropertyId, bool value)
	{
		bool exists = CurrBoolPropValues.Contains(fullPropertyId);
		CurrBoolPropValues.FindOrAdd(fullPropertyId);

		bool changed = !CurrBoolPropValues[fullPropertyId] == value;
		CurrBoolPropValues[fullPropertyId] = value;

		if (BoolPropBindings.Contains(fullPropertyId) && (!exists || changed))
		{
			for (int i = 0; i < BoolPropBindings[fullPropertyId].Num(); i++)
				BoolPropBindings[fullPropertyId][i].ExecuteIfBound(value, GetContainerName(fullPropertyId), GetPropertyName(fullPropertyId));
		}
	}

	void SpacePropertyModel::UpdateFloatPropVal(FString fullPropertyId, float value)
	{
		bool exists = CurrFloatPropValues.Contains(fullPropertyId);
		CurrFloatPropValues.FindOrAdd(fullPropertyId);

		bool changed = !FMath::IsNearlyEqual(CurrFloatPropValues[fullPropertyId], value, .0001f);
		CurrFloatPropValues[fullPropertyId] = value;

		if (FloatPropBindings.Contains(fullPropertyId) && (!exists || changed))
		{
			for (int i = 0; i < FloatPropBindings[fullPropertyId].Num(); i++)
				FloatPropBindings[fullPropertyId][i].ExecuteIfBound(value, GetContainerName(fullPropertyId), GetPropertyName(fullPropertyId));
		}
	}

	void SpacePropertyModel::UpdateColorPropVal(FString fullPropertyId, FLinearColor value)
	{
		bool exists = CurrColorPropValues.Contains(fullPropertyId);
		CurrColorPropValues.FindOrAdd(fullPropertyId);
		bool changed = !CurrColorPropValues[fullPropertyId].Equals(value);
		CurrColorPropValues[fullPropertyId] = value;

		if (ColorPropBindings.Contains(fullPropertyId) && (!exists || changed))
		{
			for (int i = 0; i < ColorPropBindings[fullPropertyId].Num(); i++)
				ColorPropBindings[fullPropertyId][i].ExecuteIfBound(value, GetContainerName(fullPropertyId), GetPropertyName(fullPropertyId));
		}
	}

	void SpacePropertyModel::UpdateVectorPropVal(FString fullPropertyId, FVector4 value)
	{
		bool exists = CurrVectorPropValues.Contains(fullPropertyId);
		CurrVectorPropValues.FindOrAdd(fullPropertyId);

		bool changed = !CurrVectorPropValues[fullPropertyId].Equals(value, .0001f);
		CurrVectorPropValues[fullPropertyId] = value;

		if (VectorPropBindings.Contains(fullPropertyId) && (!exists || changed))
		{
			for (int i = 0; i < VectorPropBindings[fullPropertyId].Num(); i++)
				VectorPropBindings[fullPropertyId][i].ExecuteIfBound(value, GetContainerName(fullPropertyId), GetPropertyName(fullPropertyId));
		}
	}

	void SpacePropertyModel::UpdateTransformPropVal(FString fullPropertyId, FTransform value)
	{
		bool exists = CurrTransformPropValues.Contains(fullPropertyId);
		CurrTransformPropValues.FindOrAdd(fullPropertyId);

		bool changed = !CurrTransformPropValues[fullPropertyId].Equals(value, .0001f);
		CurrTransformPropValues[fullPropertyId] = value;

		if (TransformPropBindings.Contains(fullPropertyId) && (!exists || changed))
		{
			for (int i = 0; i < TransformPropBindings[fullPropertyId].Num(); i++)
				TransformPropBindings[fullPropertyId][i].ExecuteIfBound(value, GetContainerName(fullPropertyId), GetPropertyName(fullPropertyId));
		}
	}
#pragma endregion

#pragma region Bind Property
	FCavrnusBinding SpacePropertyModel::BindStringProperty(FString fullPropertyId, FStringPropertyUpdated callback)
	{
		if (CurrStringPropValues.Contains(fullPropertyId))
			callback.ExecuteIfBound(CurrStringPropValues[fullPropertyId], GetContainerName(fullPropertyId), GetPropertyName(fullPropertyId));

		StringPropBindings.FindOrAdd(fullPropertyId);
		StringPropBindings[fullPropertyId].Add(callback);

		return FCavrnusBinding([this, fullPropertyId, callback]() {
			StringPropBindings[fullPropertyId].Remove(callback);
			if (StringPropBindings[fullPropertyId].IsEmpty())
				StringPropBindings.Remove(fullPropertyId);
		});
	}

	FCavrnusBinding SpacePropertyModel::BindBoolProperty(FString fullPropertyId, FBoolPropertyUpdated callback)
	{
		if (CurrBoolPropValues.Contains(fullPropertyId))
			callback.ExecuteIfBound(CurrBoolPropValues[fullPropertyId], GetContainerName(fullPropertyId), GetPropertyName(fullPropertyId));

		BoolPropBindings.FindOrAdd(fullPropertyId);
		BoolPropBindings[fullPropertyId].Add(callback);

		return FCavrnusBinding([this, fullPropertyId, callback]() {
			BoolPropBindings[fullPropertyId].Remove(callback);
			if (BoolPropBindings[fullPropertyId].IsEmpty())
				BoolPropBindings.Remove(fullPropertyId);
			});
	}

	FCavrnusBinding SpacePropertyModel::BindFloatProperty(FString fullPropertyId, FFloatPropertyUpdated callback)
	{
		if (CurrFloatPropValues.Contains(fullPropertyId))
			callback.ExecuteIfBound(CurrFloatPropValues[fullPropertyId], GetContainerName(fullPropertyId), GetPropertyName(fullPropertyId));

		FloatPropBindings.FindOrAdd(fullPropertyId);
		FloatPropBindings[fullPropertyId].Add(callback);

		return FCavrnusBinding([this, fullPropertyId, callback]() { 
			FloatPropBindings[fullPropertyId].Remove(callback);
			if (FloatPropBindings[fullPropertyId].IsEmpty())
				FloatPropBindings.Remove(fullPropertyId);
		});
	}

	FCavrnusBinding SpacePropertyModel::BindColorProperty(FString fullPropertyId, FColorPropertyUpdated callback)
	{
		if (CurrColorPropValues.Contains(fullPropertyId))
			callback.ExecuteIfBound(CurrColorPropValues[fullPropertyId], GetContainerName(fullPropertyId), GetPropertyName(fullPropertyId));

		ColorPropBindings.FindOrAdd(fullPropertyId);
		ColorPropBindings[fullPropertyId].Add(callback);

		return FCavrnusBinding([this, fullPropertyId, callback]() { 
			ColorPropBindings[fullPropertyId].Remove(callback);
			if (ColorPropBindings[fullPropertyId].IsEmpty())
				ColorPropBindings.Remove(fullPropertyId);
			});
	}

	FCavrnusBinding SpacePropertyModel::BindVectorProperty(FString fullPropertyId, FVectorPropertyUpdated callback)
	{
		if (CurrVectorPropValues.Contains(fullPropertyId))
			callback.ExecuteIfBound(CurrVectorPropValues[fullPropertyId], GetContainerName(fullPropertyId), GetPropertyName(fullPropertyId));

		VectorPropBindings.FindOrAdd(fullPropertyId);
		VectorPropBindings[fullPropertyId].Add(callback);

		return FCavrnusBinding([this, fullPropertyId, callback]() {
			VectorPropBindings[fullPropertyId].Remove(callback);
			if (VectorPropBindings[fullPropertyId].IsEmpty())
				VectorPropBindings.Remove(fullPropertyId);
			});
	}

	FCavrnusBinding SpacePropertyModel::BindTransformProperty(FString fullPropertyId, FTransformPropertyUpdated callback)
	{
		if (CurrTransformPropValues.Contains(fullPropertyId))
			callback.ExecuteIfBound(CurrTransformPropValues[fullPropertyId], GetContainerName(fullPropertyId), GetPropertyName(fullPropertyId));

		TransformPropBindings.FindOrAdd(fullPropertyId);
		TransformPropBindings[fullPropertyId].Add(callback);

		return FCavrnusBinding([this, fullPropertyId, callback]() {
			TransformPropBindings[fullPropertyId].Remove(callback);
			if (TransformPropBindings[fullPropertyId].IsEmpty())
				TransformPropBindings.Remove(fullPropertyId);
			});
	}

	FCavrnusBinding SpacePropertyModel::BindUserVideoTexture(FCavrnusUser& User, FCavrnusUserVideoFrameEvent Callback)
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
	FString SpacePropertyModel::GetStringPropValue(FString fullPropertyId)
	{
		if (CurrStringPropValues.Contains(fullPropertyId))
			return CurrStringPropValues[fullPropertyId];
		return "";
	}

	bool SpacePropertyModel::GetBoolPropValue(FString fullPropertyId)
	{
		if (CurrBoolPropValues.Contains(fullPropertyId))
			return CurrBoolPropValues[fullPropertyId];
		return false;
	}

	float SpacePropertyModel::GetFloatPropValue(FString fullPropertyId)
	{
		if (CurrFloatPropValues.Contains(fullPropertyId))
			return CurrFloatPropValues[fullPropertyId];
		return 0.0f;
	}

	FLinearColor SpacePropertyModel::GetColorPropValue(FString fullPropertyId)
	{
		if (CurrColorPropValues.Contains(fullPropertyId))
			return CurrColorPropValues[fullPropertyId];
		return FLinearColor();
	}

	FVector4 SpacePropertyModel::GetVectorPropValue(FString fullPropertyId)
	{
		if (CurrVectorPropValues.Contains(fullPropertyId))
			return CurrVectorPropValues[fullPropertyId];
		return FVector4();
	}

	FTransform SpacePropertyModel::GetTransformPropValue(FString fullPropertyId)
	{
		if (CurrTransformPropValues.Contains(fullPropertyId))
			return CurrTransformPropValues[fullPropertyId];
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