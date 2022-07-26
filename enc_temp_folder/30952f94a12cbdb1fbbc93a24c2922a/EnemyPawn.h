// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyPawn.generated.h"

// �G�̏��
UENUM(BlueprintType)
enum class EEnemyState : uint8
{
	Hunt,	 // �T��
	Idle,	 // �ҋ@
	RunAway	 // ������
};

// ��ԕω����̃C�x���g�f�B�X�p�b�`���[�錾�p�}�N���@����:���
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnemyStateChangedEvent, EEnemyState, NewState);

UCLASS()
class PACMAN_API AEnemyPawn : public APawn
{
	GENERATED_BODY()

public:

	AEnemyPawn();

	virtual void Tick(float DeltaTime) override;

	// �G�̏��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EEnemyState State = EEnemyState::Hunt;

	// �T��
	UFUNCTION(BlueprintCallable)
		void Hunt();
	// �ҋ@
	UFUNCTION(BlueprintCallable)
		void Idle();
	// ������
	UFUNCTION(BlueprintCallable)
		void RunAway();

	// ��ԕω�(�C�x���g�f�B�X�p�b�`���[)
	FEnemyStateChangedEvent& OnStateChanged() { return StateChangedEvent; }

private:

	// ��ԕω����̃C�x���g�f�B�X�p�b�`���[
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FEnemyStateChangedEvent StateChangedEvent;

	// �����蔻��
	UFUNCTION()
		void OnComponentHit(AActor* PlayerActor, AActor* OtherActor);


};
