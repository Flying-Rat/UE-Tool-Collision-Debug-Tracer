// Copyright 2022 Tadeáš Anděl, All Rights Reserved.

#include "Visualizers/StaticMeshVisualizer.h"

#include "TraceUtility.h"

#include "Actors/Components/StaticMeshTraceDummyComponent.h"

void FStaticMeshTraceVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View,
                                                   FPrimitiveDrawInterface* PDI)
{
	// This is a workaround for removing const from Component, because not all engine functions have const ptr in parameters
	AActor* TraceOwner = Component->GetOwner();
	if (!IsValid(TraceOwner))
	{
		return;
	}

	TArray<UStaticMeshTraceDummyComponent*> FoundComponents; 
	TraceOwner->GetComponents<UStaticMeshTraceDummyComponent>(FoundComponents);
	
	UStaticMeshTraceDummyComponent* TraceComponent{ nullptr };
	for (UStaticMeshTraceDummyComponent* FoundComponent : FoundComponents)
	{
		if (FoundComponent == Component)
		{
			TraceComponent = FoundComponent;
			break;
		}
	}
	
	if (!IsValid(TraceComponent))
	{
		return;
	}
	const FVector& Start = TraceComponent->GetComponentLocation();
	const FVector& End = Start + TraceComponent->TraceVector;

	UWorld* World = Component->GetWorld();
	if (!IsValid(World))
	{
		return;
	}

	switch (TraceComponent->TraceType)
	{
		case ESMTraceType::OverlapMulti:
		{
			TArray<FOverlapResult> OverlapResults;
			switch (TraceComponent->QueryType)
			{
				case ESMQueryType::Component:
				{
					World->ComponentOverlapMulti(OverlapResults, TraceComponent, Start,
					                             TraceComponent->GetComponentQuat());
					break;
				}
				case ESMQueryType::TraceChannel:
				{
					World->ComponentOverlapMultiByChannel(OverlapResults, TraceComponent, Start,
					                                      TraceComponent->GetComponentQuat(),
					                                      TraceComponent->TraceChannel);
					break;
				}
			}
			FTraceUtility::VisualizeOverlapResults(World, Start, OverlapResults);
			break;
		}
		case ESMTraceType::SweepMulti:
		{
			TArray<FHitResult> HitResults;
			FComponentQueryParams ComponentQueryParams;
			switch (TraceComponent->QueryType)
			{
				case ESMQueryType::Component:
				{
					World->ComponentSweepMulti(HitResults, TraceComponent, Start, End,
					                           TraceComponent->GetComponentQuat(), ComponentQueryParams);
					break;
				}
				case ESMQueryType::TraceChannel:
				{
					World->ComponentSweepMultiByChannel(HitResults, TraceComponent, Start, End,
					                                    TraceComponent->GetComponentQuat(),
					                                    TraceComponent->TraceChannel, ComponentQueryParams);
					break;
				}
			}

			FTraceUtility::VisualizeTraceHits(World, HitResults);
			break;
		}
	}

	if (TraceComponent->TraceType != ESMTraceType::SweepMulti)
	{
		return;
	}

	UStaticMesh* StaticMesh = TraceComponent->GetStaticMesh();
	if (!IsValid(StaticMesh))
	{
		return;
	}

	FStaticMeshLODResources& LODModel = StaticMesh->GetRenderData()->LODResources[0];
	FPositionVertexBuffer& VertexBuffer = LODModel.VertexBuffers.PositionVertexBuffer;

	TArray<FVector> Vertices;
	const FTransform& Tranform = TraceComponent->GetComponentTransform();
	for (uint32 Index = 0; Index < VertexBuffer.GetNumVertices(); ++Index)
	{
		Vertices.Add(
			Tranform.TransformPosition(FVector(VertexBuffer.VertexPosition(Index))) + TraceComponent->
			TraceVector);
	}

	FRawStaticIndexBuffer& IndexBuffer = LODModel.IndexBuffer;
	TArray<int32> Indices;
	Indices.Reserve(IndexBuffer.GetNumIndices());
	for (int32 Index = 0; Index < IndexBuffer.GetNumIndices(); ++Index)
	{
		Indices.Add(IndexBuffer.GetIndex(Index));
	}

	DrawDebugMesh(World, Vertices, Indices, FColor::Red, false, 0.03f, SDPG_Foreground);

	FVector Min;
	FVector Max;
	TraceComponent->GetLocalBounds(Min, Max);
	const FVector& Vertex1 = Tranform.TransformPosition(FVector(Max.X, Min.Y, Max.Z));
	const FVector& Vertex2 = Tranform.TransformPosition(FVector(Min.X, Min.Y, Max.Z));
	const FVector& Vertex3 = Tranform.TransformPosition(FVector(Min.X, Max.Y, Max.Z));
	const FVector& Vertex4 = Tranform.TransformPosition(FVector(Max.X, Max.Y, Max.Z));
	const FVector& Vertex5 = Tranform.TransformPosition(FVector(Max.X, Min.Y, Min.Z));
	const FVector& Vertex6 = Tranform.TransformPosition(FVector(Min.X, Min.Y, Min.Z));
	const FVector& Vertex7 = Tranform.TransformPosition(FVector(Min.X, Max.Y, Min.Z));
	const FVector& Vertex8 = Tranform.TransformPosition(FVector(Max.X, Max.Y, Min.Z));

	PDI->DrawLine(Vertex1, Vertex1 + TraceComponent->TraceVector, FLinearColor::Red, SDPG_Foreground);
	PDI->DrawLine(Vertex2, Vertex2 + TraceComponent->TraceVector, FLinearColor::Red, SDPG_Foreground);
	PDI->DrawLine(Vertex3, Vertex3 + TraceComponent->TraceVector, FLinearColor::Red, SDPG_Foreground);
	PDI->DrawLine(Vertex4, Vertex4 + TraceComponent->TraceVector, FLinearColor::Red, SDPG_Foreground);
	PDI->DrawLine(Vertex5, Vertex5 + TraceComponent->TraceVector, FLinearColor::Red, SDPG_Foreground);
	PDI->DrawLine(Vertex6, Vertex6 + TraceComponent->TraceVector, FLinearColor::Red, SDPG_Foreground);
	PDI->DrawLine(Vertex7, Vertex7 + TraceComponent->TraceVector, FLinearColor::Red, SDPG_Foreground);
	PDI->DrawLine(Vertex8, Vertex8 + TraceComponent->TraceVector, FLinearColor::Red, SDPG_Foreground);
}
