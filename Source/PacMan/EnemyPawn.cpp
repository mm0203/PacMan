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
	// 探索
	State = EEnemyState::Hunt;

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

void AEnemyPawn::RunAway()
{
	// 逃げる
	State = EEnemyState::RunAway;

	// イベントディスパッチャーの呼び出し
	StateChangedEvent.Broadcast(State);
}

// プレイヤーと別アクターの当たり判定
void AEnemyPawn::OnComponentHit(AActor* PlayerActor, AActor* OtherActor)
{
	//// 通常の餌
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
