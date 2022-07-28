// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPawn.h"
#include "Kismet/KismetSystemLibrary.h" //�ǉ�

AEnemyPawn::AEnemyPawn()
{

}

void AEnemyPawn::Tick(float DeltaTime)
{
}

// �ҋ@
void AEnemyPawn::Idle()
{
	State = EEnemyState::Idle;
	StateChangedEvent.Broadcast(State);
}

// �T��
void AEnemyPawn::Hunt()
{
	State = EEnemyState::Hunt;
	StateChangedEvent.Broadcast(State);
}

// ������
void AEnemyPawn::RunAway()
{
	State = EEnemyState::RunAway;
	StateChangedEvent.Broadcast(State);
}

// �ҋ@���T��
void AEnemyPawn::StartMoving()
{
	// �ҋ@�̃f�B�X�p�b�`���[���Ă�
	Idle();

	// �Z�b�g�^�C�}�[�@1.5�b��ɒT��
	World = GEngine->GameViewport->GetWorld();
	FTimerHandle _TimerHandle;
	World->GetTimerManager().SetTimer(_TimerHandle, this, &AEnemyPawn::Hunt, 1.0f, false,1.5f);
}

void AEnemyPawn::OnMoving()
{
	GetController();

	switch (State)
	{
	case EEnemyState::Idle:
		
		break;
	case EEnemyState::Hunt:

		break;
	case EEnemyState::RunAway:

		break;

	}
}


// �v���C���[�ƕʃA�N�^�[�̓����蔻��
void AEnemyPawn::OnComponentHit(AActor* PlayerActor, AActor* OtherActor)
{

}
