// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MassCommonTypes.h"
#include "MassMovementTypes.h"
#include "MassTrafficFragments.h"
#include "MassTrafficProcessorBase.h"
#include "MassTrafficUpdateDistanceToNearestObstacleProcessor.generated.h"

UCLASS()
class MASSTRAFFIC_API UMassTrafficUpdateDistanceToNearestObstacleProcessor : public UMassTrafficProcessorBase
{
	GENERATED_BODY()

public:
	UMassTrafficUpdateDistanceToNearestObstacleProcessor();

protected:
	virtual void ConfigureQueries() override;
	virtual void Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context) override;
	
	FMassEntityQuery EntityQuery_Conditional;
};
