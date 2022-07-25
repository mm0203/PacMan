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
	// 探索
	State = EEnemyState::Hunt;

	// イベントディスパッチャーの呼び出し
	StateChangedEvent.Broadcast(State);
}

void AEnemyPawn::Idle()
{
	// 待機
	State = EEnemyState::Idle;

	//StateChangedEvent.AddDynamic(this, OnHitAttack());

	// イベントディスパッチャーの呼び出し
	StateChangedEvent.Broadcast(State);
}

void AEnemyPawn::RunAway()
{
	
}

//void AEnemyPawn::TestFunc()
//{
//	
//}
