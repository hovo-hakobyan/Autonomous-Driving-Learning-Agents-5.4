// Fill out your copyright notice in the Description page of Project Settings.


#include "IOSubSystem.h"

bool UIOSubSystem::WriteToCSV(const FString& FileName, const TArray<FString>& ColumnNames,
	const TArray<FCSVRowData>& RowData)
{
	if(RowData.IsEmpty()) return false;

	FString csvContent = ConstructCSVContent(ColumnNames,RowData);
	FString filePath = FPaths::ProjectSavedDir() + FileName + ".csv";

	if(FFileHelper::SaveStringToFile(csvContent,*filePath))
	{
		return true;
	}
	return false;
}

FString UIOSubSystem::ConstructCSVContent(const TArray<FString>& ColumnNames, const TArray<FCSVRowData>& RowData)
{
	FString csvContent = "";

	csvContent += FString::Join(ColumnNames,TEXT(",")) + TEXT("\n");
	for(const FCSVRowData& rowData : RowData)
	{
		csvContent += FString::Printf(TEXT("\"%d\",\"%d\"\n"),rowData.Value1,rowData.Value2);
	}
	
	return csvContent;
}
