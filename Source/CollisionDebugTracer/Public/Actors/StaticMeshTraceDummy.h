// Copyright 2022 Tadeáš Anděl, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "StaticMeshTraceDummy.generated.h"

class UStaticMeshTraceDummyComponent;

UCLASS(BlueprintType, Blueprintable)
class COLLISIONDEBUGTRACER_API AStaticMeshTraceDummy : public AActor
{
	GENERATED_BODY()

public: // Construction

	AStaticMeshTraceDummy();

protected: // Components

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshTraceDummyComponent> TraceDummyComponent;
};