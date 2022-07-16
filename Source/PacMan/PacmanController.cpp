// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanController.h"

#include "PacmanPawn.h"


// プレイヤーのポーンを取得
APacmanPawn * APacmanController::GetPacmanPawn() const
{
	// キャスト
	// BPでいうCast to ~~ ？
	return Cast<APacmanPawn>(GetPawn());
}

// コントローラーの設定
void APacmanController::SetupInputComponent()
{
	// インプットのコンストラクタ
	Super::SetupInputComponent();

	// 各移動キーを割り当て
	InputComponent->BindAction("MoveUp", IE_Pressed, this, &APacmanController::MoveUp);
	InputComponent->BindAction("MoveDown", IE_Pressed, this, &APacmanController::MoveDown);
	InputComponent->BindAction("MoveLeft", IE_Pressed, this, &APacmanController::MoveLeft);
	InputComponent->BindAction("MoveRight", IE_Pressed, this, &APacmanController::MoveRight);
}

// 上
void APacmanController::MoveUp()
{
	if (GetPacmanPawn() != nullptr) 
	{
		GetPacmanPawn()->SetDirection(FVector::UpVector);
	}
}

// 下
void APacmanController::MoveDown()
{
	if (GetPacmanPawn() != nullptr) 
	{
		GetPacmanPawn()->SetDirection(FVector::DownVector);
	}
}

// 左
void APacmanController::MoveLeft()
{
	if (GetPacmanPawn() != nullptr)
	{
		GetPacmanPawn()->SetDirection(FVector::LeftVector);
	}
}

// 右
void APacmanController::MoveRight()
{
	if (GetPacmanPawn() != nullptr) 
	{
		GetPacmanPawn()->SetDirection(FVector::RightVector);
	}
}
