// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WebBrowserBridge.h"

void UWebBrowserBridge::HandleButtonClick(const FString& Message)
{
	// Handle the button click event here
	// You can access the message passed from the web page
	UE_LOG(LogTemp, Warning, TEXT("Received message from web page: %s"), *Message);

	OnMessageSent.Broadcast(*Message);
}