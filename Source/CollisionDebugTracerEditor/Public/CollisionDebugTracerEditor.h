// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Editor/UnrealEd/Public/ComponentVisualizer.h"

#include "Modules/ModuleManager.h"

class FCollisionDebugTracerEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private: // Component visualizers

	void RegisterComponentVisualizer(const FName& ComponentClassName, TSharedPtr<FComponentVisualizer> Visualizer);

private: // Component visualizers
    
	TArray<FName> RegisteredComponentClassNames;
};
