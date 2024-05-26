// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PointCloud.h"
#include "PointCloudSliceAndDiceRule.h"
#include "PointCloudSliceAndDiceRuleInstance.h"
#include "PointCloudSliceAndDiceRuleData.h"
#include "PointCloudSliceAndDiceRuleFactory.h"
#include "PointCloudAssetHelpers.h"
#include "WorldPartition/DataLayer/ActorDataLayer.h"
#include "Containers/UnrealString.h"

#include "SpawnWorldAudioDataRule.generated.h"

class ISlateStyle;
class UPointCloud;
class AWorldAudioDataClusterActor;
struct FSlateImageBrush;

USTRUCT(BlueprintType)
struct FSpawnWorldAudioDataRuleData : public FPointCloudRuleData
{
	GENERATED_BODY()

public:
	FSpawnWorldAudioDataRuleData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes)
	FString MetaDataKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes)
	FString ReverbKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes)
	FString NamePattern;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes)
	FName FolderPath;

	/** DataLayers the generated actors will belong to.*/
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category = DataLayers)
	TArray<FActorDataLayer> DataLayers;

	virtual UScriptStruct* GetStruct() const override { return StaticStruct(); }
};

UCLASS(BlueprintType, hidecategories = (Object))
class USpawnWorldAudioDataRule : public UPointCloudRule
{
	GENERATED_BODY()

public:
    virtual FString RuleName() const override;
    virtual FString Description() const override;
    virtual bool    Compile(FSliceAndDiceContext& Context) const override;
    virtual RuleType GetType() const override { return RuleType::GENERATOR; }

	/**
	* Make The Name String for the Given Point Cloud By Substituting tokens in the RuleName Template
	* @return A String containing the name of the new actor to create, or empty string on failure
	* @param Pc - A pointer to the point cloud
	* @param InNamePattern - the naming pattern
	* @param InNameValue - the token to replace $IN_VALUE with
	*/
	static FString MakeName(UPointCloud* Pc, const FString& InNamePattern, const FString& InNameValue);

protected:
	USpawnWorldAudioDataRule();
	virtual void ReportParameters(FSliceAndDiceContext& Context)  const override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attributes, meta = (ShowOnlyInnerProperties))
	FSpawnWorldAudioDataRuleData Data;
};

class FSpawnWorldAudioDataRuleInstance : public FPointCloudRuleInstanceWithData<FSpawnWorldAudioDataRuleInstance, FSpawnWorldAudioDataRuleData>
{
public:
	explicit FSpawnWorldAudioDataRuleInstance(const USpawnWorldAudioDataRule* InRule)
		: FPointCloudRuleInstanceWithData(InRule, InRule->Data)
	{
	}

	virtual bool Execute(FSliceAndDiceExecutionContextPtr Context) override;
	virtual bool CanBeExecutedOnAnyThread() const override { return false; }
};

class FSpawnWorldAudioDataFactory : public FSliceAndDiceRuleFactory
{
public:
	FSpawnWorldAudioDataFactory(TSharedPtr<ISlateStyle> Style);
	virtual ~FSpawnWorldAudioDataFactory();

	virtual FString Name() const override;
	virtual FString Description() const override;
	virtual FSlateBrush* GetIcon() const override;
	virtual UPointCloudRule::RuleType GetType() const override { return UPointCloudRule::RuleType::GENERATOR; }

protected:
	virtual UPointCloudRule* Create(UObject* Parent) override;

private:
	FSlateImageBrush* Icon;
};
