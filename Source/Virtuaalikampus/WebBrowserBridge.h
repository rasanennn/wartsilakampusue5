// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"

#include "WebBrowserBridge.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMessageSent, const FString, Message);
UCLASS()
class VIRTUAALIKAMPUS_API UWebBrowserBridge : public UObject
{
	GENERATED_BODY()

public:
	//On the Javascript side, all object and function names are all lowercase. Example:
	//This function is called via javascript with the line window.ue.bridge.handlebuttonclick();
	UFUNCTION(BlueprintCallable, Category = "Web Browser")
	void HandleButtonClick(const FString& Message);


private:

	UPROPERTY(BlueprintAssignable, Category = "Web Browser")
	FOnMessageSent OnMessageSent;
};