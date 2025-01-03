// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "IOSubSystem.generated.h"

/**
 * 
 */
 
USTRUCT(BlueprintType)
struct GRADWORKPROJECT_API FCSVRowData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category = "CSV")
	int32 Value1;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category = "CSV")
	int32 Value2;
};

UCLASS()
class GRADWORKPROJECT_API UIOSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "IOSubSystem")
	bool WriteToCSV(const FString& FileName,const TArray<FString>& ColumnNames, const TArray<FCSVRowData>& RowData );

private:
	FString ConstructCSVContent(const TArray<FString>& ColumnNames, const TArray<FCSVRowData>& RowData);
	
};
