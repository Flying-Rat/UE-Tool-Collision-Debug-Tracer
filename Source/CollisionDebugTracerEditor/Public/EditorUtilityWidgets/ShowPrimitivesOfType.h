// Copyright 2022 Tadeáš Anděl, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Editor/Blutility/Classes/EditorUtilityWidget.h"

#include "ShowPrimitivesOfType.generated.h"

class UCheckBox;
class UEditableText;
class UButton;

UCLASS(BlueprintType, Blueprintable)
class COLLISIONDEBUGTRACEREDITOR_API UShowPrimitivesOfType : public UEditorUtilityWidget
{
	GENERATED_BODY()

public: // Overrides

	virtual void NativeConstruct() override;

private: // Callbacks

	UFUNCTION()
	void ShowPrimitivesForProfile();

	UFUNCTION()
	void FindPrimitivesAssetsForProfile();
	
	UFUNCTION()
	void UnHideAllActors();

protected: // Widgets

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UCheckBox* LogPrimitives;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UEditableText* CollisionProfileNameText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* ShowPrimitivesForProfileButton;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* FindPrimitivesAssetsForProfileButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* UnHideAllActorsButton;
};