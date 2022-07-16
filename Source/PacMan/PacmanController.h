// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PacmanController.generated.h"

// 前方宣言
class APacmanPawn;

UCLASS()
class PACMAN_API APacmanController : public APlayerController
{
	GENERATED_BODY()

protected:

	// コントローラーの設定
	void SetupInputComponent() override;

	// プレイヤーのポーンを取得
	APacmanPawn* GetPacmanPawn() const;

public:

	// 移動関数
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

};
