// Copyright 2022 Tadeáš Anděl, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CollisionTraceDummy.generated.h"

UENUM(BlueprintType)
enum class ETraceType : uint8
{
	SweepSingle,
	SweepMulti,
	Overlap,
};

UENUM(BlueprintType)
enum class EQueryType : uint8
{
	CollisionProfile,
	TraceChannel,
	ObjectType
};

UENUM(BlueprintType)
enum class ECollisionTraceShape : uint8
{
	Line,
	Box,
	Sphere,
	Capsule,
};

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class COLLISIONDEBUGTRACER_API UCollisionTraceDummy : public USceneComponent
{
	GENERATED_BODY()

public: // Overrides

#if WITH_EDITOR
	virtual bool CanEditChange(const FProperty* InProperty) const override;
#endif

public: // Setup

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	ECollisionTraceShape CollisionShape;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	ETraceType TraceType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	EQueryType QueryType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	TEnumAsByte<ECollisionChannel> TraceChannel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	FName CollisionProfile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	FRotator RotationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	float TraceLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	float Radius;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	float CapsuleHalfHeight;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	FVector BoxHalfExtent;
};
