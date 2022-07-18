// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPawn.h"


void AEnemyPawn::Hunt()
{
	// 探索
	State = EEnemyState::Default;

	// イベントディスパッチャーの呼び出し
	StateChangedEvent.Broadcast(State);
}

void AEnemyPawn::Idle()
{
	// 待機
	State = EEnemyState::Idle;

	// イベントディスパッチャーの呼び出し
	StateChangedEvent.Broadcast(State);
}
