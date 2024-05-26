// Copyright Epic Games, Inc.All Rights Reserved.

#pragma once

#include "GameFramework/SpectatorPawn.h"
#include "Styling/SlateBrush.h"
#include "Camera/CameraComponent.h"
#include "HoverDronePawnBase.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogHoverDrone, Log, All)

UCLASS(config = Game)
class HOVERDRONE_API AHoverDronePawnBase : public ADefaultPawn
{
	GENERATED_BODY()

public:
	AHoverDronePawnBase(const FObjectInitializer& ObjectInitializer);

	virtual void PossessedBy(AController* NewController) override;
	virtual void UnPossessed() override;
	virtual void TurnAtRate(float Rate) override;
	virtual void LookUpAtRate(float Rate) override;
	virtual void SetupPlayerInputComponent(UInputComponent* InInputComponent) override;
	
	UCameraComponent* GetCameraComponent() { return CameraComponent; }

	/** Can be used by an inherited pawn that requires some sort of loading before being correctly shown. When this method returns true we display a loading screen on replays. */
	virtual bool IsLoading() const { return false; }

protected:
	/** Name of the MovementComponent.  Use this name if you want to use a different class (with ObjectInitializer.SetDefaultSubobjectClass). */
	static const FName CameraComponentName;

	UPROPERTY(Category = Pawn, VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* CameraComponent;

};
