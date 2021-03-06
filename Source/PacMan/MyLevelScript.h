// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "Foodie.h"
#include "EngineUtils.h"
#include "MyLevelScript.generated.h"

UCLASS()
class PACMAN_API AMyLevelScript : public ALevelScriptActor
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	AMyLevelScript();

	// 餌の数取得
	UFUNCTION(BlueprintCallable)
		void GetFoodieCount(int num);

	// 餌の数
	static int& GetFoodieCounter() { return FoodieCounter; }

	static int FoodieCounter;

	UPROPERTY(EditAnywhere)
		FName LevelToLoad;
};
