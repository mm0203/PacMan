// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPawn.h"
#include "Kismet/KismetSystemLibrary.h" //追加

AEnemyPawn::AEnemyPawn()
{

}

void AEnemyPawn::Tick(float DeltaTime)
{
}

// 待機
void AEnemyPawn::Idle()
{
	State = EEnemyState::Idle;
	StateChangedEvent.Broadcast(State);
}

// 探索
void AEnemyPawn::Hunt()
{
	State = EEnemyState::Hunt;
	StateChangedEvent.Broadcast(State);
}

// 逃げる
void AEnemyPawn::RunAway()
{
	State = EEnemyState::RunAway;
	StateChangedEvent.Broadcast(State);
}

// 待機→探索
void AEnemyPawn::StartMoving()
{
	// 待機のディスパッチャーを呼ぶ
	Idle();

	// セットタイマー　1.5秒後に探索
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


// プレイヤーと別アクターの当たり判定
void AEnemyPawn::OnComponentHit(AActor* PlayerActor, AActor* OtherActor)
{

}
