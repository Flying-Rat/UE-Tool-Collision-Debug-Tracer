// Copyright 2022 Tadeáš Anděl, All Rights Reserved.

#include "Visualizers/CollisionTraceVisualizer.h"

#include "TraceUtility.h"

#include "Actors/Components/CollisionTraceDummy.h"

void FCollisionTraceVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View,
                                                  FPrimitiveDrawInterface* PDI)
{
	UWorld* World = Component->GetWorld();
	if (!IsValid(World))
	{
		return;
	}

	const UCollisionTraceDummy* CollisionTraceDummy = Cast<UCollisionTraceDummy>(Component);
	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActor(CollisionTraceDummy->GetOwner());
	const FVector& Start = CollisionTraceDummy->GetComponentLocation();
	const FVector& End = Start + CollisionTraceDummy->GetForwardVector() * CollisionTraceDummy->TraceLength;

	switch (CollisionTraceDummy->CollisionShape)
	{
		case ECollisionTraceShape::Line:
			VisualizeLineTrace(World, PDI, CollisionTraceDummy, Start, End, CollisionQueryParams);
			break;
		case ECollisionTraceShape::Box:
			VisualizeBoxTrace(World, PDI, CollisionTraceDummy, Start, End, CollisionQueryParams);
			break;
		case ECollisionTraceShape::Sphere:
			VisualizeSphereTrace(World, PDI, CollisionTraceDummy, Start, End, CollisionQueryParams);
			break;
		case ECollisionTraceShape::Capsule:
			VisualizeCapsuleTrace(World, PDI, CollisionTraceDummy, Start, End, CollisionQueryParams);
			break;
	}
}

void FCollisionTraceVisualizer::VisualizeLineTrace(UWorld* World, FPrimitiveDrawInterface* PDI,
                                                   const UCollisionTraceDummy* CollisionTraceDummy,
                                                   const FVector& Start, const FVector& End,
                                                   const FCollisionQueryParams& CollisionQueryParams)
{
	PDI->DrawLine(Start, End, FLinearColor::Red, SDPG_World);
	switch (CollisionTraceDummy->TraceType)
	{
		case ETraceType::SweepSingle:
		{
			FHitResult HitResult;

			switch (CollisionTraceDummy->QueryType)
			{
				case EQueryType::CollisionProfile:
				{
					World->LineTraceSingleByProfile(HitResult, Start, End, CollisionTraceDummy->CollisionProfile,
					                                CollisionQueryParams);
					break;
				}
				case EQueryType::TraceChannel:
				{
					World->LineTraceSingleByChannel(HitResult, Start, End, CollisionTraceDummy->TraceChannel,
					                                CollisionQueryParams);
					break;
				}
				case EQueryType::ObjectType:
				{
					World->LineTraceSingleByObjectType(HitResult, Start, End,
					                                   FCollisionObjectQueryParams(CollisionTraceDummy->ObjectTypes),
					                                   CollisionQueryParams);
					break;
				}
			}

			if (!HitResult.HasValidHitObjectHandle())
			{
				return;
			}

			PDI->DrawPoint(HitResult.ImpactPoint, FLinearColor::Green, 10.0f, SDPG_Foreground);
			break;
		}
		case ETraceType::SweepMulti:
		{
			TArray<FHitResult> HitResults;

			switch (CollisionTraceDummy->QueryType)
			{
				case EQueryType::CollisionProfile:
				{
					World->LineTraceMultiByProfile(HitResults, Start, End, CollisionTraceDummy->CollisionProfile,
					                               CollisionQueryParams);
					break;
				}
				case EQueryType::TraceChannel:
				{
					World->LineTraceMultiByChannel(HitResults, Start, End, CollisionTraceDummy->TraceChannel,
					                               CollisionQueryParams);
					break;
				}
				case EQueryType::ObjectType:
				{
					World->LineTraceMultiByObjectType(HitResults, Start, End,
					                                  FCollisionObjectQueryParams(CollisionTraceDummy->ObjectTypes),
					                                  CollisionQueryParams);
					break;
				}
			}

			FTraceUtility::VisualizeTraceHits(World, HitResults);
			break;
		}
		case ETraceType::Overlap:
		{
			// No overlapping for line trace
		}
	}
}

void FCollisionTraceVisualizer::VisualizeBoxTrace(UWorld* World, FPrimitiveDrawInterface* PDI,
                                                  const UCollisionTraceDummy* CollisionTraceDummy, const FVector& Start,
                                                  const FVector& End,
                                                  const FCollisionQueryParams& CollisionQueryParams)
{
	const FRotator& Rotation = CollisionTraceDummy->GetComponentRotation() + CollisionTraceDummy->RotationOffset;
	const FMatrix& BoxToWorldStart = FTransform(
		Rotation, Start).ToMatrixNoScale();
	DrawWireBox(PDI, BoxToWorldStart, FBox(-CollisionTraceDummy->BoxHalfExtent, CollisionTraceDummy->BoxHalfExtent),
	            FLinearColor::Red,
	            SDPG_World);

	if (CollisionTraceDummy->TraceLength > 0.0f && CollisionTraceDummy->TraceType != ETraceType::Overlap)
	{
		const FMatrix& BoxToWorldEnd = FTransform(
			Rotation, End).ToMatrixNoScale();
		DrawWireBox(PDI, BoxToWorldEnd, FBox(-CollisionTraceDummy->BoxHalfExtent, CollisionTraceDummy->BoxHalfExtent),
		            FLinearColor::Blue,
		            SDPG_World);

		const FVector& ExtentXOffset = Rotation.RotateVector(FVector::ForwardVector) * CollisionTraceDummy->
			BoxHalfExtent.X;
		const FVector& ExtentYOffset = Rotation.RotateVector(FVector::RightVector) * CollisionTraceDummy->BoxHalfExtent.
			Y;
		const FVector& ExtentZOffset = Rotation.RotateVector(FVector::UpVector) * CollisionTraceDummy->BoxHalfExtent.Z;

		const FLinearColor& Purple = FLinearColor(1.0f, 0.0f, 1.0f);
		PDI->DrawLine(Start + ExtentXOffset + ExtentYOffset + ExtentZOffset,
		              End + ExtentXOffset + ExtentYOffset + ExtentZOffset, Purple, SDPG_World);
		PDI->DrawLine(Start - ExtentXOffset + ExtentYOffset + ExtentZOffset,
		              End - ExtentXOffset + ExtentYOffset + ExtentZOffset, Purple, SDPG_World);
		PDI->DrawLine(Start - ExtentXOffset - ExtentYOffset + ExtentZOffset,
		              End - ExtentXOffset - ExtentYOffset + ExtentZOffset, Purple, SDPG_World);
		PDI->DrawLine(Start - ExtentXOffset - ExtentYOffset - ExtentZOffset,
		              End - ExtentXOffset - ExtentYOffset - ExtentZOffset, Purple, SDPG_World);
		PDI->DrawLine(Start + ExtentXOffset - ExtentYOffset - ExtentZOffset,
		              End + ExtentXOffset - ExtentYOffset - ExtentZOffset, Purple, SDPG_World);
		PDI->DrawLine(Start + ExtentXOffset + ExtentYOffset - ExtentZOffset,
		              End + ExtentXOffset + ExtentYOffset - ExtentZOffset, Purple, SDPG_World);
		PDI->DrawLine(Start - ExtentXOffset + ExtentYOffset - ExtentZOffset,
		              End - ExtentXOffset + ExtentYOffset - ExtentZOffset, Purple, SDPG_World);
		PDI->DrawLine(Start + ExtentXOffset - ExtentYOffset + ExtentZOffset,
		              End + ExtentXOffset - ExtentYOffset + ExtentZOffset, Purple, SDPG_World);
	}

	VisualizeShapeTrace(World, PDI, CollisionTraceDummy, Start, End, CollisionQueryParams,
	                    FCollisionShape::MakeBox(CollisionTraceDummy->BoxHalfExtent));
}

void FCollisionTraceVisualizer::VisualizeCapsuleTrace(UWorld* World, FPrimitiveDrawInterface* PDI,
                                                      const UCollisionTraceDummy* CollisionTraceDummy,
                                                      const FVector& Start, const FVector& End,
                                                      const FCollisionQueryParams& CollisionQueryParams)
{
	const FRotator& Rotation = CollisionTraceDummy->GetComponentRotation() + CollisionTraceDummy->RotationOffset;
	const FVector& X = Rotation.RotateVector(FVector::ForwardVector);
	const FVector& Y = Rotation.RotateVector(FVector::RightVector);
	const FVector& Z = Rotation.RotateVector(FVector::UpVector);

	DrawWireCapsule(PDI, Start, X, Y, Z, FLinearColor::Red, CollisionTraceDummy->Radius,
	                CollisionTraceDummy->CapsuleHalfHeight, 12, SDPG_World);

	if (CollisionTraceDummy->TraceLength > 0.0f && CollisionTraceDummy->TraceType != ETraceType::Overlap)
	{
		DrawWireCapsule(PDI, End, X, Y, Z, FLinearColor::Blue, CollisionTraceDummy->Radius,
		                CollisionTraceDummy->CapsuleHalfHeight, 12, SDPG_World);

		const FVector& CapsuleReachX = X * CollisionTraceDummy->Radius;
		const FVector& CapsuleReachY = Y * CollisionTraceDummy->Radius;
		const FVector& CapsuleReachZ = Z * CollisionTraceDummy->CapsuleHalfHeight;

		const FLinearColor& Purple = FLinearColor(1.0f, 0.0f, 1.0f);
		PDI->DrawLine(Start + CapsuleReachZ, End + CapsuleReachZ, Purple, SDPG_World);
		PDI->DrawLine(Start - CapsuleReachZ, End - CapsuleReachZ, Purple, SDPG_World);
		const FVector& HalfCapsuleReachZ = CapsuleReachZ * 0.5f;
		PDI->DrawLine(Start + HalfCapsuleReachZ + CapsuleReachX, End + HalfCapsuleReachZ + CapsuleReachX, Purple,
		              SDPG_World);
		PDI->DrawLine(Start - HalfCapsuleReachZ + CapsuleReachX, End - HalfCapsuleReachZ + CapsuleReachX, Purple,
		              SDPG_World);
		PDI->DrawLine(Start + HalfCapsuleReachZ - CapsuleReachX, End + HalfCapsuleReachZ - CapsuleReachX, Purple,
		              SDPG_World);
		PDI->DrawLine(Start - HalfCapsuleReachZ - CapsuleReachX, End - HalfCapsuleReachZ - CapsuleReachX, Purple,
		              SDPG_World);
		PDI->DrawLine(Start + HalfCapsuleReachZ + CapsuleReachY, End + HalfCapsuleReachZ + CapsuleReachY, Purple,
		              SDPG_World);
		PDI->DrawLine(Start - HalfCapsuleReachZ + CapsuleReachY, End - HalfCapsuleReachZ + CapsuleReachY, Purple,
		              SDPG_World);
		PDI->DrawLine(Start + HalfCapsuleReachZ - CapsuleReachY, End + HalfCapsuleReachZ - CapsuleReachY, Purple,
		              SDPG_World);
		PDI->DrawLine(Start - HalfCapsuleReachZ - CapsuleReachY, End - HalfCapsuleReachZ - CapsuleReachY, Purple,
		              SDPG_World);
	}

	VisualizeShapeTrace(World, PDI, CollisionTraceDummy, Start, End, CollisionQueryParams,
	                    FCollisionShape::MakeCapsule(CollisionTraceDummy->Radius,
	                                                 CollisionTraceDummy->CapsuleHalfHeight));
}

void FCollisionTraceVisualizer::VisualizeSphereTrace(UWorld* World, FPrimitiveDrawInterface* PDI,
                                                     const UCollisionTraceDummy* CollisionTraceDummy,
                                                     const FVector& Start, const FVector& End,
                                                     const FCollisionQueryParams& CollisionQueryParams)
{
	DrawWireSphere(PDI, Start, FLinearColor::Red, CollisionTraceDummy->Radius, 32, SDPG_World);

	if (CollisionTraceDummy->TraceLength > 0.0f && CollisionTraceDummy->TraceType != ETraceType::Overlap)
	{
		DrawWireSphere(PDI, End, FLinearColor::Blue, CollisionTraceDummy->Radius, 32, SDPG_World);

		const FVector& SphereReachX = FVector::ForwardVector * CollisionTraceDummy->Radius;
		const FVector& SphereReachY = FVector::RightVector * CollisionTraceDummy->Radius;
		const FVector& SphereReachZ = FVector::UpVector * CollisionTraceDummy->Radius;

		const FLinearColor& Purple = FLinearColor(1.0f, 0.0f, 1.0f);
		PDI->DrawLine(Start + SphereReachX, End + SphereReachX, Purple, SDPG_World);
		PDI->DrawLine(Start + SphereReachY, End + SphereReachY, Purple, SDPG_World);
		PDI->DrawLine(Start + SphereReachZ, End + SphereReachZ, Purple, SDPG_World);
		PDI->DrawLine(Start - SphereReachX, End - SphereReachX, Purple, SDPG_World);
		PDI->DrawLine(Start - SphereReachY, End - SphereReachY, Purple, SDPG_World);
		PDI->DrawLine(Start - SphereReachZ, End - SphereReachZ, Purple, SDPG_World);
	}

	VisualizeShapeTrace(World, PDI, CollisionTraceDummy, Start, End, CollisionQueryParams,
	                    FCollisionShape::MakeSphere(CollisionTraceDummy->Radius));
}

void FCollisionTraceVisualizer::VisualizeShapeTrace(UWorld* World, FPrimitiveDrawInterface* PDI,
                                                    const UCollisionTraceDummy* CollisionTraceDummy,
                                                    const FVector& Start, const FVector& End,
                                                    const FCollisionQueryParams& CollisionQueryParams,
                                                    const FCollisionShape& CollisionShape)
{
	const FQuat& Rotation = (CollisionTraceDummy->GetComponentRotation() + CollisionTraceDummy->RotationOffset).
		Quaternion();
	switch (CollisionTraceDummy->TraceType)
	{
		case ETraceType::SweepSingle:
		{
			FHitResult HitResult;

			switch (CollisionTraceDummy->QueryType)
			{
				case EQueryType::CollisionProfile:
				{
					World->SweepSingleByProfile(HitResult, Start, End, Rotation,
					                            CollisionTraceDummy->CollisionProfile,
					                            CollisionShape,
					                            CollisionQueryParams);
					break;
				}
				case EQueryType::TraceChannel:
				{
					World->SweepSingleByChannel(HitResult, Start, End, Rotation,
					                            CollisionTraceDummy->TraceChannel,
					                            CollisionShape,
					                            CollisionQueryParams);
					break;
				}
				case EQueryType::ObjectType:
				{
					World->SweepSingleByObjectType(HitResult, Start, End, Rotation,
					                               FCollisionObjectQueryParams(CollisionTraceDummy->ObjectTypes),
					                               CollisionShape,
					                               CollisionQueryParams);
					break;
				}
			}

			if (!HitResult.HasValidHitObjectHandle())
			{
				return;
			}

			PDI->DrawPoint(HitResult.ImpactPoint, FLinearColor::Green, 10.0f, SDPG_Foreground);
			break;
		}
		case ETraceType::SweepMulti:
		{
			TArray<FHitResult> HitResults;

			switch (CollisionTraceDummy->QueryType)
			{
				case EQueryType::CollisionProfile:
				{
					World->SweepMultiByProfile(HitResults, Start, End, Rotation,
					                           CollisionTraceDummy->CollisionProfile,
					                           CollisionShape,
					                           CollisionQueryParams);
					break;
				}
				case EQueryType::TraceChannel:
				{
					World->SweepMultiByChannel(HitResults, Start, End, Rotation,
					                           CollisionTraceDummy->TraceChannel,
					                           CollisionShape,
					                           CollisionQueryParams);
					break;
				}
				case EQueryType::ObjectType:
				{
					World->SweepMultiByObjectType(HitResults, Start, End, Rotation,
					                              FCollisionObjectQueryParams(CollisionTraceDummy->ObjectTypes),
					                              CollisionShape,
					                              CollisionQueryParams);
					break;
				}
			}

			FTraceUtility::VisualizeTraceHits(World, HitResults);
			break;
		}
		case ETraceType::Overlap:
		{
			TArray<FOverlapResult> OverlapResults;
			switch (CollisionTraceDummy->QueryType)
			{
				case EQueryType::CollisionProfile:
				{
					World->OverlapMultiByProfile(OverlapResults, Start, Rotation,
					                             CollisionTraceDummy->CollisionProfile, CollisionShape
					);
					break;
				}
				case EQueryType::TraceChannel:
				{
					World->OverlapMultiByChannel(OverlapResults, Start, Rotation,
					                             CollisionTraceDummy->TraceChannel,
					                             CollisionShape);
					break;
				}
				case EQueryType::ObjectType:
				{
					World->OverlapMultiByObjectType(OverlapResults, Start, Rotation,
					                                FCollisionObjectQueryParams(CollisionTraceDummy->ObjectTypes),
					                                CollisionShape);
					break;
				}
			}

			FTraceUtility::VisualizeOverlapResults(World, Start, OverlapResults);
			break;
		}
	}
}
