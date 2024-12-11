// Copyright 2022 Tadeáš Anděl, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "StaticMeshTraceDummyComponent.generated.h"

UENUM(BlueprintType)
enum class ESMTraceType : uint8
{
	OverlapMulti,
	SweepMulti,
};

UENUM(BlueprintType)
enum class ESMQueryType : uint8
{
	Component,
	TraceChannel,
};

UCLASS(BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class COLLISIONDEBUGTRACER_API UStaticMeshTraceDummyComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public: // Overrides

#if WITH_EDITOR
	virtual bool CanEditChange(const FProperty* InProperty) const override;
#endif

public: // Setup

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	ESMTraceType TraceType{ ESMTraceType::OverlapMulti };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	ESMQueryType QueryType{ ESMQueryType::Component };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	FVector TraceVector{ FVector::ZeroVector };
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	TEnumAsByte<ECollisionChannel> TraceChannel;
};
