// Copyright 2022 Tadeáš Anděl, All Rights Reserved.

#include "EditorUtilityWidgets/ShowPrimitivesOfType.h"

#include "EngineUtils.h"

#include "AssetRegistry/AssetRegistryModule.h"

#include "Components/Button.h"
#include "Components/CheckBox.h"
#include "Components/EditableText.h"

void UShowPrimitivesOfType::NativeConstruct()
{
	Super::NativeConstruct();

	ShowPrimitivesForProfileButton->OnClicked.AddDynamic(this, &UShowPrimitivesOfType::ShowPrimitivesForProfile);
	FindPrimitivesAssetsForProfileButton->OnClicked.AddDynamic(this, &UShowPrimitivesOfType::FindPrimitivesAssetsForProfile);
	UnHideAllActorsButton->OnClicked.AddDynamic(this, &UShowPrimitivesOfType::UnHideAllActors);
}

void UShowPrimitivesOfType::ShowPrimitivesForProfile()
{
	TArray<FString> CollisionProfileNames;
	CollisionProfileNameText->GetText().ToString().ParseIntoArray(CollisionProfileNames, TEXT(";"));
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AActor* Actor = *ActorItr;
		TArray<UPrimitiveComponent*> PrimitiveComponents;
		Actor->GetComponents<UPrimitiveComponent>(PrimitiveComponents);
		bool bShouldBeHidden{ PrimitiveComponents.Num() != 0 };
		for (UPrimitiveComponent* PrimitiveComponent : PrimitiveComponents)
		{
			for (const FString& CollisionProfileName : CollisionProfileNames)
			{
				if (PrimitiveComponent->GetCollisionProfileName() == FName(*CollisionProfileName))
				{
					Actor->SetIsTemporarilyHiddenInEditor(false);
					bShouldBeHidden = false;
					if (LogPrimitives->IsChecked())
					{
						UE_LOG(LogTemp, Log, TEXT("Actor %s has primitive %s with collision profile %s"), *Actor->GetName(), *PrimitiveComponent->GetName(), *CollisionProfileNameText->GetText().ToString())
					}
					break;
				}
			}
		}

		if (bShouldBeHidden)
		{
			Actor->SetIsTemporarilyHiddenInEditor(true);
		}
	}
}

void UShowPrimitivesOfType::FindPrimitivesAssetsForProfile()
{
	TArray<FAssetData> AssetsData;
	FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get().GetAllAssets(AssetsData);
	
	for (const FAssetData& AssetData : AssetsData)
	{
		FSoftObjectPath AssetSoftObjectPath(AssetData.GetSoftObjectPath());
		UObject* LoadedAsset = AssetSoftObjectPath.TryLoad();
		if (!IsValid(LoadedAsset))
		{
			continue;
		}

		AActor* ActorAsset = Cast<AActor>(LoadedAsset);
		if (!IsValid(ActorAsset))
		{
			continue;
		}

		TArray<UPrimitiveComponent*> PrimitiveComponents;
		ActorAsset->GetComponents<UPrimitiveComponent>(PrimitiveComponents);
		for (UPrimitiveComponent* PrimitiveComponent : PrimitiveComponents)
		{
			if (PrimitiveComponent->GetCollisionProfileName() == FName(*CollisionProfileNameText->GetText().ToString()))
			{
				UE_LOG(LogTemp, Log, TEXT("Asset %s has primitive %s with collision profile %s"), *ActorAsset->GetName(), *PrimitiveComponent->GetName(), *CollisionProfileNameText->GetText().ToString())
			}
		}
	}
}

void UShowPrimitivesOfType::UnHideAllActors()
{
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AActor* Actor = *ActorItr;
		Actor->SetIsTemporarilyHiddenInEditor(false);
	}
}
