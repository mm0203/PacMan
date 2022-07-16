// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Foodie.generated.h"

// 前方宣言
class USoundCue;

// 餌の種類
UENUM(BlueprintType)
enum class EFoodieType : uint8
{
	Regular,	// 通常
	PowerUp		// パワーアップ
};

// なんかデリゲートするっぽい　よくわからん
// ノード終了時に呼ぶデリゲートらしい？
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFoodieEatenEvent, EFoodieType, FoodieType);

UCLASS()
class PACMAN_API AFoodie : public AActor
{
	GENERATED_BODY()
	
public:	
	AFoodie();

protected:
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Consume();

	UPROPERTY(EditAnywhere)
		EFoodieType FoodieType = EFoodieType::Regular;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FFoodieEatenEvent FoodieEatenEvent;

private:

	UPROPERTY(EditAnywhere)
		USoundCue* ConsumptionSound;


};
