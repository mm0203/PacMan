// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanController.h"

#include "PacmanPawn.h"


// �v���C���[�̃|�[�����擾
APacmanPawn * APacmanController::GetPacmanPawn() const
{
	// �L���X�g
	// BP�ł���Cast to ~~ �H
	return Cast<APacmanPawn>(GetPawn());
}

// �R���g���[���[�̐ݒ�
void APacmanController::SetupInputComponent()
{
	// �C���v�b�g�̃R���X�g���N�^
	Super::SetupInputComponent();

	// �e�ړ��L�[�����蓖��
	InputComponent->BindAction("MoveUp", IE_Pressed, this, &APacmanController::MoveUp);
	InputComponent->BindAction("MoveDown", IE_Pressed, this, &APacmanController::MoveDown);
	InputComponent->BindAction("MoveLeft", IE_Pressed, this, &APacmanController::MoveLeft);
	InputComponent->BindAction("MoveRight", IE_Pressed, this, &APacmanController::MoveRight);
}

// ��
void APacmanController::MoveUp()
{
	if (GetPacmanPawn() != nullptr) 
	{
		GetPacmanPawn()->SetDirection(FVector::UpVector);
	}
}

// ��
void APacmanController::MoveDown()
{
	if (GetPacmanPawn() != nullptr) 
	{
		GetPacmanPawn()->SetDirection(FVector::DownVector);
	}
}

// ��
void APacmanController::MoveLeft()
{
	if (GetPacmanPawn() != nullptr)
	{
		GetPacmanPawn()->SetDirection(FVector::LeftVector);
	}
}

// �E
void APacmanController::MoveRight()
{
	if (GetPacmanPawn() != nullptr) 
	{
		GetPacmanPawn()->SetDirection(FVector::RightVector);
	}
}
