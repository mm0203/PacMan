// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPawn.h"

#include "PacmanPawn.h"

AEnemyPawn::AEnemyPawn()
{

}

void AEnemyPawn::Tick(float DeltaTime)
{
}


void AEnemyPawn::Hunt()
{
	// �T��
	State = EEnemyState::Hunt;

	// �C�x���g�f�B�X�p�b�`���[�̌Ăяo��
	StateChangedEvent.Broadcast(State);
}

void AEnemyPawn::Idle()
{
	// �ҋ@
	State = EEnemyState::Idle;

	// �C�x���g�f�B�X�p�b�`���[�̌Ăяo��
	StateChangedEvent.Broadcast(State);
}

void AEnemyPawn::RunAway()
{
	// ������
	State = EEnemyState::RunAway;

	// �C�x���g�f�B�X�p�b�`���[�̌Ăяo��
	StateChangedEvent.Broadcast(State);
}

// �v���C���[�ƕʃA�N�^�[�̓����蔻��
void AEnemyPawn::OnComponentHit(AActor* PlayerActor, AActor* OtherActor)
{
	//// �ʏ�̉a
	//if (OtherActor->ActorHasTag("Pacman"))
	//{
	//	if(Cast<APacmanPawn>(OtherActor)->IsPowerUp())
	//	{
	//		FVector location = FVector(0, 150, 50);

	//		SetActorLocation(location);
	//	}
	//	else
	//	{
	//		FVector location = FVector(10000, 10050, 50);

	//		Cast<APacmanPawn>(OtherActor)->SetActorLocation(location);
	//	}
	//}
}
