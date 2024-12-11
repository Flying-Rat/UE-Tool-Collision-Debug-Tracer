// Copyright 2022 Tadeáš Anděl, All Rights Reserved.

#include "Actors/StaticMeshTraceDummy.h"

#include "Actors/Components/StaticMeshTraceDummyComponent.h"

AStaticMeshTraceDummy::AStaticMeshTraceDummy()
{
	TraceDummyComponent = CreateDefaultSubobject<UStaticMeshTraceDummyComponent>(TEXT("Trace Dummy Component"));
	RootComponent = TraceDummyComponent;
}
