// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPawn.h"


void AEnemyPawn::Hunt()
{
	// �T��
	State = EEnemyState::Default;

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
