// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Templates/SharedPointer.h"
#include "Styling/SlateStyle.h"

class FSliceAndDiceRuleFactory;

class FWorldAudioDataSystemEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	TSharedPtr<ISlateStyle> Style;

	TArray<FSliceAndDiceRuleFactory*> RuleFactories;
};
