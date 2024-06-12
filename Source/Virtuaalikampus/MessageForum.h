// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MessageForum.generated.h"

UCLASS()
class VIRTUAALIKAMPUS_API AMessageForum : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMessageForum();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Message Forum")
	FString NewMessage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Message Forum")
	TArray<FString> AllMessages;

	UFUNCTION(BlueprintCallable, Category = "Message Forum")
	void AddMessageToArray(FString Message);

	UFUNCTION(BlueprintCallable, Category = "Message Forum")
	void SaveArrayToFile(TArray<FString> Array);

	UFUNCTION(BlueprintCallable, Category = "Message Forum")
	void LoadArrayFromFile();
};