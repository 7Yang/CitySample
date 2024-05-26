// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MassProcessor.h"
#include "MassTrafficFragments.h"
#include "MassTrafficProcessorBase.h"
#include "MassTrafficChooseNextLaneProcessor.generated.h"

UCLASS()
class MASSTRAFFIC_API UMassTrafficChooseNextLaneProcessor : public UMassTrafficProcessorBase
{
	GENERATED_BODY()

public:
	UMassTrafficChooseNextLaneProcessor();

protected:
	virtual void ConfigureQueries() override;
	virtual void Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context) override;

	FMassEntityQuery EntityQuery_Conditional;
};
