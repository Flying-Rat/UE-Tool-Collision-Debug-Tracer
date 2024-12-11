// Copyright 2022 Tadeáš Anděl, All Rights Reserved.

#include "TraceUtility.h"

#include "CollisionDebugTracer.h"

#include "Components/ShapeComponent.h"

bool FTraceUtility::LineTraceSingleByProfile(const UWorld* World, FHitResult& OutHit, const FVector& Start,
                                             const FVector& End, const FName& ProfileName,
                                             const FCollisionQueryParams& Params, bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->LineTraceSingleByProfile(OutHit, Start, End, ProfileName, Params);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		float Duration = CVarDebugDrawTracesDuration.GetValueOnGameThread();
		DrawDebugLine(World, Start, End, FColor::Red, false, Duration, SDPG_World);

		if (bRet)
		{
			DrawDebugPoint(World, OutHit.ImpactPoint, 10.0f, FColor::Green, false, Duration, SDPG_World);
		}
	}
#endif
	return bRet;
}

bool FTraceUtility::LineTraceSingleByChannel(const UWorld* World, FHitResult& OutHit, const FVector& Start,
                                             const FVector& End, ECollisionChannel TraceChannel,
                                             const FCollisionQueryParams& Params,
                                             const FCollisionResponseParams& ResponseParam,
                                             bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->LineTraceSingleByChannel(OutHit, Start, End, TraceChannel, Params, ResponseParam);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		float Duration = CVarDebugDrawTracesDuration.GetValueOnGameThread();
		DrawDebugLine(World, Start, End, FColor::Red, false, Duration, SDPG_World);

		if (bRet)
		{
			DrawDebugPoint(World, OutHit.ImpactPoint, 10.0f, FColor::Green, false, Duration, SDPG_World);
		}
	}
#endif
	return bRet;
}

bool FTraceUtility::LineTraceSingleByObjectType(const UWorld* World, FHitResult& OutHit, const FVector& Start,
                                                const FVector& End,
                                                const FCollisionObjectQueryParams& ObjectQueryParams,
                                                const FCollisionQueryParams& Params, bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->LineTraceSingleByObjectType(OutHit, Start, End, ObjectQueryParams, Params);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		float Duration = CVarDebugDrawTracesDuration.GetValueOnGameThread();
		DrawDebugLine(World, Start, End, FColor::Red, false, Duration, SDPG_World);

		if (bRet)
		{
			DrawDebugPoint(World, OutHit.ImpactPoint, 10.0f, FColor::Green, false, Duration, SDPG_World);
		}
	}
#endif
	return bRet;
}

bool FTraceUtility::LineTraceMultiByProfile(const UWorld* World, TArray<FHitResult>& OutHits, const FVector& Start,
                                            const FVector& End, const FName& ProfileName,
                                            const FCollisionQueryParams& Params, bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->LineTraceMultiByProfile(OutHits, Start, End, ProfileName, Params);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		float Duration = CVarDebugDrawTracesDuration.GetValueOnGameThread();
		DrawDebugLine(World, Start, End, FColor::Red, false, Duration, SDPG_World);
		VisualizeTraceHits(World, OutHits);
	}
#endif
	return bRet;
}

bool FTraceUtility::LineTraceMultiByChannel(const UWorld* World, TArray<FHitResult>& OutHits, const FVector& Start,
                                            const FVector& End, ECollisionChannel TraceChannel,
                                            const FCollisionQueryParams& Params,
                                            const FCollisionResponseParams& ResponseParam,
                                            bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->LineTraceMultiByChannel(OutHits, Start, End, TraceChannel, Params, ResponseParam);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		float Duration = CVarDebugDrawTracesDuration.GetValueOnGameThread();
		DrawDebugLine(World, Start, End, FColor::Red, false, Duration, SDPG_World);
		VisualizeTraceHits(World, OutHits);
	}
#endif
	return bRet;
}

bool FTraceUtility::LineTraceMultiByObjectType(const UWorld* World, TArray<FHitResult>& OutHits, const FVector& Start,
                                               const FVector& End, const FCollisionObjectQueryParams& ObjectQueryParams,
                                               const FCollisionQueryParams& Params, bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->LineTraceMultiByObjectType(OutHits, Start, End, ObjectQueryParams, Params);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		float Duration = CVarDebugDrawTracesDuration.GetValueOnGameThread();
		DrawDebugLine(World, Start, End, FColor::Red, false, Duration, SDPG_World);
		VisualizeTraceHits(World, OutHits);
	}
#endif
	return bRet;
}

bool FTraceUtility::SweepMultiByProfile(const UWorld* World, TArray<FHitResult>& OutHits, const FVector& Start,
                                        const FVector& End, const FQuat& Rot, const FName& ProfileName,
                                        const FCollisionShape& CollisionShape,
                                        const FCollisionQueryParams& Params, bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->SweepMultiByProfile(OutHits, Start, End, Rot, ProfileName, CollisionShape, Params);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		VisualizeShapeTrace(World, Start, End, Rot, CollisionShape);
		VisualizeTraceHits(World, OutHits);
	}
#endif
	return bRet;
}

bool FTraceUtility::SweepMultiByChannel(const UWorld* World, TArray<FHitResult>& OutHits, const FVector& Start,
                                        const FVector& End, const FQuat& Rot, ECollisionChannel TraceChannel,
                                        const FCollisionShape& CollisionShape,
                                        const FCollisionQueryParams& Params,
                                        const FCollisionResponseParams& ResponseParam,
                                        bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->SweepMultiByChannel(OutHits, Start, End, Rot, TraceChannel, CollisionShape, Params,
	                                       ResponseParam);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		VisualizeShapeTrace(World, Start, End, Rot, CollisionShape);
		VisualizeTraceHits(World, OutHits);
	}
#endif
	return bRet;
}

bool FTraceUtility::SweepMultiByObjectType(const UWorld* World, TArray<FHitResult>& OutHits, const FVector& Start,
                                           const FVector& End, const FQuat& Rot,
                                           const FCollisionObjectQueryParams& ObjectQueryParams,
                                           const FCollisionShape& CollisionShape,
                                           const FCollisionQueryParams& Params, bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->SweepMultiByObjectType(OutHits, Start, End, Rot, ObjectQueryParams, CollisionShape, Params);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		VisualizeShapeTrace(World, Start, End, Rot, CollisionShape);
		VisualizeTraceHits(World, OutHits);
	}
#endif
	return bRet;
}

bool FTraceUtility::SweepSingleByProfile(const UWorld* World, FHitResult& OutHit, const FVector& Start,
                                         const FVector& End, const FQuat& Rot, FName ProfileName,
                                         const FCollisionShape& CollisionShape,
                                         const FCollisionQueryParams& Params, bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->SweepSingleByProfile(OutHit, Start, End, Rot, ProfileName, CollisionShape, Params);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		VisualizeShapeTrace(World, Start, End, Rot, CollisionShape);
		if (bRet)
		{
			DrawDebugPoint(World, OutHit.ImpactPoint, 10.0f, FColor::Green, false,
			               CVarDebugDrawTracesDuration.GetValueOnGameThread(), SDPG_World);
		}
	}
#endif
	return bRet;
}

bool FTraceUtility::SweepSingleByChannel(const UWorld* World, FHitResult& OutHit, const FVector& Start,
                                         const FVector& End, const FQuat& Rot, ECollisionChannel TraceChannel,
                                         const FCollisionShape& CollisionShape,
                                         const FCollisionQueryParams& Params,
                                         const FCollisionResponseParams& ResponseParam,
                                         bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->SweepSingleByChannel(OutHit, Start, End, Rot, TraceChannel, CollisionShape, Params,
	                                        ResponseParam);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		VisualizeShapeTrace(World, Start, End, Rot, CollisionShape);
		if (bRet)
		{
			DrawDebugPoint(World, OutHit.ImpactPoint, 10.0f, FColor::Green, false,
			               CVarDebugDrawTracesDuration.GetValueOnGameThread(), SDPG_World);
		}
	}
#endif
	return bRet;
}

bool FTraceUtility::SweepSingleByObjectType(const UWorld* World, FHitResult& OutHit, const FVector& Start,
                                            const FVector& End, const FQuat& Rot,
                                            const FCollisionObjectQueryParams& ObjectQueryParams,
                                            const FCollisionShape& CollisionShape, const FCollisionQueryParams& Params,
                                            bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->SweepSingleByObjectType(OutHit, Start, End, Rot, ObjectQueryParams, CollisionShape, Params);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		VisualizeShapeTrace(World, Start, End, Rot, CollisionShape);
		if (bRet)
		{
			DrawDebugPoint(World, OutHit.ImpactPoint, 10.0f, FColor::Green, false,
			               CVarDebugDrawTracesDuration.GetValueOnGameThread(), SDPG_World);
		}
	}
#endif
	return bRet;
}

bool FTraceUtility::OverlapMultiByProfile(const UWorld* World, TArray<FOverlapResult>& OutOverlaps, const FVector& Pos,
                                          const FQuat& Rot, const FName& ProfileName,
                                          const FCollisionShape& CollisionShape,
                                          const FCollisionQueryParams& Params, bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->OverlapMultiByProfile(OutOverlaps, Pos, Rot, ProfileName, CollisionShape, Params);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		VisualizeShape(World, Pos, Rot, CollisionShape);
		VisualizeOverlapResults(World, Pos, OutOverlaps);
	}
#endif
	return bRet;
}

bool FTraceUtility::OverlapMultiByChannel(const UWorld* World, TArray<FOverlapResult>& OutOverlaps, const FVector& Pos,
                                          const FQuat& Rot, ECollisionChannel TraceChannel,
                                          const FCollisionShape& CollisionShape,
                                          const FCollisionQueryParams& Params,
                                          const FCollisionResponseParams& ResponseParam,
                                          bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->OverlapMultiByChannel(OutOverlaps, Pos, Rot, TraceChannel, CollisionShape, Params,
	                                         ResponseParam);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		VisualizeShape(World, Pos, Rot, CollisionShape);
		VisualizeOverlapResults(World, Pos, OutOverlaps);
	}
#endif
	return bRet;
}

bool FTraceUtility::OverlapMultiByObjectType(const UWorld* World, TArray<FOverlapResult>& OutOverlaps,
                                             const FVector& Pos, const FQuat& Rot,
                                             const FCollisionObjectQueryParams& ObjectQueryParams,
                                             const FCollisionShape& CollisionShape, const FCollisionQueryParams& Params,
                                             bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->OverlapMultiByObjectType(OutOverlaps, Pos, Rot, ObjectQueryParams, CollisionShape, Params);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		VisualizeShape(World, Pos, Rot, CollisionShape);
		VisualizeOverlapResults(World, Pos, OutOverlaps);
	}
#endif
	return bRet;
}

bool FTraceUtility::ComponentOverlapMulti(const UWorld* World, TArray<FOverlapResult>& OutOverlaps,
                                          const UPrimitiveComponent* PrimComp, const FVector& Pos, const FQuat& Rot,
                                          const FComponentQueryParams& Params,
                                          const FCollisionObjectQueryParams& ObjectQueryParams,
                                          bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->ComponentOverlapMulti(OutOverlaps, PrimComp, Pos, Rot, Params, ObjectQueryParams);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		VisualizePrimitiveComponent(World, Pos, Rot, PrimComp);
		VisualizeOverlapResults(World, Pos, OutOverlaps);
	}
#endif
	return bRet;
}

bool FTraceUtility::ComponentOverlapMultiByChannel(const UWorld* World, TArray<FOverlapResult>& OutOverlaps,
                                                   const UPrimitiveComponent* PrimComp, const FVector& Pos,
                                                   const FQuat& Rot, ECollisionChannel TraceChannel,
                                                   const FComponentQueryParams& Params,
                                                   const FCollisionObjectQueryParams& ObjectQueryParams,
                                                   bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->ComponentOverlapMultiByChannel(OutOverlaps, PrimComp, Pos, Rot, TraceChannel, Params,
	                                                  ObjectQueryParams);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		VisualizePrimitiveComponent(World, Pos, Rot, PrimComp);
		VisualizeOverlapResults(World, Pos, OutOverlaps);
	}
#endif
	return bRet;
}

bool FTraceUtility::ComponentSweepMulti(const UWorld* World, TArray<FHitResult>& OutHits, UPrimitiveComponent* PrimComp,
                                        const FVector& Start, const FVector& End, const FQuat& Rot,
                                        const FComponentQueryParams& Params, bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->ComponentSweepMulti(OutHits, PrimComp, Start, End, Rot, Params);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		VisualizePrimitiveComponentTrace(World, Start, End, Rot, PrimComp);
		VisualizeTraceHits(World, OutHits);
	}
#endif
	return bRet;
}

bool FTraceUtility::ComponentSweepMultiByChannel(const UWorld* World, TArray<FHitResult>& OutHits,
                                                 UPrimitiveComponent* PrimComp, const FVector& Start,
                                                 const FVector& End, const FQuat& Rot,
                                                 ECollisionChannel TraceChannel, const FComponentQueryParams& Params,
                                                 bool bAlwaysDebugDraw /*= false*/)
{
	bool bRet = World->ComponentSweepMultiByChannel(OutHits, PrimComp, Start, End, Rot, TraceChannel, Params);
#if !UE_BUILD_SHIPPING
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		VisualizePrimitiveComponentTrace(World, Start, End, Rot, PrimComp);
		VisualizeTraceHits(World, OutHits);
	}
#endif
	return bRet;
}

void FTraceUtility::VisualizeOverlapResults(const UWorld* World, const FVector& Pos,
                                            const TArray<FOverlapResult>& OutOverlaps,
                                            bool bAlwaysDebugDraw /*= false*/)
{
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		const float Duration = CVarDebugDrawTracesDuration.GetValueOnGameThread();
		for (const FOverlapResult& OverlapResult : OutOverlaps)
		{
			DrawDebugLine(World, Pos, OverlapResult.Component->GetComponentLocation(), FColor::Green,
			              false, Duration, SDPG_Foreground);
		}
	}
}

void FTraceUtility::VisualizeTraceHits(const UWorld* World, const TArray<FHitResult>& OutHits,
                                       bool bAlwaysDebugDraw /*= false*/)
{
	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		const float Duration = CVarDebugDrawTracesDuration.GetValueOnGameThread();
		for (const FHitResult& HitResult : OutHits)
		{
			const FColor& Color = HitResult.bBlockingHit ? FColor::Red : FColor::Yellow;
			DrawDebugPoint(World, HitResult.ImpactPoint, 10.0f, Color, false,
			               Duration, SDPG_World);
		}
	}
}

#if !UE_BUILD_SHIPPING
void FTraceUtility::VisualizeShapeTrace(const UWorld* World, const FVector& Start, const FVector& End, const FQuat& Rot,
                                        const FCollisionShape& CollisionShape)
{
	switch (CollisionShape.ShapeType)
	{
		case ECollisionShape::Line:
		{
			DrawDebugLine(World, Start, End, FColor::Red, false, CVarDebugDrawTracesDuration.GetValueOnGameThread(),
			              SDPG_World);
			break;
		}
		case ECollisionShape::Box:
		{
			const FRotator& Rotation = Rot.Rotator();
			const FVector& Extent = CollisionShape.GetExtent();
			float Duration = CVarDebugDrawTracesDuration.GetValueOnGameThread();
			VisualizeShape(World, Start, Rot, CollisionShape);
			DrawDebugBox(World, End, Extent, Rot, FColor::Blue, false, Duration, SDPG_World);

			const FVector& ExtentXOffset = Rotation.RotateVector(FVector::ForwardVector) * Extent.X;
			const FVector& ExtentYOffset = Rotation.RotateVector(FVector::RightVector) * Extent.Y;
			const FVector& ExtentZOffset = Rotation.RotateVector(FVector::UpVector) * Extent.Z;

			DrawDebugLine(World, Start + ExtentXOffset + ExtentYOffset + ExtentZOffset,
			              End + ExtentXOffset + ExtentYOffset + ExtentZOffset, FColor::Purple, false, Duration,
			              SDPG_World);
			DrawDebugLine(World, Start - ExtentXOffset + ExtentYOffset + ExtentZOffset,
			              End - ExtentXOffset + ExtentYOffset + ExtentZOffset, FColor::Purple, false, Duration,
			              SDPG_World);
			DrawDebugLine(World, Start - ExtentXOffset - ExtentYOffset + ExtentZOffset,
			              End - ExtentXOffset - ExtentYOffset + ExtentZOffset, FColor::Purple, false, Duration,
			              SDPG_World);
			DrawDebugLine(World, Start - ExtentXOffset - ExtentYOffset - ExtentZOffset,
			              End - ExtentXOffset - ExtentYOffset - ExtentZOffset, FColor::Purple, false, Duration,
			              SDPG_World);
			DrawDebugLine(World, Start + ExtentXOffset - ExtentYOffset - ExtentZOffset,
			              End + ExtentXOffset - ExtentYOffset - ExtentZOffset, FColor::Purple, false, Duration,
			              SDPG_World);
			DrawDebugLine(World, Start + ExtentXOffset + ExtentYOffset - ExtentZOffset,
			              End + ExtentXOffset + ExtentYOffset - ExtentZOffset, FColor::Purple, false, Duration,
			              SDPG_World);
			DrawDebugLine(World, Start - ExtentXOffset + ExtentYOffset - ExtentZOffset,
			              End - ExtentXOffset + ExtentYOffset - ExtentZOffset, FColor::Purple, false, Duration,
			              SDPG_World);
			DrawDebugLine(World, Start + ExtentXOffset - ExtentYOffset + ExtentZOffset,
			              End + ExtentXOffset - ExtentYOffset + ExtentZOffset, FColor::Purple, false, Duration,
			              SDPG_World);
			break;
		}
		case ECollisionShape::Sphere:
		{
			float Radius = CollisionShape.GetSphereRadius();
			float Duration = CVarDebugDrawTracesDuration.GetValueOnGameThread();
			VisualizeShape(World, Start, Rot, CollisionShape);
			DrawDebugSphere(World, End, Radius, 32, FColor::Blue, false, Duration, SDPG_World);

			const FVector& SphereReachX = FVector::ForwardVector * Radius;
			const FVector& SphereReachY = FVector::RightVector * Radius;
			const FVector& SphereReachZ = FVector::UpVector * Radius;

			DrawDebugLine(World, Start + SphereReachX, End + SphereReachX, FColor::Purple, false, Duration, SDPG_World);
			DrawDebugLine(World, Start + SphereReachY, End + SphereReachY, FColor::Purple, false, Duration, SDPG_World);
			DrawDebugLine(World, Start + SphereReachZ, End + SphereReachZ, FColor::Purple, false, Duration, SDPG_World);
			DrawDebugLine(World, Start - SphereReachX, End - SphereReachX, FColor::Purple, false, Duration, SDPG_World);
			DrawDebugLine(World, Start - SphereReachY, End - SphereReachY, FColor::Purple, false, Duration, SDPG_World);
			DrawDebugLine(World, Start - SphereReachZ, End - SphereReachZ, FColor::Purple, false, Duration, SDPG_World);
			break;
		}
		case ECollisionShape::Capsule:
		{
			const FRotator& Rotation = Rot.Rotator();
			const FVector& X = Rotation.RotateVector(FVector::ForwardVector);
			const FVector& Y = Rotation.RotateVector(FVector::RightVector);
			const FVector& Z = Rotation.RotateVector(FVector::UpVector);

			float Duration = CVarDebugDrawTracesDuration.GetValueOnGameThread();
			float HalfHeight = CollisionShape.GetCapsuleHalfHeight();
			float Radius = CollisionShape.GetCapsuleRadius();
			VisualizeShape(World, Start, Rot, CollisionShape);
			DrawDebugCapsule(World, End, HalfHeight, Radius, Rot, FColor::Blue, false, Duration, SDPG_World);

			const FVector& CapsuleReachX = X * Radius;
			const FVector& CapsuleReachY = Y * Radius;
			const FVector& CapsuleReachZ = Z * HalfHeight;

			DrawDebugLine(World, Start + CapsuleReachZ, End + CapsuleReachZ, FColor::Purple, false, Duration,
			              SDPG_World);
			DrawDebugLine(World, Start - CapsuleReachZ, End - CapsuleReachZ, FColor::Purple, false, Duration,
			              SDPG_World);
			const FVector& HalfCapsuleReachZ = CapsuleReachZ * 0.5f;
			DrawDebugLine(World, Start + HalfCapsuleReachZ + CapsuleReachX, End + HalfCapsuleReachZ + CapsuleReachX,
			              FColor::Purple, false, Duration, SDPG_World);
			DrawDebugLine(World, Start - HalfCapsuleReachZ + CapsuleReachX, End - HalfCapsuleReachZ + CapsuleReachX,
			              FColor::Purple, false, Duration, SDPG_World);
			DrawDebugLine(World, Start + HalfCapsuleReachZ - CapsuleReachX, End + HalfCapsuleReachZ - CapsuleReachX,
			              FColor::Purple, false, Duration, SDPG_World);
			DrawDebugLine(World, Start - HalfCapsuleReachZ - CapsuleReachX, End - HalfCapsuleReachZ - CapsuleReachX,
			              FColor::Purple, false, Duration, SDPG_World);
			DrawDebugLine(World, Start + HalfCapsuleReachZ + CapsuleReachY, End + HalfCapsuleReachZ + CapsuleReachY,
			              FColor::Purple, false, Duration, SDPG_World);
			DrawDebugLine(World, Start - HalfCapsuleReachZ + CapsuleReachY, End - HalfCapsuleReachZ + CapsuleReachY,
			              FColor::Purple, false, Duration, SDPG_World);
			DrawDebugLine(World, Start + HalfCapsuleReachZ - CapsuleReachY, End + HalfCapsuleReachZ - CapsuleReachY,
			              FColor::Purple, false, Duration, SDPG_World);
			DrawDebugLine(World, Start - HalfCapsuleReachZ - CapsuleReachY, End - HalfCapsuleReachZ - CapsuleReachY,
			              FColor::Purple, false, Duration, SDPG_World);
			break;
		}
	}
}

void FTraceUtility::VisualizeShape(const UWorld* World, const FVector& Start, const FQuat& Rot,
                                   const FCollisionShape& CollisionShape)
{
	float Duration = CVarDebugDrawTracesDuration.GetValueOnGameThread();
	switch (CollisionShape.ShapeType)
	{
		case ECollisionShape::Box:
		{
			DrawDebugBox(World, Start, CollisionShape.GetExtent(), Rot, FColor::Red, false, Duration, SDPG_World);
			break;
		}
		case ECollisionShape::Sphere:
		{
			float Radius = CollisionShape.GetSphereRadius();
			DrawDebugSphere(World, Start, Radius, 32, FColor::Red, false, Duration, SDPG_World);
			break;
		}
		case ECollisionShape::Capsule:
		{
			float HalfHeight = CollisionShape.GetCapsuleHalfHeight();
			float Radius = CollisionShape.GetCapsuleRadius();
			DrawDebugCapsule(World, Start, HalfHeight, Radius, Rot, FColor::Red, false, Duration, SDPG_World);
		}
	}
}

void FTraceUtility::VisualizePrimitiveComponent(const UWorld* World, const FVector& Start, const FQuat& Rot,
                                                const UPrimitiveComponent* PrimComp)
{
	float Duration = CVarDebugDrawTracesDuration.GetValueOnGameThread();

	UClass* PrimCompClass = PrimComp->GetClass();
	if (PrimCompClass->IsChildOf<UStaticMeshComponent>())
	{
		const UStaticMeshComponent* StaticMeshComponent = Cast<UStaticMeshComponent>(PrimComp);
		UStaticMesh* StaticMesh = StaticMeshComponent->GetStaticMesh();
		if (!IsValid(StaticMesh))
		{
			return;
		}

		FStaticMeshLODResources& LODModel = StaticMesh->GetRenderData()->LODResources[0];
		FPositionVertexBuffer& VertexBuffer = LODModel.VertexBuffers.PositionVertexBuffer;

		TArray<FVector> Vertices;
		const FTransform& Tranform = StaticMeshComponent->GetComponentTransform();
		for (uint32 Index = 0; Index < VertexBuffer.GetNumVertices(); ++Index)
		{
			Vertices.Add(Tranform.TransformPosition(FVector(VertexBuffer.VertexPosition(Index))));
		}

		FRawStaticIndexBuffer& IndexBuffer = LODModel.IndexBuffer;
		TArray<int32> Indices;
		Indices.Reserve(IndexBuffer.GetNumIndices());
		for (int32 Index = 0; Index < IndexBuffer.GetNumIndices(); ++Index)
		{
			Indices.Add(IndexBuffer.GetIndex(Index));
		}

		DrawDebugMesh(World, Vertices, Indices, FColor::Red, false, Duration, SDPG_World);
	}
	else if (PrimCompClass->IsChildOf<UShapeComponent>())
	{
		const UShapeComponent* ShapeComponent = Cast<UShapeComponent>(PrimComp);
		VisualizeShape(World, Start, Rot, ShapeComponent->GetCollisionShape());
	}
}

void FTraceUtility::VisualizePrimitiveComponentTrace(const UWorld* World, const FVector& Start, const FVector& End,
                                                     const FQuat& Rot,
                                                     UPrimitiveComponent* PrimComp)
{
	float Duration = CVarDebugDrawTracesDuration.GetValueOnGameThread();

	UClass* PrimCompClass = PrimComp->GetClass();
	if (PrimCompClass->IsChildOf<UStaticMeshComponent>())
	{
		const UStaticMeshComponent* StaticMeshComponent = Cast<UStaticMeshComponent>(PrimComp);
		UStaticMesh* StaticMesh = StaticMeshComponent->GetStaticMesh();
		if (!IsValid(StaticMesh))
		{
			return;
		}

		FStaticMeshLODResources& LODModel = StaticMesh->GetRenderData()->LODResources[0];
		FPositionVertexBuffer& VertexBuffer = LODModel.VertexBuffers.PositionVertexBuffer;

		TArray<FVector> StartVertices;
		TArray<FVector> EndVertices;
		const FTransform& Tranform = StaticMeshComponent->GetComponentTransform();
		const FVector& Delta = End - Start;
		for (uint32 Index = 0; Index < VertexBuffer.GetNumVertices(); ++Index)
		{
			const FVector& VertexPosition = Tranform.TransformPosition(
				FVector(VertexBuffer.VertexPosition(Index)));
			StartVertices.Add(VertexPosition);
			EndVertices.Add(VertexPosition + Delta);
		}

		FRawStaticIndexBuffer& IndexBuffer = LODModel.IndexBuffer;
		TArray<int32> Indices;
		Indices.Reserve(IndexBuffer.GetNumIndices());
		for (int32 Index = 0; Index < IndexBuffer.GetNumIndices(); ++Index)
		{
			Indices.Add(IndexBuffer.GetIndex(Index));
		}

		DrawDebugMesh(World, StartVertices, Indices, FColor(202.0f, 0.0f, 255.0f), false, 0.03f, SDPG_Foreground);
		DrawDebugMesh(World, EndVertices, Indices, FColor(82.0f, 0.0f, 105.0f), false, 0.03f, SDPG_Foreground);

		FVector Min;
		FVector Max;
		StaticMeshComponent->GetLocalBounds(Min, Max);
		const FVector& Vertex1 = Tranform.TransformPosition(FVector(Max.X, Min.Y, Max.Z));
		const FVector& Vertex2 = Tranform.TransformPosition(FVector(Min.X, Min.Y, Max.Z));
		const FVector& Vertex3 = Tranform.TransformPosition(FVector(Min.X, Max.Y, Max.Z));
		const FVector& Vertex4 = Tranform.TransformPosition(FVector(Max.X, Max.Y, Max.Z));
		const FVector& Vertex5 = Tranform.TransformPosition(FVector(Max.X, Min.Y, Min.Z));
		const FVector& Vertex6 = Tranform.TransformPosition(FVector(Min.X, Min.Y, Min.Z));
		const FVector& Vertex7 = Tranform.TransformPosition(FVector(Min.X, Max.Y, Min.Z));
		const FVector& Vertex8 = Tranform.TransformPosition(FVector(Max.X, Max.Y, Min.Z));

		const FColor& ConnectionColor = FColor(127.0f, 0.0f, 161.0f);
		DrawDebugLine(World, Vertex1, Vertex1 + Delta, ConnectionColor, false, Duration, SDPG_World);
		DrawDebugLine(World, Vertex2, Vertex2 + Delta, ConnectionColor, false, Duration, SDPG_World);
		DrawDebugLine(World, Vertex3, Vertex3 + Delta, ConnectionColor, false, Duration, SDPG_World);
		DrawDebugLine(World, Vertex4, Vertex4 + Delta, ConnectionColor, false, Duration, SDPG_World);
		DrawDebugLine(World, Vertex5, Vertex5 + Delta, ConnectionColor, false, Duration, SDPG_World);
		DrawDebugLine(World, Vertex6, Vertex6 + Delta, ConnectionColor, false, Duration, SDPG_World);
		DrawDebugLine(World, Vertex7, Vertex7 + Delta, ConnectionColor, false, Duration, SDPG_World);
		DrawDebugLine(World, Vertex8, Vertex8 + Delta, ConnectionColor, false, Duration, SDPG_World);
	}
	else if (PrimCompClass->IsChildOf<UShapeComponent>())
	{
		UShapeComponent* ShapeComponent = Cast<UShapeComponent>(PrimComp);
		VisualizeShapeTrace(World, Start, End, Rot, ShapeComponent->GetCollisionShape());
	}
}
#endif
