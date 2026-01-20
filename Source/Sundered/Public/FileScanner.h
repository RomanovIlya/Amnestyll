#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FileScanner.generated.h"

USTRUCT(BlueprintType)
struct FScannedFileInfo
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category="File Scanner")
    FString FileName;

    UPROPERTY(BlueprintReadOnly, Category="File Scanner")
    FDateTime CreationDate;
};

UCLASS()
class SUNDERED_API UFileScanner : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category="File Scanner")
    static TArray<FScannedFileInfo> ScanFiles(const FString& DirectoryPath);

private:
    static void ProcessFile(const FString& FilePath, TArray<FScannedFileInfo>& OutFiles);
};

