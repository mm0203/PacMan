// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPawn.h"

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

	//StateChangedEvent.AddDynamic(this, OnHitAttack());

	// �C�x���g�f�B�X�p�b�`���[�̌Ăяo��
	StateChangedEvent.Broadcast(State);
}

void AEnemyPawn::RunAway()
{
	
}

//void AEnemyPawn::TestFunc()
//{
//	
//}
