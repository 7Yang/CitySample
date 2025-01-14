﻿// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Subsystems/GameInstanceSubsystem.h"
#include "HoverDroneVolumeManager.generated.h"

UCLASS()
class HOVERDRONE_API UHoverDroneVolumeManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	const TSet<class ABlockingVolume*>& GetBlockingVolumes() const { return BlockingVolumes; }

	const TSet<class AHoverDroneSpeedLimitBox*>& GetSpeedLimitBoxes() const { return SpeedLimitBoxes; }

private:
	void OnLevelRemovedFromWorld(class ULevel* Level, class UWorld* World);
	void OnLevelAddedToWorld(class ULevel* Level, class UWorld* World);
	void PostGarbageCollect();

	UPROPERTY(Transient)
	TSet<class AHoverDroneSpeedLimitBox*> SpeedLimitBoxes;

	UPROPERTY(Transient)
	TSet<class ABlockingVolume*> BlockingVolumes;

	FDelegateHandle OnLevelRemovedFromWorldHandle;
	FDelegateHandle OnLevelAddedToWorldHandle;
	FDelegateHandle PostGarbageCollectHandle;
};