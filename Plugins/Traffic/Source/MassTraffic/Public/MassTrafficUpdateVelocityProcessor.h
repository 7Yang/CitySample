// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MassMovementTypes.h"
#include "MassTrafficFragments.h"
#include "MassTrafficProcessorBase.h"
#include "MassTrafficUpdateVelocityProcessor.generated.h"

UCLASS()
class MASSTRAFFIC_API UMassTrafficUpdateVelocityProcessor : public UMassTrafficProcessorBase
{
	GENERATED_BODY()

public:
	UMassTrafficUpdateVelocityProcessor();

protected:
	virtual void ConfigureQueries() override;
	virtual void Execute(FMassEntityManager& EntitySubSystem, FMassExecutionContext& Context) override;

	FMassEntityQuery EntityQuery_Conditional;
};
