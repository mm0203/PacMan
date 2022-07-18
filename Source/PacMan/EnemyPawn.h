// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyPawn.generated.h"

// �G�̏��
UENUM(BlueprintType)
enum class EEnemyState : uint8
{
	Default, // �T��
	Idle	 // �ҋ@
};

// ���I�}���`�L���X�g�f���Q�[�g(�C�x���g�f�B�X�p�b�`���[)�錾 (�^,������)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnemyStateChangedEvent, EEnemyState, NewState);

UCLASS()
class PACMAN_API AEnemyPawn : public APawn
{
	GENERATED_BODY()

public:
	// �G�̏��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EEnemyState State = EEnemyState::Default;

	// �T��
	UFUNCTION(BlueprintCallable)
		void Hunt();

	// �ҋ@
	UFUNCTION(BlueprintCallable)
		void Idle();

	// ��ԕω�(�C�x���g�f�B�X�p�b�`���[)
	FEnemyStateChangedEvent& OnStateChanged() { return StateChangedEvent; }

private:

	// ���I�}���`�L���X�g�f���Q�[�g(�C�x���g�f�B�X�p�b�`���[)�̒�`
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FEnemyStateChangedEvent StateChangedEvent;

};
