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
	FTimerHandle _TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(_TimerHandle, this, &AEnemyPawn::Hunt, 1.0f, false,1.5f);
}

// ��Ԃɂ���čs���ω�
void AEnemyPawn::UpdateMovement()
{
	// �G�̃R���g���[���擾
	AController* MyController = GetController();
	// AI�擾
	AAIController* MyAIController = UAIBlueprintHelperLibrary::GetAIController(MyController);
	// �v���C���[�|�[���擾
	APacmanPawn* MyCharacter = Cast<APacmanPawn>(UGameplayStatics::GetPlayerPawn(this, 0));
	// �����ʒu
	FVector StartLocation = FVector(0, 100, 0);

	switch (State)
	{
	case EEnemyState::Idle:		// �ҋ@
		MyAIController->StopMovement();
		break;
	case EEnemyState::Hunt:		// �T��
		MyAIController->MoveToActor(MyCharacter);
		break;
	case EEnemyState::RunAway:	// ������
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(MyAIController, StartLocation);
		break;

	}
}

// �v���C���[�ƕʃA�N�^�[�̓����蔻��
void AEnemyPawn::OnComponentHit(AActor* PlayerActor, AActor* OtherActor)
{

}
