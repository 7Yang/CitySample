// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "HoverDronePawn.h"
#include "Game/ICitySampleTraversalInterface.h"
#include "UI/CitySampleControlsOverlayInterface.h"
#include "Util/ICitySampleInputInterface.h"
#include "CitySampleHoverDrone.generated.h"

UCLASS()
class CITYSAMPLE_API ACitySampleHoverDrone : public AHoverDronePawn,
										     public ICitySampleTraversalInterface,
										     public ICitySampleControlsOverlayInterface,
										     public ICitySampleInputInterface
{
	GENERATED_BODY()

public:
	virtual void PawnClientRestart() override;

	virtual EPlayerTraversalState GetTraversalState_Implementation() const override { return EPlayerTraversalState::Drone; }

protected:
	/** Mapping of pawn relevant InputActions to their string description for the controls overlay UI. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controls Overlay")
	TMap<UInputAction*, FText> InputActionDescriptions;

	/** Mapping of pawn relevant input keys to their string description for the controls overlay UI. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Controls Overlay")
	TMap<FKey, FText> InputKeyDescriptionOverrides;

public:
	/** Returns mapping of pawn relevant InputActions to their string description for the controls overlay UI. */
	virtual TMap<UInputAction*, FText> GetInputActionDescriptions_Implementation() const override { return InputActionDescriptions; }

	/** Returns mapping of pawn relevant input keys to their string description for the controls overlay UI. */
	virtual TMap<FKey, FText> GetInputKeyDescriptionOverrides_Implementation() const override { return InputKeyDescriptionOverrides; }

	virtual void AddInputContext_Implementation(const TScriptInterface<IEnhancedInputSubsystemInterface>& SubsystemInterface) override;
	virtual void RemoveInputContext_Implementation(const TScriptInterface<IEnhancedInputSubsystemInterface>& SubsystemInterface) override;
};