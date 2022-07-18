// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyPawn.generated.h"

// �G�̏��
UENUM(BlueprintType)
enum class EEnemyState : uint8
{
	Default, // �Ȃ�
	Idle	 // �ҋ@
};
// ���I�}���`�L���X�g�f���Q�[�g(�C�x���g�f�B�X�p�b�`���[)�錾 (�^,������)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnemyStateChangedEvent, EEnemyState, NewState);

UCLASS()
class PACMAN_API AEnemyPawn : public APawn
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EEnemyState State = EEnemyState::Default;

	UFUNCTION(BlueprintCallable)
		void Hunt();

	UFUNCTION(BlueprintCallable)
		void Idle();

	FEnemyStateChangedEvent& OnStateChanged() { return StateChangedEvent; }

private:

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FEnemyStateChangedEvent StateChangedEvent;

};
