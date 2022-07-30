// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPawn.h"
#include "PacmanPawn.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

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
	FTimerHandle _TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(_TimerHandle, this, &AEnemyPawn::Hunt, 1.0f, false,1.5f);
}

// 状態によって行動変化
void AEnemyPawn::UpdateMovement()
{
	// 敵のコントローラ取得
	AController* MyController = GetController();
	// AI取得
	AAIController* MyAIController = UAIBlueprintHelperLibrary::GetAIController(MyController);
	// プレイヤーポーン取得
	APacmanPawn* MyCharacter = Cast<APacmanPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
	// 初期位置
	FVector StartLocation = FVector(0, 100, 0);

	switch (State)
	{
	case EEnemyState::Idle:		// 待機
		MyAIController->StopMovement();
		break;
	case EEnemyState::Hunt:		// 探索
		MyAIController->MoveToActor(MyCharacter);
		break;
	case EEnemyState::RunAway:	// 逃げる
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(MyAIController, StartLocation);
		break;

	}
}

// プレイヤーと別アクターの当たり判定
void AEnemyPawn::OnComponentHit(AActor* PlayerActor, AActor* OtherActor)
{

}
