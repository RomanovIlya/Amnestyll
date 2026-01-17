#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FileScanner.generated.h"

/**
 * Класс для сканирования файлов
 */
UCLASS(Blueprintable)
class SUNDERED_API UFileScanner : public UObject
{
    GENERATED_BODY()

public:
    // Конструктор
    UFileScanner();

    // Пример функции для сканирования файлов
    UFUNCTION(BlueprintCallable, Category="File Scanner")
    void ScanFiles(const FString& DirectoryPath);

private:
    // Пример приватного метода
    void ProcessFile(const FString& FilePath);
};
