// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "WebBrowser.h"
#include "SWebBrowser.h"
#include "WebBrowserBridge.h"
#include "WebBrowserExtended.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUAALIKAMPUS_API UWebBrowserExtended : public UWebBrowser
{
	GENERATED_BODY()

public:
	// Create an instance of the WebBrowserBridge class and bind it to the WebBrowser
	UFUNCTION(BlueprintCallable, meta= (DisplayName = "Setup Browser"), Category = "Web Browser")
	void SetupWebBrowser();

	// Bind the BridgeObject to the web browser
	//UFUNCTION(BlueprintCallable, meta = (DisplayName = "Bind Browser To Object"), Category = "Web Browser")
	UWebBrowserBridge* BindBrowserToObject();

protected:

	UPROPERTY(BlueprintReadOnly)
	UWebBrowserBridge* BridgeObject;

private:

	const FString BridgeObjectName = TEXT("bridge");
};