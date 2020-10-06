
#include "RWText.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"

bool URWText::SaveArrayText(FString SaveDirectory, FString Filename, TArray<FString> SaveText, bool AllowOverwriting = false)
{
	// Set complete file path
	SaveDirectory += "\\";
	SaveDirectory += Filename;
	if (!AllowOverwriting)
	{
		if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDirectory))
		{
			return false;
		}
	}
	FString FinalString = "";
	for (FString& Each : SaveText)
	{
		FinalString += Each;
		FinalString += LINE_TERMINATOR;
	}
	FFileHelper::SaveStringToFile(FinalString, *SaveDirectory);
	return false;
	//return FFileHelper::SaveStringToFile(FinalString, *SaveDirectory);
}
