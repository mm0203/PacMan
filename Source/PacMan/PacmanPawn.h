// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PacmanPawn.generated.h"


// 敵の状態
UENUM(BlueprintType)
enum class EPacManState : uint8
{
	Regular,	// 通常
	PowerUp		// パワーアップ
};

// パワーアップ時のイベントディスパッチャー宣言用マクロ
DECLARE_MULTICAST_DELEGATE(FIsPowerUpEventDispatcher);

UCLASS()

class PACMAN_API APacmanPawn : public APawn
{
	GENERATED_BODY()

public:
	APacmanPawn();

	// 敵の状態
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EPacManState State = EPacManState::Regular;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// 操作の入力設定
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:

	// 動けるかどうか
	UPROPERTY(BlueprintReadOnly)
		bool Frozen = true;

	// パワーアップ餌を取得
	UPROPERTY(BlueprintReadOnly)
		bool PowerUp = false;

public:

	// 移動方向をセット
	void SetDirection(const FVector Direction);

	// 止まっているか
	bool IsFrozen() { return Frozen; }

	// パワーアップかどうか
	UFUNCTION(BlueprintCallable)
	bool IsPowerUp() { return PowerUp; }

	// 動けるか止まっているかを設定
	UFUNCTION(BlueprintCallable)
		void SetPowerUp(bool Value) { PowerUp = Value; }

	// 動けるか止まっているかを設定
	UFUNCTION(BlueprintCallable)
		void SetFrozen(bool Value) { Frozen = Value; }

private:

	// 当たり判定
	UFUNCTION()
		void OnOverlapBegin(AActor* PlayerActor, AActor* OtherActor);

	// 攻撃が当たった時のイベントディスパッチャー
	FIsPowerUpEventDispatcher OnHitEventDispatcher;
};
