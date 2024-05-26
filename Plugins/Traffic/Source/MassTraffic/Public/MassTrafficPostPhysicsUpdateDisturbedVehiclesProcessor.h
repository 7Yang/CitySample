// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MassTrafficFragments.h"
#include "MassTrafficProcessorBase.h"
#include "MassTrafficPostPhysicsUpdateDisturbedVehiclesProcessor.generated.h"

UCLASS()
class MASSTRAFFIC_API UMassTrafficPostPhysicsUpdateDisturbedVehiclesProcessor : public UMassTrafficProcessorBase
{
	GENERATED_BODY()

public:
	UMassTrafficPostPhysicsUpdateDisturbedVehiclesProcessor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
protected:
	virtual void ConfigureQueries() override;
	virtual void Execute(FMassEntityManager& EntitySubSystem, FMassExecutionContext& Context) override;

	FMassEntityQuery DisturbedVehicleQuery;
};
