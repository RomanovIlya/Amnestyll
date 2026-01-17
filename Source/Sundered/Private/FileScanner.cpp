#include "FileScanner.h"
#include "Misc/Paths.h"
#include "HAL/FileManager.h"

UFileScanner::UFileScanner()
{
    // Конструктор можно использовать для инициализации
}

void UFileScanner::ScanFiles(const FString& DirectoryPath)
{
    if (!FPaths::DirectoryExists(DirectoryPath))
    {
        UE_LOG(LogTemp, Warning, TEXT("Directory does not exist: %s"), *DirectoryPath);
        return;
    }

    // Получаем все файлы в директории
    TArray<FString> FoundFiles;
    IFileManager::Get().FindFilesRecursive(FoundFiles, *DirectoryPath, TEXT("*.*"), true, false);

    for (const FString& File : FoundFiles)
    {
        ProcessFile(File);
    }
}

void UFileScanner::ProcessFile(const FString& FilePath)
{
    // Пример обработки файла
    UE_LOG(LogTemp, Log, TEXT("Found file: %s"), *FilePath);
}

