// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PacmanController.generated.h"

// �O���錾
class APacmanPawn;

UCLASS()
class PACMAN_API APacmanController : public APlayerController
{
	GENERATED_BODY()

protected:

	// �R���g���[���[�̐ݒ�
	void SetupInputComponent() override;

	// �v���C���[�̃|�[�����擾
	APacmanPawn* GetPacmanPawn() const;

public:

	// �ړ��֐�
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

};
