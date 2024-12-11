// Copyright 2022 Tadeáš Anděl, All Rights Reserved.

#pragma once

#include "ComponentVisualizer.h"

struct FStaticMeshTraceVisualizer : FComponentVisualizer
{
public: // Draw

	virtual void DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI) override;
};
