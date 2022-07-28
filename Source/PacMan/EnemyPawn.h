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

	// ��ԕω�(�C�x���g�f�B�X�p�b�`���[)
	EEnemyState& GetState() { return State; }

	// �ҋ@
	UFUNCTION(BlueprintCallable)
		void Idle();
	// �T��
	UFUNCTION(BlueprintCallable)
		void Hunt();
	// ������
	UFUNCTION(BlueprintCallable)
		void RunAway();
	// �ҋ@���T��
	UFUNCTION(BlueprintCallable)
		void StartMoving();

	UFUNCTION(BlueprintCallable)
		void OnMoving();

	// ��ԕω�(�C�x���g�f�B�X�p�b�`���[)
	FEnemyStateChangedEvent& OnStateChanged() { return StateChangedEvent; }

protected:
	UPROPERTY()
		UWorld* World;
private:

	// ��ԕω����̃C�x���g�f�B�X�p�b�`���[
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FEnemyStateChangedEvent StateChangedEvent;

	// �����蔻��
	UFUNCTION()
		void OnComponentHit(AActor* PlayerActor, AActor* OtherActor);


};
