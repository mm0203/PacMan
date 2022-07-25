// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyPawn.generated.h"

// 敵の状態
UENUM(BlueprintType)
enum class EEnemyState : uint8
{
	Hunt,	 // 探索
	Idle	 // 待機
};

// 状態変化時のイベントディスパッチャー宣言用マクロ　引数:状態
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnemyStateChangedEvent, EEnemyState, NewState);

UCLASS()
class PACMAN_API AEnemyPawn : public APawn
{
	GENERATED_BODY()

public:

	AEnemyPawn();

	virtual void Tick(float DeltaTime) override;

	// 敵の状態
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EEnemyState State = EEnemyState::Hunt;

	// 探索
	UFUNCTION(BlueprintCallable)
		void Hunt();

	// 待機
	UFUNCTION(BlueprintCallable)
		void Idle();

	UFUNCTION(BlueprintImplementableEvent)
		bool TestFunc();

	// 状態変化(イベントディスパッチャー)
	FEnemyStateChangedEvent& OnStateChanged() { return StateChangedEvent; }

private:

	// 状態変化時のイベントディスパッチャー
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FEnemyStateChangedEvent StateChangedEvent;

	// 攻撃が当たったらヒット表示
	UFUNCTION(BlueprintCallable)
	void RunAway();
};
