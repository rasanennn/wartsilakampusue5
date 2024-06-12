// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageForum.h"
#include "Misc/FileHelper.h"

// Sets default values
AMessageForum::AMessageForum()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMessageForum::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMessageForum::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMessageForum::AddMessageToArray(FString Message)
{
	AllMessages.Add(Message); // Add latest message to array
}

void AMessageForum::SaveArrayToFile(TArray<FString> Array)
{
	// Get path for textfile in which messages are saved
	FString FilePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir() + TEXT("SavedMessages.txt"));

	FString FileContents;
	for (const FString& Message : Array)
	{
		// Add line switch after every message
		FileContents += Message + TEXT("\n");
	}

	// Save message to text file
	if (FFileHelper::SaveStringToFile(FileContents, *FilePath))
	{
		UE_LOG(LogTemp, Warning, TEXT("Array contents saved to file: %s"), *FilePath);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to save array contents to file!"));
	}
}

void AMessageForum::LoadArrayFromFile()
{
	// Get textfile in which messages are saved
	FString Filepath = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir() + TEXT("SavedMessages.txt"));

	FString FileContents;
	if (FFileHelper::LoadFileToString(FileContents, *Filepath))
	{
		AllMessages.Empty(); // Clear existing array

		TArray<FString> Lines;
		FileContents.ParseIntoArrayLines(Lines);

		// Load messages from file
		for (const FString& Line : Lines)
		{
			AllMessages.Add(Line);
		}

		UE_LOG(LogTemp, Warning, TEXT("Array contents loaded from file %s"), *Filepath);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load array contents from file!"));
	}
}