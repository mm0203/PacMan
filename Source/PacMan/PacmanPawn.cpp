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

	// �����蔻��̐錾�I�Ȃ����
	OnActorBeginOverlap.AddDynamic(this, &APacmanPawn::OnOverlapBegin);
}

void APacmanPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// �������ԂȂ�
	if (!Frozen)
	{
		// �w�肵�������ɓ�����
		AddMovementInput(GetActorForwardVector());
	}
}

// �L�[���͂̌Ăяo��
void APacmanPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// �v���C���[�̌�����ς���
void APacmanPawn::SetDirection(const FVector Direction)
{
	if (Direction == FVector::UpVector) 		// ��
	{
		SetActorRotation(FRotator(0, 270, 0));
	}
	else if (Direction == FVector::DownVector)	// ��
	{
		SetActorRotation(FRotator(0, 90, 0));
	}
	else if (Direction == FVector::RightVector)	// �E
	{
		SetActorRotation(FRotator(0, 0, 0));
	}
	else if (Direction == FVector::LeftVector)	// ��
	{
		SetActorRotation(FRotator(0, 180, 180));
	}
}

// �v���C���[�ƕʃA�N�^�[�̓����蔻��
void APacmanPawn::OnOverlapBegin(AActor * PlayerActor, AActor * OtherActor)
{
	// �ʏ�̉a
	if (OtherActor->ActorHasTag("Foodie.Regular")) 
	{
		Cast<AFoodie>(OtherActor)->Consume();
	}
	// �p���[�A�b�v
	if (OtherActor->ActorHasTag("Foodie.PowerUp"))
	{
		Cast<AFoodie>(OtherActor)->Consume();
	}
}

