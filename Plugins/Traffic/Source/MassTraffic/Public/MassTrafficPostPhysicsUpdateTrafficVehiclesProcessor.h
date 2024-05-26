// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MassTrafficFragments.h"
#include "MassTrafficProcessorBase.h"
#include "MassTrafficPostPhysicsUpdateTrafficVehiclesProcessor.generated.h"


UCLASS()
class MASSTRAFFIC_API UMassTrafficPostPhysicsUpdateTrafficVehiclesProcessor : public UMassTrafficProcessorBase
{
	GENERATED_BODY()

public:
	UMassTrafficPostPhysicsUpdateTrafficVehiclesProcessor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void ConfigureQueries() override;
	virtual void Execute(FMassEntityManager& EntitySubSystem, FMassExecutionContext& Context) override;

	FMassEntityQuery PIDControlTrafficVehicleQuery;
};
