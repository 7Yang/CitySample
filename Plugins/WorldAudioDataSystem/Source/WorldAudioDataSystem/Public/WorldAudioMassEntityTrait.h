// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MassEntityTypes.h"
#include "MassEntityTraitBase.h"

#include "WorldAudioMassEntityTrait.generated.h"

USTRUCT()
struct WORLDAUDIODATASYSTEM_API FWorldAudioDataAudioControllerParameters : public FMassSharedFragment
{
	GENERATED_BODY()

	/** The audio controller to use for individualised audio */
	FName AudioController;
};

UCLASS(meta=(DisplayName="World Audio Data"))
class WORLDAUDIODATASYSTEM_API UWorldAudioDataMassEntityTrait : public UMassEntityTraitBase
{
	GENERATED_BODY()

public:
	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, const UWorld& World) const override;

public:
	/** The audio controller to use for individualised audio */
	UPROPERTY(EditAnywhere, Category = "World Audio Data")
	FName                   AudioController;
};
