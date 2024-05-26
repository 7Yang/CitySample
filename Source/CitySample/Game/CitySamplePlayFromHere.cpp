// Copyright Epic Games, Inc. All Rights Reserved.
#include "CitySamplePlayFromHere.h"
#include "WorldPartition/DataLayer/WorldDataLayers.h"
#include "Engine/World.h"

ACitySamplePlayFromHere::ACitySamplePlayFromHere(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
#if WITH_EDITORONLY_DATA
	bCanPlayFromHere                   = true;
	bIsSpatiallyLoaded                 = false;
	RootComponent->bVisualizeComponent = true;
#endif
}

#if WITH_EDITOR
void ACitySamplePlayFromHere::OnPlayFromHere()
{
	Super::OnPlayFromHere();

	if (bOverrideActiveDataLayers || bOverrideLoadedDataLayers)
	{
		if (AWorldDataLayers* WorldDataLayers = GetWorld()->GetWorldDataLayers())
		{
			WorldDataLayers->OverwriteDataLayerRuntimeStates(bOverrideActiveDataLayers ? &ActiveDataLayers : nullptr, bOverrideLoadedDataLayers ? &LoadedDataLayers : nullptr);
		}
	}

	TGuardValue<bool> AutoRestore(GAllowActorScriptExecutionInEditor, true);
	PlayFromHereEvent();
}
#endif