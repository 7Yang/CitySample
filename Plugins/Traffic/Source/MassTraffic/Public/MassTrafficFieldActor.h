// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "MassTrafficFieldComponent.h"

#include "MassTrafficFieldActor.generated.h"

UCLASS()
class MASSTRAFFIC_API AMassTrafficFieldActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMassTrafficFieldActor();

	UMassTrafficFieldComponent* GetFieldComponent() const { return FieldComponent; } 

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMassTrafficFieldComponent*   FieldComponent;
};
