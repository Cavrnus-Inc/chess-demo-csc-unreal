#pragma once

#include "CoreMinimal.h"
#include "PDFImporter.h"

typedef int (*CreateAPIInstance)(void** Instance, void* CallerHandle);
typedef void (*DeleteAPIInstance)(void* Instance);
typedef int (*InitAPI)(void* Instance, int Argc, char** Argv);
typedef int (*ExitAPI)(void* Instance);

DECLARE_DELEGATE_OneParam(FOnPDFConverted, class UPDF*);

class PDFIMPORTER_API FGhostscriptCore
{
private:
	// Ghostscript module
	void* GhostscriptModule;

	// Ghostscript function pointers
	CreateAPIInstance CreateInstance;
	DeleteAPIInstance DeleteInstance;
	InitAPI Init;
	ExitAPI Exit;

	TSharedPtr<class IImageWrapper> ImageWrapper;

public:
	FString PagesDirectoryPath;

public:
	// Convert PDF to PDF asset
	void ConvertPdfToPdfAssetRequest(FOnPDFConverted Callback, const FString& InputPath, int Dpi, int FirstPage, int LastPage, bool bIsImportIntoEditor = false);

private:
	// Convert PDF to multiple jpeg images using Ghostscript API
	void ConvertPdfToJpeg(FOnPDFConverted Callback, const FString& InputPath, int Dpi, int FirstPage, int LastPage);

	void ConvertingFinished(FOnPDFConverted Callback, const FString& TempDirPath, int Dpi, int FirstPage, int LastPage);
	// Create UTexture2D from image files in directory
	bool LoadTexture2DFromFile(const FString& FilePath, class UTexture2D*& LoadedTexture);

#if WITH_EDITORONLY_DATA
	// Create texture asset from image files in directory
	bool CreateTextureAssetFromFile(const FString& FilePath, class UTexture2D*& LoadedTexture);
#endif

	//
	TArray<char> FStringToCharPtr(const FString& Text);

	// Get the size of FString data
	int GetFStringSize(const FString& Text);

private:
	// Only PDFImporterModule can create instances
	friend FPDFImporterModule;

	void* GhostscriptInstance = nullptr;
	FGhostscriptCore();

public:
	// Destructor is open because it is managed by TSharedPtr
	~FGhostscriptCore();
};
