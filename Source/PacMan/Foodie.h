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

// 動的マルチキャストデリゲート(イベントディスパッチャー)宣言 (型,引数名)
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
	virtual void Tick(float DeltaTime) override;

	// 餌の獲得
	void Consume();

	// 餌のタイプ
	UPROPERTY(EditAnywhere)
		EFoodieType FoodieType = EFoodieType::Regular;

	// 動的マルチキャストデリゲート(イベントディスパッチャー)の定義
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FFoodieEatenEvent FoodieEatenEvent;

private:

	// 餌取得時の音
	UPROPERTY(EditAnywhere)
		USoundCue* ConsumptionSound;

};
