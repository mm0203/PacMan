// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyPawn.generated.h"

// 敵の状態
UENUM(BlueprintType)
enum class EEnemyState : uint8
{
	Default, // 探索
	Idle	 // 待機
};

// 動的マルチキャストデリゲート(イベントディスパッチャー)宣言 (型,引数名)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnemyStateChangedEvent, EEnemyState, NewState);

UCLASS()
class PACMAN_API AEnemyPawn : public APawn
{
	GENERATED_BODY()

public:
	// 敵の状態
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EEnemyState State = EEnemyState::Default;

	// 探索
	UFUNCTION(BlueprintCallable)
		void Hunt();

	// 待機
	UFUNCTION(BlueprintCallable)
		void Idle();

	// 状態変化(イベントディスパッチャー)
	FEnemyStateChangedEvent& OnStateChanged() { return StateChangedEvent; }

private:

	// 動的マルチキャストデリゲート(イベントディスパッチャー)の定義
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FEnemyStateChangedEvent StateChangedEvent;

};
