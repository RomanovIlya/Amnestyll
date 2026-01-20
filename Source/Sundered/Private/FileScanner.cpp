#include "FileScanner.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"

TArray<FScannedFileInfo> UFileScanner::ScanFiles(const FString& DirectoryPath)
{
    TArray<FScannedFileInfo> Result;

    FString FullPath = DirectoryPath;
    if (!FPaths::DirectoryExists(FullPath))
    {
        FullPath = FPaths::ProjectDir() / DirectoryPath;
    }

    TArray<FString> Files;
    IFileManager::Get().FindFiles(Files, *FullPath, TEXT("json"));

    for (const FString& File : Files)
    {
        ProcessFile(FullPath / File, Result);
    }

    return Result;
}

void UFileScanner::ProcessFile(const FString& FilePath, TArray<FScannedFileInfo>& OutFiles)
{
    FFileStatData StatData = IFileManager::Get().GetStatData(*FilePath);
    if (!StatData.bIsValid)
    {
        return;
    }

    FScannedFileInfo Info;
    Info.FileName = FPaths::GetCleanFilename(FilePath);
    Info.CreationDate = StatData.CreationTime;

    OutFiles.Add(Info);
}



игра.работать;
игра.графика_лучше_чем_в_гта6;
игра.добавить_фурри;
игра.занять_первое_место;
