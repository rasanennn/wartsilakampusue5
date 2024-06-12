// Fill out your copyright notice in the Description page of Project Settings.

#include "WebBrowserExtended.h"



void UWebBrowserExtended::SetupWebBrowser()
{
	BindBrowserToObject();
}

UWebBrowserBridge* UWebBrowserExtended::BindBrowserToObject()
{
	if(!BridgeObject)
	{
		BridgeObject = NewObject<UWebBrowserBridge>();
		BridgeObject->Rename(*BridgeObjectName);
	}
	WebBrowserWidget->BindUObject(BridgeObjectName, BridgeObject, true);

	return BridgeObject;
}

