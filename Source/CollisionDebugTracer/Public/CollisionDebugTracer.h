// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Modules/ModuleManager.h"

static TAutoConsoleVariable<bool> CVarDebugDrawTraces(TEXT("cdt.DebugDrawTraces"), false, TEXT("visualizes all collision traces"));
static TAutoConsoleVariable<float> CVarDebugDrawTracesDuration(TEXT("cdt.DebugDrawTracesDuration"), 0.5f, TEXT("How long in seconds visualized traces remain"));

class FCollisionDebugTracerModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
