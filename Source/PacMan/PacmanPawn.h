// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PacmanPawn.generated.h"

UCLASS()
class PACMAN_API APacmanPawn : public APawn
{
	GENERATED_BODY()

public:
	APacmanPawn();

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

public:

	// 移動方向をセット
	void SetDirection(const FVector Direction);

	// 止まっているか
	bool IsFrozen() { return Frozen; }

	// 動けるか止まっているかを設定
	UFUNCTION(BlueprintCallable)
		void SetFrozen(bool Value) { Frozen = Value; }

private:

	// 当たり判定
	UFUNCTION()
		void OnOverlapBegin(AActor* PlayerActor, AActor* OtherActor);
};
