// Copyright 2022 Tadeáš Anděl, All Rights Reserved.

#include "Actors/Components/CollisionTraceDummy.h"

#if WITH_EDITOR
bool UCollisionTraceDummy::CanEditChange(const FProperty* InProperty) const
{
	if (InProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UCollisionTraceDummy, TraceChannel))
	{
		return QueryType == EQueryType::TraceChannel;
	}

	if (InProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UCollisionTraceDummy, CollisionProfile))
	{
		return QueryType == EQueryType::CollisionProfile;
	}

	if (InProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UCollisionTraceDummy, ObjectTypes))
	{
		return QueryType == EQueryType::ObjectType;
	}

	if (InProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UCollisionTraceDummy, TraceLength))
	{
		return TraceType == ETraceType::SweepSingle || TraceType == ETraceType::SweepMulti;
	}

	if (InProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UCollisionTraceDummy, Radius))
	{
		return CollisionShape == ECollisionTraceShape::Sphere || CollisionShape == ECollisionTraceShape::Capsule;
	}

	if (InProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UCollisionTraceDummy, CapsuleHalfHeight))
	{
		return CollisionShape == ECollisionTraceShape::Capsule;
	}

	if (InProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UCollisionTraceDummy, BoxHalfExtent))
	{
		return CollisionShape == ECollisionTraceShape::Box;
	}
	
	return true;
}
#endif