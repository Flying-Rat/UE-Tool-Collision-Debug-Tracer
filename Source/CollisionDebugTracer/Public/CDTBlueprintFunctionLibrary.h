// Copyright 2022 Tadeáš Anděl, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CDTBlueprintFunctionLibrary.generated.h"

/**
 * Exposes all the TraceUtility.h functions to blueprints
 */
UCLASS(BlueprintType)
class COLLISIONDEBUGTRACER_API UCDTBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public: // TraceUtility

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool LineTraceSingleByProfile(const UObject* WorldContextObject, FHitResult& OutHit, const FVector& Start,
	                                     const FVector& End, const FName& ProfileName,
	                                     const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool LineTraceSingleByChannel(const UObject* WorldContextObject, FHitResult& OutHit, const FVector& Start,
	                                     const FVector& End,
	                                     ECollisionChannel TraceChannel, const TArray<AActor*>& ActorsToIgnore,
	                                     bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore, ObjectTypes"))
	static bool LineTraceSingleByObjectType(const UObject* WorldContextObject, FHitResult& OutHit, const FVector& Start,
	                                        const FVector& End,
	                                        const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes,
	                                        const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool LineTraceMultiByProfile(const UObject* WorldContextObject, TArray<FHitResult>& OutHits,
	                                    const FVector& Start,
	                                    const FVector& End, const FName& ProfileName,
	                                    const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool LineTraceMultiByChannel(const UObject* WorldContextObject, TArray<FHitResult>& OutHits,
	                                    const FVector& Start,
	                                    const FVector& End, ECollisionChannel TraceChannel,
	                                    const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore, ObjectTypes"))
	static bool LineTraceMultiByObjectType(const UObject* WorldContextObject, TArray<FHitResult>& OutHits,
	                                       const FVector& Start,
	                                       const FVector& End,
	                                       const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes,
	                                       const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool SphereTraceMultiByProfile(const UObject* WorldContextObject, TArray<FHitResult>& OutHits,
	                                      const FVector& Start,
	                                      const FVector& End, float Radius, const FName& ProfileName,
	                                      const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool SphereTraceMultiByChannel(const UObject* WorldContextObject, TArray<FHitResult>& OutHits,
	                                      const FVector& Start,
	                                      const FVector& End, float Radius,
	                                      ECollisionChannel TraceChannel,
	                                      const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore, ObjectTypes"))
	static bool SphereTraceMultiByObjectType(const UObject* WorldContextObject, TArray<FHitResult>& OutHits,
	                                         const FVector& Start, const FVector& End, float Radius,
	                                         const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes,
	                                         const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool SphereTraceSingleByProfile(const UObject* WorldContextObject, FHitResult& OutHit,
	                                       const FVector& Start,
	                                       const FVector& End, float Radius, const FName& ProfileName,
	                                       const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool SphereTraceSingleByChannel(const UObject* WorldContextObject, FHitResult& OutHit,
	                                       const FVector& Start,
	                                       const FVector& End, float Radius,
	                                       ECollisionChannel TraceChannel,
	                                       const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore, ObjectTypes"))
	static bool SphereTraceSingleByObjectType(const UObject* WorldContextObject, FHitResult& OutHit,
	                                          const FVector& Start, const FVector& End, float Radius,
	                                          const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes,
	                                          const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool SphereOverlapMultiByProfile(const UObject* WorldContextObject, TArray<AActor*>& OutOverlappedActors,
	                                        const FVector& Pos, float Radius, const FName& ProfileName,
	                                        const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool SphereOverlapMultiByChannel(const UObject* WorldContextObject, TArray<AActor*>& OutOverlappedActors,
	                                        const FVector& Pos, float Radius, ECollisionChannel TraceChannel,
	                                        const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore, ObjectTypes"))
	static bool SphereOverlapMultiByObjectType(const UObject* WorldContextObject, TArray<AActor*>& OutOverlappedActors,
	                                           const FVector& Pos, float Radius,
	                                           const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes,
	                                           const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool BoxTraceMultiByProfile(const UObject* WorldContextObject, TArray<FHitResult>& OutHits,
	                                   const FVector& Start,
	                                   const FVector& End, const FVector& HalfExtent, const FName& ProfileName,
	                                   const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore, Rot"))
	static bool BoxTraceMultiByChannel(const UObject* WorldContextObject, TArray<FHitResult>& OutHits,
	                                   const FVector& Start,
	                                   const FVector& End, const FRotator& Rot, const FVector& HalfExtent,
	                                   ECollisionChannel TraceChannel,
	                                   const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore, ObjectTypes"))
	static bool BoxTraceMultiByObjectType(const UObject* WorldContextObject, TArray<FHitResult>& OutHits,
	                                      const FVector& Start, const FVector& End, const FVector& HalfExtent,
	                                      const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes,
	                                      const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool BoxTraceSingleByProfile(const UObject* WorldContextObject, FHitResult& OutHit,
	                                    const FVector& Start,
	                                    const FVector& End, const FVector& HalfExtent, const FName& ProfileName,
	                                    const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool BoxTraceSingleByChannel(const UObject* WorldContextObject, FHitResult& OutHit,
	                                    const FVector& Start,
	                                    const FVector& End, const FVector& HalfExtent,
	                                    ECollisionChannel TraceChannel,
	                                    const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore, ObjectTypes"))
	static bool BoxTraceSingleByObjectType(const UObject* WorldContextObject, FHitResult& OutHit,
	                                       const FVector& Start, const FVector& End, const FVector& HalfExtent,
	                                       const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes,
	                                       const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool BoxOverlapMultiByProfile(const UObject* WorldContextObject, TArray<AActor*>& OutOverlappedActors,
	                                     const FVector& Pos, const FVector& HalfExtent, const FName& ProfileName,
	                                     const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool BoxOverlapMultiByChannel(const UObject* WorldContextObject, TArray<AActor*>& OutOverlappedActors,
	                                     const FVector& Pos, const FVector& HalfExtent, ECollisionChannel TraceChannel,
	                                     const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore, ObjectTypes"))
	static bool BoxOverlapMultiByObjectType(const UObject* WorldContextObject, TArray<AActor*>& OutOverlappedActors,
	                                        const FVector& Pos, const FVector& HalfExtent,
	                                        const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes,
	                                        const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool CapsuleTraceMultiByProfile(const UObject* WorldContextObject, TArray<FHitResult>& OutHits,
	                                       const FVector& Start,
	                                       const FVector& End, float Radius, float HalfHeight, const FName& ProfileName,
	                                       const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool CapsuleTraceMultiByChannel(const UObject* WorldContextObject, TArray<FHitResult>& OutHits,
	                                       const FVector& Start,
	                                       const FVector& End, float Radius, float HalfHeight,
	                                       ECollisionChannel TraceChannel,
	                                       const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore, ObjectTypes"))
	static bool CapsuleTraceMultiByObjectType(const UObject* WorldContextObject, TArray<FHitResult>& OutHits,
	                                          const FVector& Start, const FVector& End, float Radius, float HalfHeight,
	                                          const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes,
	                                          const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool CapsuleTraceSingleByProfile(const UObject* WorldContextObject, FHitResult& OutHit,
	                                        const FVector& Start,
	                                        const FVector& End, float Radius, float HalfHeight,
	                                        const FName& ProfileName,
	                                        const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool CapsuleTraceSingleByChannel(const UObject* WorldContextObject, FHitResult& OutHit,
	                                        const FVector& Start,
	                                        const FVector& End, float Radius, float HalfHeight,
	                                        ECollisionChannel TraceChannel,
	                                        const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore, ObjectTypes"))
	static bool CapsuleTraceSingleByObjectType(const UObject* WorldContextObject, FHitResult& OutHit,
	                                           const FVector& Start, const FVector& End, float Radius, float HalfHeight,
	                                           const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes,
	                                           const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool CapsuleOverlapMultiByProfile(const UObject* WorldContextObject, TArray<AActor*>& OutOverlappedActors,
	                                         const FVector& Pos, float Radius, float HalfHeight,
	                                         const FName& ProfileName,
	                                         const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore"))
	static bool CapsuleOverlapMultiByChannel(const UObject* WorldContextObject, TArray<AActor*>& OutOverlappedActors,
	                                         const FVector& Pos, float Radius, float HalfHeight,
	                                         ECollisionChannel TraceChannel,
	                                         const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore, ObjectTypes"))
	static bool CapsuleOverlapMultiByObjectType(const UObject* WorldContextObject, TArray<AActor*>& OutOverlappedActors,
	                                            const FVector& Pos, float Radius, float HalfHeight,
	                                            const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes,
	                                            const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore, Rot, ObjectTypes"))
	static bool ComponentOverlapMulti(const UObject* WorldContextObject, TArray<AActor*>& OutOverlappedActors,
	                                  const UPrimitiveComponent* PrimComp, const FVector& Pos, const FQuat& Rot,
	                                  const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes,
	                                  const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore, Rot, ObjectTypes"))
	static bool ComponentOverlapMultiByChannel(const UObject* WorldContextObject, TArray<AActor*>& OutOverlappedActors,
	                                           const UPrimitiveComponent* PrimComp, const FVector& Pos,
	                                           const FQuat& Rot, ECollisionChannel TraceChannel,
	                                           const TArray<TEnumAsByte<EObjectTypeQuery>>& ObjectTypes,
	                                           const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore, Rot"))
	static bool ComponentSweepMulti(const UObject* WorldContextObject, TArray<FHitResult>& OutHits,
	                                UPrimitiveComponent* PrimComp,
	                                const FVector& Start, const FVector& End, const FQuat& Rot,
	                                const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"), meta = (AutoCreateRefTerm="ActorsToIgnore, Rot"))
	static bool ComponentSweepMultiByChannel(const UObject* WorldContextObject, TArray<FHitResult>& OutHits,
	                                         UPrimitiveComponent* PrimComp, const FVector& Start, const FVector& End,
	                                         const FQuat& Rot, ECollisionChannel TraceChannel,
	                                         const TArray<AActor*>& ActorsToIgnore, bool bAlwaysDebugDraw = false);

public: // Hit and Overlap result visualizers

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"))
	static void VisualizeOverlapResults(const UObject* WorldContextObject, const FVector& Pos,
	                                    const TArray<AActor*> OverlappedActors, bool bAlwaysDebugDraw = false);

	UFUNCTION(BlueprintCallable, Category="CDT", meta=(WorldContext="WorldContextObject"))
	static void VisualizeTraceHits(const UObject* WorldContextObject, const TArray<FHitResult>& OverlappedHits, bool bAlwaysDebugDraw = false);
};
