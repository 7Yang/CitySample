// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Animation/AnimInstance.h"
#include "Animation/AnimSequence.h"
#include "MassTrafficEvaluateSequenceAnimInstance.generated.h"

/**
 * Simple anim instance with a few parameters to be used as inputs when driving it from UAnimToTextureBPLibrary::AnimationToTexture()
 */
UCLASS()
class MASSTRAFFIC_API UEvaluateSequenceAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UEvaluateSequenceAnimInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	UPROPERTY(Transient, EditAnywhere, Category = Default, BlueprintReadOnly)
	TObjectPtr<UAnimSequence> SequenceToEvaluate = nullptr;

	UPROPERTY(Transient, EditAnywhere, Category = Default, BlueprintReadOnly)
	float TimeToEvaluate = 0.0f;
};

