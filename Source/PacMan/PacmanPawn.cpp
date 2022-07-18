// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanPawn.h"
#include "Foodie.h"

APacmanPawn::APacmanPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APacmanPawn::BeginPlay()
{
	Super::BeginPlay();

	// 当たり判定の宣言的なやつかも
	OnActorBeginOverlap.AddDynamic(this, &APacmanPawn::OnOverlapBegin);
}

void APacmanPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 動ける状態なら
	if (!Frozen)
	{
		// 指定した方向に動かす
		AddMovementInput(GetActorForwardVector());
	}
}

// キー入力の呼び出し
void APacmanPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// プレイヤーの向きを変える
void APacmanPawn::SetDirection(const FVector Direction)
{
	if (Direction == FVector::UpVector) 		// 上
	{
		SetActorRotation(FRotator(0, 270, 0));
	}
	else if (Direction == FVector::DownVector)	// 下
	{
		SetActorRotation(FRotator(0, 90, 0));
	}
	else if (Direction == FVector::RightVector)	// 右
	{
		SetActorRotation(FRotator(0, 0, 0));
	}
	else if (Direction == FVector::LeftVector)	// 左
	{
		SetActorRotation(FRotator(0, 180, 180));
	}
}

// プレイヤーと別アクターの当たり判定
void APacmanPawn::OnOverlapBegin(AActor * PlayerActor, AActor * OtherActor)
{
	// 通常の餌
	if (OtherActor->ActorHasTag("Foodie.Regular")) 
	{
		Cast<AFoodie>(OtherActor)->Consume();
	}
	// パワーアップ
	if (OtherActor->ActorHasTag("Foodie.PowerUp"))
	{
		Cast<AFoodie>(OtherActor)->Consume();
	}
}

