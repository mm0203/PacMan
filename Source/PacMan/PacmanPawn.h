// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PacmanPawn.generated.h"


// �G�̏��
UENUM(BlueprintType)
enum class EPacManState : uint8
{
	Regular,	// �ʏ�
	PowerUp		// �p���[�A�b�v
};

// �p���[�A�b�v���̃C�x���g�f�B�X�p�b�`���[�錾�p�}�N��
DECLARE_MULTICAST_DELEGATE(FIsPowerUpEventDispatcher);

UCLASS()

class PACMAN_API APacmanPawn : public APawn
{
	GENERATED_BODY()

public:
	APacmanPawn();

	// �G�̏��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EPacManState State = EPacManState::Regular;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// ����̓��͐ݒ�
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:

	// �����邩�ǂ���
	UPROPERTY(BlueprintReadOnly)
		bool Frozen = true;

	// �p���[�A�b�v�a���擾
	UPROPERTY(BlueprintReadOnly)
		bool PowerUp = false;

public:

	// �ړ��������Z�b�g
	void SetDirection(const FVector Direction);

	// �~�܂��Ă��邩
	bool IsFrozen() { return Frozen; }

	// �p���[�A�b�v���ǂ���
	UFUNCTION(BlueprintCallable)
	bool IsPowerUp() { return PowerUp; }

	// �����邩�~�܂��Ă��邩��ݒ�
	UFUNCTION(BlueprintCallable)
		void SetPowerUp(bool Value) { PowerUp = Value; }

	// �����邩�~�܂��Ă��邩��ݒ�
	UFUNCTION(BlueprintCallable)
		void SetFrozen(bool Value) { Frozen = Value; }

private:

	// �����蔻��
	UFUNCTION()
		void OnOverlapBegin(AActor* PlayerActor, AActor* OtherActor);

	// �U���������������̃C�x���g�f�B�X�p�b�`���[
	FIsPowerUpEventDispatcher OnHitEventDispatcher;
};
