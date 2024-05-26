// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MassCommonFragments.h"
#include "MassTrafficFragments.h"
#include "MassTrafficProcessorBase.h"
#include "MassTrafficInitInterpolationProcessor.generated.h"


UCLASS()
class MASSTRAFFIC_API UMassTrafficInitInterpolationProcessor : public UMassTrafficProcessorBase
{
	GENERATED_BODY()

public:
	UMassTrafficInitInterpolationProcessor();
	
protected:
	virtual void ConfigureQueries() override;
	virtual void Execute(FMassEntityManager& EntitySubSystem, FMassExecutionContext& Context) override;

	FMassEntityQuery EntityQuery;
};
