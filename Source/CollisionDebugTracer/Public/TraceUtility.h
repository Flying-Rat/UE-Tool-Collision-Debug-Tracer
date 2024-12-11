// Copyright 2022 Tadeáš Anděl, All Rights Reserved.

#pragma once

struct COLLISIONDEBUGTRACER_API FTraceUtility
{
	bool static LineTraceSingleByProfile(const UWorld* World, FHitResult& OutHit, const FVector& Start,
	                                     const FVector& End, const FName& ProfileName,
	                                     const FCollisionQueryParams& Params =
		                                     FCollisionQueryParams::DefaultQueryParam, bool bAlwaysDebugDraw = false);

	bool static LineTraceSingleByChannel(const UWorld* World, FHitResult& OutHit, const FVector& Start,
	                                     const FVector& End,
	                                     ECollisionChannel TraceChannel,
	                                     const FCollisionQueryParams& Params = FCollisionQueryParams::DefaultQueryParam,
	                                     const FCollisionResponseParams& ResponseParam =
		                                     FCollisionResponseParams::DefaultResponseParam, bool bAlwaysDebugDraw = false);

	bool static LineTraceSingleByObjectType(const UWorld* World, FHitResult& OutHit, const FVector& Start,
	                                        const FVector& End, const FCollisionObjectQueryParams& ObjectQueryParams,
	                                        const FCollisionQueryParams& Params =
		                                        FCollisionQueryParams::DefaultQueryParam, bool bAlwaysDebugDraw = false);

	bool static LineTraceMultiByProfile(const UWorld* World, TArray<FHitResult>& OutHits, const FVector& Start,
	                                    const FVector& End, const FName& ProfileName,
	                                    const FCollisionQueryParams& Params = FCollisionQueryParams::DefaultQueryParam, bool bAlwaysDebugDraw = false);

	bool static LineTraceMultiByChannel(const UWorld* World, TArray<FHitResult>& OutHits, const FVector& Start,
	                                    const FVector& End, ECollisionChannel TraceChannel,
	                                    const FCollisionQueryParams& Params = FCollisionQueryParams::DefaultQueryParam,
	                                    const FCollisionResponseParams& ResponseParam =
		                                    FCollisionResponseParams::DefaultResponseParam, bool bAlwaysDebugDraw = false);

	bool static LineTraceMultiByObjectType(const UWorld* World, TArray<FHitResult>& OutHits, const FVector& Start,
	                                       const FVector& End, const FCollisionObjectQueryParams& ObjectQueryParams,
	                                       const FCollisionQueryParams& Params =
		                                       FCollisionQueryParams::DefaultQueryParam, bool bAlwaysDebugDraw = false);

	bool static SweepMultiByProfile(const UWorld* World, TArray<FHitResult>& OutHits, const FVector& Start,
	                                const FVector& End,
	                                const FQuat& Rot, const FName& ProfileName, const FCollisionShape& CollisionShape,
	                                const FCollisionQueryParams& Params = FCollisionQueryParams::DefaultQueryParam, bool bAlwaysDebugDraw = false);

	bool static SweepMultiByChannel(const UWorld* World, TArray<FHitResult>& OutHits, const FVector& Start,
	                                const FVector& End, const FQuat& Rot, ECollisionChannel TraceChannel,
	                                const FCollisionShape& CollisionShape,
	                                const FCollisionQueryParams& Params = FCollisionQueryParams::DefaultQueryParam,
	                                const FCollisionResponseParams& ResponseParam =
		                                FCollisionResponseParams::DefaultResponseParam, bool bAlwaysDebugDraw = false);

	bool static SweepMultiByObjectType(const UWorld* World, TArray<FHitResult>& OutHits,
	                                   const FVector& Start, const FVector& End, const FQuat& Rot,
	                                   const FCollisionObjectQueryParams& ObjectQueryParams,
	                                   const FCollisionShape& CollisionShape,
	                                   const FCollisionQueryParams& Params =
		                                   FCollisionQueryParams::DefaultQueryParam, bool bAlwaysDebugDraw = false);

	bool static SweepSingleByProfile(const UWorld* World, FHitResult& OutHit, const FVector& Start, const FVector& End,
	                                 const FQuat& Rot, FName ProfileName, const FCollisionShape& CollisionShape,
	                                 const FCollisionQueryParams& Params = FCollisionQueryParams::DefaultQueryParam, bool bAlwaysDebugDraw = false);

	bool static SweepSingleByChannel(const UWorld* World, FHitResult& OutHit, const FVector& Start, const FVector& End,
	                                 const FQuat& Rot, ECollisionChannel TraceChannel,
	                                 const FCollisionShape& CollisionShape,
	                                 const FCollisionQueryParams& Params = FCollisionQueryParams::DefaultQueryParam,
	                                 const FCollisionResponseParams& ResponseParam =
		                                 FCollisionResponseParams::DefaultResponseParam, bool bAlwaysDebugDraw = false);

	bool static SweepSingleByObjectType(const UWorld* World, FHitResult& OutHit, const FVector& Start,
	                                    const FVector& End, const FQuat& Rot,
	                                    const FCollisionObjectQueryParams& ObjectQueryParams,
	                                    const FCollisionShape& CollisionShape,
	                                    const FCollisionQueryParams& Params = FCollisionQueryParams::DefaultQueryParam, bool bAlwaysDebugDraw = false);

	bool static OverlapMultiByProfile(const UWorld* World, TArray<FOverlapResult>& OutOverlaps, const FVector& Pos,
	                                  const FQuat& Rot, const FName& ProfileName, const FCollisionShape& CollisionShape,
	                                  const FCollisionQueryParams& Params = FCollisionQueryParams::DefaultQueryParam, bool bAlwaysDebugDraw = false);

	bool static OverlapMultiByChannel(const UWorld* World, TArray<FOverlapResult>& OutOverlaps, const FVector& Pos,
	                                  const FQuat& Rot, ECollisionChannel TraceChannel,
	                                  const FCollisionShape& CollisionShape,
	                                  const FCollisionQueryParams& Params = FCollisionQueryParams::DefaultQueryParam,
	                                  const FCollisionResponseParams& ResponseParam =
		                                  FCollisionResponseParams::DefaultResponseParam, bool bAlwaysDebugDraw = false);

	bool static OverlapMultiByObjectType(const UWorld* World, TArray<FOverlapResult>& OutOverlaps, const FVector& Pos,
	                                     const FQuat& Rot, const FCollisionObjectQueryParams& ObjectQueryParams,
	                                     const FCollisionShape& CollisionShape,
	                                     const FCollisionQueryParams& Params =
		                                     FCollisionQueryParams::DefaultQueryParam, bool bAlwaysDebugDraw = false);

	bool static ComponentOverlapMulti(const UWorld* World, TArray<FOverlapResult>& OutOverlaps,
	                                  const UPrimitiveComponent* PrimComp, const FVector& Pos, const FQuat& Rot,
	                                  const FComponentQueryParams& Params =
		                                  FComponentQueryParams::DefaultComponentQueryParams,
	                                  const FCollisionObjectQueryParams& ObjectQueryParams =
		                                  FCollisionObjectQueryParams::DefaultObjectQueryParam, bool bAlwaysDebugDraw = false);

	bool static ComponentOverlapMultiByChannel(const UWorld* World, TArray<FOverlapResult>& OutOverlaps,
	                                           const UPrimitiveComponent* PrimComp, const FVector& Pos,
	                                           const FQuat& Rot, ECollisionChannel TraceChannel,
	                                           const FComponentQueryParams& Params =
		                                           FComponentQueryParams::DefaultComponentQueryParams,
	                                           const FCollisionObjectQueryParams& ObjectQueryParams =
		                                           FCollisionObjectQueryParams::DefaultObjectQueryParam, bool bAlwaysDebugDraw = false);

	bool static ComponentSweepMulti(const UWorld* World, TArray<FHitResult>& OutHits, UPrimitiveComponent* PrimComp,
	                                const FVector& Start, const FVector& End, const FQuat& Rot,
	                                const FComponentQueryParams& Params, bool bAlwaysDebugDraw = false);

	bool static ComponentSweepMultiByChannel(const UWorld* World, TArray<FHitResult>& OutHits,
	                                         UPrimitiveComponent* PrimComp, const FVector& Start, const FVector& End,
	                                         const FQuat& Rot, ECollisionChannel TraceChannel,
	                                         const FComponentQueryParams& Params, bool bAlwaysDebugDraw = false);

public: // Hits visualizing

	static void VisualizeOverlapResults(const UWorld* World, const FVector& Pos, const TArray<FOverlapResult>& OutOverlaps, bool bAlwaysDebugDraw = false);

	static void VisualizeTraceHits(const UWorld* World, const TArray<FHitResult>& OutHits, bool bAlwaysDebugDraw = false);

public: // Editor only

#if !UE_BUILD_SHIPPING
	static void VisualizeShapeTrace(const UWorld* World, const FVector& Start, const FVector& End, const FQuat& Rot,
	                                const FCollisionShape& CollisionShape);

	static void VisualizeShape(const UWorld* World, const FVector& Start, const FQuat& Rot,
	                           const FCollisionShape& CollisionShape);

	static void VisualizePrimitiveComponent(const UWorld* World, const FVector& Start, const FQuat& Rot,
	                                        const UPrimitiveComponent* PrimComp);

	static void VisualizePrimitiveComponentTrace(const UWorld* World, const FVector& Start, const FVector& End,
	                                             const FQuat& Rot,
	                                             UPrimitiveComponent* PrimComp);
#endif
};
