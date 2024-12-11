// Copyright 2022 Tadeáš Anděl, All Rights Reserved.

#include "Actors/Components/StaticMeshTraceDummyComponent.h"

#if WITH_EDITOR
bool UStaticMeshTraceDummyComponent::CanEditChange(const FProperty* InProperty) const
{
	if (InProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UStaticMeshTraceDummyComponent, TraceVector))
	{
		return TraceType == ESMTraceType::SweepMulti;
	}
	
	if (InProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UStaticMeshTraceDummyComponent, TraceChannel))
	{
		return QueryType == ESMQueryType::TraceChannel;
	}

	return true;
}
#endif