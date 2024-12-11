// Copyright 2022 Tadeáš Anděl, All Rights Reserved.

#pragma once

#include "ComponentVisualizer.h"

class UCollisionTraceDummy;

struct FCollisionTraceVisualizer : FComponentVisualizer
{
public: // Draw

	virtual void DrawVisualization(const UActorComponent* Component, const FSceneView* View,
	                               FPrimitiveDrawInterface* PDI) override;

private: // Shapes

	void VisualizeLineTrace(UWorld* World, FPrimitiveDrawInterface* PDI,
	                        const UCollisionTraceDummy* CollisionTraceDummy, const FVector& Start, const FVector& End,
	                          const FCollisionQueryParams& CollisionQueryParams);

	void VisualizeBoxTrace(UWorld* World, FPrimitiveDrawInterface* PDI,
	                       const UCollisionTraceDummy* CollisionTraceDummy, const FVector& Start, const FVector& End,
	                          const FCollisionQueryParams& CollisionQueryParams);

	void VisualizeCapsuleTrace(UWorld* World, FPrimitiveDrawInterface* PDI,
	                           const UCollisionTraceDummy* CollisionTraceDummy, const FVector& Start, const FVector& End,
	                          const FCollisionQueryParams& CollisionQueryParams);

	void VisualizeSphereTrace(UWorld* World, FPrimitiveDrawInterface* PDI,
	                          const UCollisionTraceDummy* CollisionTraceDummy, const FVector& Start, const FVector& End,
	                          const FCollisionQueryParams& CollisionQueryParams);

	void VisualizeShapeTrace(UWorld* World, FPrimitiveDrawInterface* PDI,
							  const UCollisionTraceDummy* CollisionTraceDummy, const FVector& Start, const FVector& End,
							  const FCollisionQueryParams& CollisionQueryParams, const FCollisionShape& CollisionShape);
};
