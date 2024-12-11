// Copyright Epic Games, Inc. All Rights Reserved.

#include "CollisionDebugTracerEditor.h"

#include "UnrealEdGlobals.h"

#include "Actors/Components/CollisionTraceDummy.h"
#include "Actors/Components/StaticMeshTraceDummyComponent.h"

#include "Editor/UnrealEdEngine.h"

#include "Visualizers/CollisionTraceVisualizer.h"
#include "Visualizers/StaticMeshVisualizer.h"

#define LOCTEXT_NAMESPACE "FCollisionDebugTracerEditorModule"

void FCollisionDebugTracerEditorModule::StartupModule()
{
	RegisterComponentVisualizer(UCollisionTraceDummy::StaticClass()->GetFName(), MakeShareable(new FCollisionTraceVisualizer()));
	RegisterComponentVisualizer(UStaticMeshTraceDummyComponent::StaticClass()->GetFName(), MakeShareable(new FStaticMeshTraceVisualizer()));
}

void FCollisionDebugTracerEditorModule::ShutdownModule()
{
	if (GUnrealEd != NULL)
	{
		for (const FName& RegisteredComponentClassName : RegisteredComponentClassNames)
		{
			GUnrealEd->UnregisterComponentVisualizer(RegisteredComponentClassName);
		}
	}
}

void FCollisionDebugTracerEditorModule::RegisterComponentVisualizer(const FName& ComponentClassName, TSharedPtr<FComponentVisualizer> Visualizer)
{
	if (GUnrealEd != NULL)
	{
		GUnrealEd->RegisterComponentVisualizer(ComponentClassName, Visualizer);
	}

	RegisteredComponentClassNames.Add(ComponentClassName);

	if (Visualizer.IsValid())
	{
		Visualizer->OnRegister();
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FCollisionDebugTracerEditorModule, CollisionDebugTracerEditor)