// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Toolkits/IToolkitHost.h"
#include "AssetTypeActions_Base.h"

class FAssetTypeActions_WADVehAudioPreset : public FAssetTypeActions_Base
{
public:
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_WADVehAudioPreset", "WAD Vehicle Audio Preset"); }
	virtual FColor GetTypeColor() const override { return FColor(229, 49, 232); }
	virtual uint32 GetCategories() override { return EAssetTypeCategories::Sounds; }
	virtual UClass* GetSupportedClass() const override;
	virtual const TArray<FText>& GetSubMenus() const override;
};
