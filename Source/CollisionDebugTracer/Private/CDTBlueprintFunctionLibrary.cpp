// Copyright 2022 Tadeáš Anděl, All Rights Reserved.

#include "CDTBlueprintFunctionLibrary.h"

#include "CollisionDebugTracer.h"
#include "TraceUtility.h"

bool UCDTBlueprintFunctionLibrary::LineTraceSingleByProfile(const UObject* WorldContextObject, FHitResult& OutHit,
                                                            const FVector& Start, const FVector& End,
                                                            const FName& ProfileName,
                                                            const TArray<AActor*>& ActorsToIgnore,
                                                            bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::LineTraceSingleByProfile(World, OutHit, Start, End, ProfileName, CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::LineTraceSingleByChannel(const UObject* WorldContextObject, FHitResult& OutHit,
                                                            const FVector& Start, const FVector& End,
                                                            ECollisionChannel TraceChannel,
                                                            const TArray<AActor*>& ActorsToIgnore,
                                                            bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::LineTraceSingleByChannel(World, OutHit, Start, End, TraceChannel, CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::LineTraceSingleByObjectType(const UObject* WorldContextObject, FHitResult& OutHit,
                                                               const FVector& Start, const FVector& End,
                                                               const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes,
                                                               const TArray<AActor*>& ActorsToIgnore,
                                                               bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::LineTraceSingleByObjectType(World, OutHit, Start, End, ObjectTypes,
	                                                  CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::LineTraceMultiByProfile(const UObject* WorldContextObject,
                                                           TArray<FHitResult>& OutHits,
                                                           const FVector& Start, const FVector& End,
                                                           const FName& ProfileName,
                                                           const TArray<AActor*>& ActorsToIgnore,
                                                           bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::LineTraceMultiByProfile(World, OutHits, Start, End, ProfileName, CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::LineTraceMultiByChannel(const UObject* WorldContextObject,
                                                           TArray<FHitResult>& OutHits,
                                                           const FVector& Start,
                                                           const FVector& End, ECollisionChannel TraceChannel,
                                                           const TArray<AActor*>& ActorsToIgnore,
                                                           bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::LineTraceMultiByChannel(World, OutHits, Start, End, TraceChannel, CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::LineTraceMultiByObjectType(const UObject* WorldContextObject,
                                                              TArray<FHitResult>& OutHits,
                                                              const FVector& Start, const FVector& End,
                                                              const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes,
                                                              const TArray<AActor*>& ActorsToIgnore,
                                                              bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::LineTraceMultiByObjectType(World, OutHits, Start, End, ObjectTypes, CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::SphereTraceMultiByProfile(const UObject* WorldContextObject,
                                                             TArray<FHitResult>& OutHits, const FVector& Start,
                                                             const FVector& End, float Radius, const FName& ProfileName,
                                                             const TArray<AActor*>& ActorsToIgnore,
                                                             bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::SweepMultiByProfile(World, OutHits, Start, End, FQuat::Identity, ProfileName,
	                                          FCollisionShape::MakeSphere(Radius), CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::SphereTraceMultiByChannel(const UObject* WorldContextObject,
                                                             TArray<FHitResult>& OutHits, const FVector& Start,
                                                             const FVector& End, float Radius,
                                                             ECollisionChannel TraceChannel,
                                                             const TArray<AActor*>& ActorsToIgnore,
                                                             bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::SweepMultiByChannel(World, OutHits, Start, End, FQuat::Identity, TraceChannel,
	                                          FCollisionShape::MakeSphere(Radius), CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::SphereTraceMultiByObjectType(const UObject* WorldContextObject,
                                                                TArray<FHitResult>& OutHits, const FVector& Start,
                                                                const FVector& End, float Radius,
                                                                const TArray<TEnumAsByte<EObjectTypeQuery>>&
                                                                ObjectTypes, const TArray<AActor*>& ActorsToIgnore,
                                                                bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	FCollisionObjectQueryParams ObjectQueryParams(ObjectTypes);
	return FTraceUtility::SweepMultiByObjectType(World, OutHits, Start, End, FQuat::Identity, ObjectQueryParams,
	                                             FCollisionShape::MakeSphere(Radius), CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::SphereTraceSingleByProfile(const UObject* WorldContextObject, FHitResult& OutHit,
                                                              const FVector& Start, const FVector& End, float Radius,
                                                              const FName& ProfileName,
                                                              const TArray<AActor*>& ActorsToIgnore,
                                                              bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::SweepSingleByProfile(World, OutHit, Start, End, FQuat::Identity, ProfileName,
	                                           FCollisionShape::MakeSphere(Radius), CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::SphereTraceSingleByChannel(const UObject* WorldContextObject, FHitResult& OutHit,
                                                              const FVector& Start, const FVector& End, float Radius,
                                                              ECollisionChannel TraceChannel,
                                                              const TArray<AActor*>& ActorsToIgnore,
                                                              bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::SweepSingleByChannel(World, OutHit, Start, End, FQuat::Identity, TraceChannel,
	                                           FCollisionShape::MakeSphere(Radius), CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::SphereTraceSingleByObjectType(const UObject* WorldContextObject, FHitResult& OutHit,
                                                                 const FVector& Start, const FVector& End, float Radius,
                                                                 const TArray<TEnumAsByte<EObjectTypeQuery>>&
                                                                 ObjectTypes,
                                                                 const TArray<AActor*>& ActorsToIgnore,
                                                                 bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	FCollisionObjectQueryParams ObjectQueryParams(ObjectTypes);
	return FTraceUtility::SweepSingleByObjectType(World, OutHit, Start, End, FQuat::Identity, ObjectQueryParams,
	                                              FCollisionShape::MakeSphere(Radius), CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::SphereOverlapMultiByProfile(const UObject* WorldContextObject,
                                                               TArray<AActor*>& OutOverlappedActors, const FVector& Pos,
                                                               float Radius, const FName& ProfileName,
                                                               const TArray<AActor*>& ActorsToIgnore,
                                                               bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	TArray<FOverlapResult> OutOverlaps;
	bool bRet = FTraceUtility::OverlapMultiByProfile(World, OutOverlaps, Pos, FQuat::Identity, ProfileName,
	                                                 FCollisionShape::MakeSphere(Radius), CollisionQueryParams);

	for (const FOverlapResult& OutOverlap : OutOverlaps)
	{
		AActor* OverlappedActor = OutOverlap.GetActor();
		if (OutOverlappedActors.Contains(OverlappedActor))
		{
			continue;
		}

		OutOverlappedActors.Add(OverlappedActor);
	}
	return bRet;
}

bool UCDTBlueprintFunctionLibrary::SphereOverlapMultiByChannel(const UObject* WorldContextObject,
                                                               TArray<AActor*>& OutOverlappedActors, const FVector& Pos,
                                                               float Radius, ECollisionChannel TraceChannel,
                                                               const TArray<AActor*>& ActorsToIgnore,
                                                               bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	TArray<FOverlapResult> OutOverlaps;
	bool bRet = FTraceUtility::OverlapMultiByChannel(World, OutOverlaps, Pos, FQuat::Identity, TraceChannel,
	                                                 FCollisionShape::MakeSphere(Radius), CollisionQueryParams);

	for (const FOverlapResult& OutOverlap : OutOverlaps)
	{
		AActor* OverlappedActor = OutOverlap.GetActor();
		if (OutOverlappedActors.Contains(OverlappedActor))
		{
			continue;
		}

		OutOverlappedActors.Add(OverlappedActor);
	}
	return bRet;
}

bool UCDTBlueprintFunctionLibrary::SphereOverlapMultiByObjectType(const UObject* WorldContextObject,
                                                                  TArray<AActor*>& OutOverlappedActors,
                                                                  const FVector& Pos, float Radius,
                                                                  const TArray<TEnumAsByte<EObjectTypeQuery>>&
                                                                  ObjectTypes, const TArray<AActor*>& ActorsToIgnore,
                                                                  bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	FCollisionObjectQueryParams ObjectQueryParams(ObjectTypes);
	TArray<FOverlapResult> OutOverlaps;

	bool bRet = FTraceUtility::OverlapMultiByObjectType(World, OutOverlaps, Pos, FQuat::Identity, ObjectQueryParams,
	                                                    FCollisionShape::MakeSphere(Radius), CollisionQueryParams, bAlwaysDebugDraw);

	for (const FOverlapResult& OutOverlap : OutOverlaps)
	{
		AActor* OverlappedActor = OutOverlap.GetActor();
		if (OutOverlappedActors.Contains(OverlappedActor))
		{
			continue;
		}

		OutOverlappedActors.Add(OverlappedActor);
	}
	return bRet;
}

bool UCDTBlueprintFunctionLibrary::BoxTraceMultiByProfile(const UObject* WorldContextObject,
                                                          TArray<FHitResult>& OutHits, const FVector& Start,
                                                          const FVector& End, const FVector& HalfExtent,
                                                          const FName& ProfileName,
                                                          const TArray<AActor*>& ActorsToIgnore,
                                                          bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::SweepMultiByProfile(World, OutHits, Start, End, FQuat::Identity, ProfileName,
	                                          FCollisionShape::MakeBox(HalfExtent), CollisionQueryParams, bAlwaysDebugDraw);
}

bool UCDTBlueprintFunctionLibrary::BoxTraceMultiByChannel(const UObject* WorldContextObject,
                                                          TArray<FHitResult>& OutHits, const FVector& Start,
                                                          const FVector& End, const FRotator& Rot, const FVector& HalfExtent,
                                                          ECollisionChannel TraceChannel,
                                                          const TArray<AActor*>& ActorsToIgnore,
                                                          bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::SweepMultiByChannel(World, OutHits, Start, End, Rot.Quaternion(), TraceChannel,
	                                          FCollisionShape::MakeBox(HalfExtent), CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::BoxTraceMultiByObjectType(const UObject* WorldContextObject,
                                                             TArray<FHitResult>& OutHits, const FVector& Start,
                                                             const FVector& End, const FVector& HalfExtent,
                                                             const TArray<TEnumAsByte<EObjectTypeQuery>>&
                                                             ObjectTypes, const TArray<AActor*>& ActorsToIgnore,
                                                             bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	FCollisionObjectQueryParams ObjectQueryParams(ObjectTypes);
	return FTraceUtility::SweepMultiByObjectType(World, OutHits, Start, End, FQuat::Identity, ObjectQueryParams,
	                                             FCollisionShape::MakeBox(HalfExtent), CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::BoxTraceSingleByProfile(const UObject* WorldContextObject, FHitResult& OutHit,
                                                           const FVector& Start, const FVector& End,
                                                           const FVector& HalfExtent,
                                                           const FName& ProfileName,
                                                           const TArray<AActor*>& ActorsToIgnore,
                                                           bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::SweepSingleByProfile(World, OutHit, Start, End, FQuat::Identity, ProfileName,
	                                           FCollisionShape::MakeBox(HalfExtent), CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::BoxTraceSingleByChannel(const UObject* WorldContextObject, FHitResult& OutHit,
                                                           const FVector& Start, const FVector& End,
                                                           const FVector& HalfExtent,
                                                           ECollisionChannel TraceChannel,
                                                           const TArray<AActor*>& ActorsToIgnore,
                                                           bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::SweepSingleByChannel(World, OutHit, Start, End, FQuat::Identity, TraceChannel,
	                                           FCollisionShape::MakeBox(HalfExtent), CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::BoxTraceSingleByObjectType(const UObject* WorldContextObject, FHitResult& OutHit,
                                                              const FVector& Start, const FVector& End,
                                                              const FVector& HalfExtent,
                                                              const TArray<TEnumAsByte<EObjectTypeQuery>>&
                                                              ObjectTypes,
                                                              const TArray<AActor*>& ActorsToIgnore,
                                                              bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	FCollisionObjectQueryParams ObjectQueryParams(ObjectTypes);
	return FTraceUtility::SweepSingleByObjectType(World, OutHit, Start, End, FQuat::Identity, ObjectQueryParams,
	                                              FCollisionShape::MakeBox(HalfExtent), CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::BoxOverlapMultiByProfile(const UObject* WorldContextObject,
                                                            TArray<AActor*>& OutOverlappedActors, const FVector& Pos,
                                                            const FVector& HalfExtent, const FName& ProfileName,
                                                            const TArray<AActor*>& ActorsToIgnore,
                                                            bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	TArray<FOverlapResult> OutOverlaps;
	bool bRet = FTraceUtility::OverlapMultiByProfile(World, OutOverlaps, Pos, FQuat::Identity, ProfileName,
	                                                 FCollisionShape::MakeBox(HalfExtent), CollisionQueryParams);

	for (const FOverlapResult& OutOverlap : OutOverlaps)
	{
		AActor* OverlappedActor = OutOverlap.GetActor();
		if (OutOverlappedActors.Contains(OverlappedActor))
		{
			continue;
		}

		OutOverlappedActors.Add(OverlappedActor);
	}
	return bRet;
}

bool UCDTBlueprintFunctionLibrary::BoxOverlapMultiByChannel(const UObject* WorldContextObject,
                                                            TArray<AActor*>& OutOverlappedActors, const FVector& Pos,
                                                            const FVector& HalfExtent, ECollisionChannel TraceChannel,
                                                            const TArray<AActor*>& ActorsToIgnore,
                                                            bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	TArray<FOverlapResult> OutOverlaps;
	bool bRet = FTraceUtility::OverlapMultiByChannel(World, OutOverlaps, Pos, FQuat::Identity, TraceChannel,
	                                                 FCollisionShape::MakeBox(HalfExtent), CollisionQueryParams);

	for (const FOverlapResult& OutOverlap : OutOverlaps)
	{
		AActor* OverlappedActor = OutOverlap.GetActor();
		if (OutOverlappedActors.Contains(OverlappedActor))
		{
			continue;
		}

		OutOverlappedActors.Add(OverlappedActor);
	}
	return bRet;
}

bool UCDTBlueprintFunctionLibrary::BoxOverlapMultiByObjectType(const UObject* WorldContextObject,
                                                               TArray<AActor*>& OutOverlappedActors,
                                                               const FVector& Pos, const FVector& HalfExtent,
                                                               const TArray<TEnumAsByte<EObjectTypeQuery>>&
                                                               ObjectTypes, const TArray<AActor*>& ActorsToIgnore,
                                                               bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	FCollisionObjectQueryParams ObjectQueryParams(ObjectTypes);
	TArray<FOverlapResult> OutOverlaps;

	bool bRet = FTraceUtility::OverlapMultiByObjectType(World, OutOverlaps, Pos, FQuat::Identity, ObjectQueryParams,
	                                                    FCollisionShape::MakeBox(HalfExtent), CollisionQueryParams);

	for (const FOverlapResult& OutOverlap : OutOverlaps)
	{
		AActor* OverlappedActor = OutOverlap.GetActor();
		if (OutOverlappedActors.Contains(OverlappedActor))
		{
			continue;
		}

		OutOverlappedActors.Add(OverlappedActor);
	}
	return bRet;
}

bool UCDTBlueprintFunctionLibrary::CapsuleTraceMultiByProfile(const UObject* WorldContextObject,
                                                              TArray<FHitResult>& OutHits, const FVector& Start,
                                                              const FVector& End, float Radius, float HalfHeight,
                                                              const FName& ProfileName,
                                                              const TArray<AActor*>& ActorsToIgnore,
                                                              bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::SweepMultiByProfile(World, OutHits, Start, End, FQuat::Identity, ProfileName,
	                                          FCollisionShape::MakeCapsule(Radius, HalfHeight), CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::CapsuleTraceMultiByChannel(const UObject* WorldContextObject,
                                                              TArray<FHitResult>& OutHits, const FVector& Start,
                                                              const FVector& End, float Radius, float HalfHeight,
                                                              ECollisionChannel TraceChannel,
                                                              const TArray<AActor*>& ActorsToIgnore,
                                                              bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::SweepMultiByChannel(World, OutHits, Start, End, FQuat::Identity, TraceChannel,
	                                          FCollisionShape::MakeCapsule(Radius, HalfHeight), CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::CapsuleTraceMultiByObjectType(const UObject* WorldContextObject,
                                                                 TArray<FHitResult>& OutHits, const FVector& Start,
                                                                 const FVector& End, float Radius, float HalfHeight,
                                                                 const TArray<TEnumAsByte<EObjectTypeQuery>>&
                                                                 ObjectTypes, const TArray<AActor*>& ActorsToIgnore,
                                                                 bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	FCollisionObjectQueryParams ObjectQueryParams(ObjectTypes);
	return FTraceUtility::SweepMultiByObjectType(World, OutHits, Start, End, FQuat::Identity, ObjectQueryParams,
	                                             FCollisionShape::MakeCapsule(Radius, HalfHeight),
	                                             CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::CapsuleTraceSingleByProfile(const UObject* WorldContextObject, FHitResult& OutHit,
                                                               const FVector& Start, const FVector& End, float Radius,
                                                               float HalfHeight,
                                                               const FName& ProfileName,
                                                               const TArray<AActor*>& ActorsToIgnore,
                                                               bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::SweepSingleByProfile(World, OutHit, Start, End, FQuat::Identity, ProfileName,
	                                           FCollisionShape::MakeCapsule(Radius, HalfHeight), CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::CapsuleTraceSingleByChannel(const UObject* WorldContextObject, FHitResult& OutHit,
                                                               const FVector& Start, const FVector& End, float Radius,
                                                               float HalfHeight,
                                                               ECollisionChannel TraceChannel,
                                                               const TArray<AActor*>& ActorsToIgnore,
                                                               bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::SweepSingleByChannel(World, OutHit, Start, End, FQuat::Identity, TraceChannel,
	                                           FCollisionShape::MakeCapsule(Radius, HalfHeight), CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::CapsuleTraceSingleByObjectType(const UObject* WorldContextObject, FHitResult& OutHit,
                                                                  const FVector& Start, const FVector& End,
                                                                  float Radius, float HalfHeight,
                                                                  const TArray<TEnumAsByte<EObjectTypeQuery>>&
                                                                  ObjectTypes,
                                                                  const TArray<AActor*>& ActorsToIgnore,
                                                                  bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	FCollisionObjectQueryParams ObjectQueryParams(ObjectTypes);
	return FTraceUtility::SweepSingleByObjectType(World, OutHit, Start, End, FQuat::Identity, ObjectQueryParams,
	                                              FCollisionShape::MakeCapsule(Radius, HalfHeight),
	                                              CollisionQueryParams);
}

bool UCDTBlueprintFunctionLibrary::CapsuleOverlapMultiByProfile(const UObject* WorldContextObject,
                                                                TArray<AActor*>& OutOverlappedActors,
                                                                const FVector& Pos,
                                                                float Radius, float HalfHeight,
                                                                const FName& ProfileName,
                                                                const TArray<AActor*>& ActorsToIgnore,
                                                                bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	TArray<FOverlapResult> OutOverlaps;
	bool bRet = FTraceUtility::OverlapMultiByProfile(World, OutOverlaps, Pos, FQuat::Identity, ProfileName,
	                                                 FCollisionShape::MakeCapsule(Radius, HalfHeight),
	                                                 CollisionQueryParams);

	for (const FOverlapResult& OutOverlap : OutOverlaps)
	{
		AActor* OverlappedActor = OutOverlap.GetActor();
		if (OutOverlappedActors.Contains(OverlappedActor))
		{
			continue;
		}

		OutOverlappedActors.Add(OverlappedActor);
	}
	return bRet;
}

bool UCDTBlueprintFunctionLibrary::CapsuleOverlapMultiByChannel(const UObject* WorldContextObject,
                                                                TArray<AActor*>& OutOverlappedActors,
                                                                const FVector& Pos,
                                                                float Radius, float HalfHeight,
                                                                ECollisionChannel TraceChannel,
                                                                const TArray<AActor*>& ActorsToIgnore,
                                                                bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	TArray<FOverlapResult> OutOverlaps;
	bool bRet = FTraceUtility::OverlapMultiByChannel(World, OutOverlaps, Pos, FQuat::Identity, TraceChannel,
	                                                 FCollisionShape::MakeCapsule(Radius, HalfHeight),
	                                                 CollisionQueryParams);

	for (const FOverlapResult& OutOverlap : OutOverlaps)
	{
		AActor* OverlappedActor = OutOverlap.GetActor();
		if (OutOverlappedActors.Contains(OverlappedActor))
		{
			continue;
		}

		OutOverlappedActors.Add(OverlappedActor);
	}
	return bRet;
}

bool UCDTBlueprintFunctionLibrary::CapsuleOverlapMultiByObjectType(const UObject* WorldContextObject,
                                                                   TArray<AActor*>& OutOverlappedActors,
                                                                   const FVector& Pos, float Radius, float HalfHeight,
                                                                   const TArray<TEnumAsByte<EObjectTypeQuery>>&
                                                                   ObjectTypes, const TArray<AActor*>& ActorsToIgnore,
                                                                   bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FCollisionQueryParams CollisionQueryParams;
	CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
	FCollisionObjectQueryParams ObjectQueryParams(ObjectTypes);
	TArray<FOverlapResult> OutOverlaps;

	bool bRet = FTraceUtility::OverlapMultiByObjectType(World, OutOverlaps, Pos, FQuat::Identity, ObjectQueryParams,
	                                                    FCollisionShape::MakeCapsule(Radius, HalfHeight),
	                                                    CollisionQueryParams);

	for (const FOverlapResult& OutOverlap : OutOverlaps)
	{
		AActor* OverlappedActor = OutOverlap.GetActor();
		if (OutOverlappedActors.Contains(OverlappedActor))
		{
			continue;
		}

		OutOverlappedActors.Add(OverlappedActor);
	}
	return bRet;
}

bool UCDTBlueprintFunctionLibrary::ComponentOverlapMulti(const UObject* WorldContextObject,
                                                         TArray<AActor*>& OutOverlappedActors,
                                                         const UPrimitiveComponent* PrimComp, const FVector& Pos,
                                                         const FQuat& Rot,
                                                         const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes,
                                                         const TArray<AActor*>& ActorsToIgnore,
                                                         bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FComponentQueryParams ComponentQueryParams;
	ComponentQueryParams.AddIgnoredActors(ActorsToIgnore);
	FCollisionObjectQueryParams CollisionObjectQueryParams(ObjectTypes);
	TArray<FOverlapResult> OutOverlaps;

	bool bRet = FTraceUtility::ComponentOverlapMulti(World, OutOverlaps, PrimComp, Pos, Rot,
	                                                 ComponentQueryParams, CollisionObjectQueryParams);

	for (const FOverlapResult& OutOverlap : OutOverlaps)
	{
		AActor* OverlappedActor = OutOverlap.GetActor();
		if (OutOverlappedActors.Contains(OverlappedActor))
		{
			continue;
		}

		OutOverlappedActors.Add(OverlappedActor);
	}
	return bRet;
}

bool UCDTBlueprintFunctionLibrary::ComponentOverlapMultiByChannel(const UObject* WorldContextObject,
                                                                  TArray<AActor*>& OutOverlappedActors,
                                                                  const UPrimitiveComponent* PrimComp,
                                                                  const FVector& Pos, const FQuat& Rot,
                                                                  ECollisionChannel TraceChannel,
                                                                  const TArray<TEnumAsByte<EObjectTypeQuery>>&
                                                                  ObjectTypes,
                                                                  const TArray<AActor*>& ActorsToIgnore,
                                                                  bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FComponentQueryParams ComponentQueryParams;
	ComponentQueryParams.AddIgnoredActors(ActorsToIgnore);
	FCollisionObjectQueryParams CollisionObjectQueryParams(ObjectTypes);
	TArray<FOverlapResult> OutOverlaps;

	bool bRet = FTraceUtility::ComponentOverlapMultiByChannel(World, OutOverlaps, PrimComp, Pos, Rot,
	                                                          TraceChannel, ComponentQueryParams,
	                                                          CollisionObjectQueryParams);

	for (const FOverlapResult& OutOverlap : OutOverlaps)
	{
		AActor* OverlappedActor = OutOverlap.GetActor();
		if (OutOverlappedActors.Contains(OverlappedActor))
		{
			continue;
		}

		OutOverlappedActors.Add(OverlappedActor);
	}
	return bRet;
}

bool UCDTBlueprintFunctionLibrary::ComponentSweepMulti(const UObject* WorldContextObject, TArray<FHitResult>& OutHits,
                                                       UPrimitiveComponent* PrimComp, const FVector& Start,
                                                       const FVector& End, const FQuat& Rot,
                                                       const TArray<AActor*>& ActorsToIgnore,
                                                       bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FComponentQueryParams ComponentQueryParams;
	ComponentQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::ComponentSweepMulti(World, OutHits, PrimComp, Start, End, Rot, ComponentQueryParams);
}

bool UCDTBlueprintFunctionLibrary::ComponentSweepMultiByChannel(const UObject* WorldContextObject,
                                                                TArray<FHitResult>& OutHits,
                                                                UPrimitiveComponent* PrimComp, const FVector& Start,
                                                                const FVector& End,
                                                                const FQuat& Rot, ECollisionChannel TraceChannel,
                                                                const TArray<AActor*>& ActorsToIgnore,
                                                                bool bAlwaysDebugDraw /*= false*/)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FComponentQueryParams ComponentQueryParams;
	ComponentQueryParams.AddIgnoredActors(ActorsToIgnore);
	return FTraceUtility::ComponentSweepMultiByChannel(World, OutHits, PrimComp, Start, End, Rot, TraceChannel,
	                                                   ComponentQueryParams);
}

void UCDTBlueprintFunctionLibrary::VisualizeOverlapResults(const UObject* WorldContextObject, const FVector& Pos,
                                                           const TArray<AActor*> OverlappedActors,
                                                           bool bAlwaysDebugDraw /*= false*/)
{
#if !UE_BUILD_SHIPPING
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	if (bAlwaysDebugDraw || CVarDebugDrawTraces.GetValueOnGameThread())
	{
		const float Duration = CVarDebugDrawTracesDuration.GetValueOnGameThread();
		for (const AActor* OverlappedActor : OverlappedActors)
		{
			DrawDebugLine(World, Pos, OverlappedActor->GetActorLocation(), FColor::Green,
			              false, Duration, SDPG_Foreground);
		}
	}
#endif
}

void UCDTBlueprintFunctionLibrary::VisualizeTraceHits(const UObject* WorldContextObject,
                                                      const TArray<FHitResult>& OverlappedHits,
                                                      bool bAlwaysDebugDraw /*= false*/)
{
#if !UE_BUILD_SHIPPING
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!ensure(IsValid(World)))
	{
		World = GWorld;
	}

	FTraceUtility::VisualizeTraceHits(World, OverlappedHits, bAlwaysDebugDraw);
#endif
}
