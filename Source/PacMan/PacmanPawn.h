// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PacmanPawn.generated.h"

UCLASS()
class PACMAN_API APacmanPawn : public APawn
{
	GENERATED_BODY()

public:
	APacmanPawn();

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

public:

	// �ړ��������Z�b�g
	void SetDirection(const FVector Direction);

	// �~�܂��Ă��邩
	bool IsFrozen() { return Frozen; }

	// �����邩�~�܂��Ă��邩��ݒ�
	UFUNCTION(BlueprintCallable)
		void SetFrozen(bool Value) { Frozen = Value; }

private:

	// �����蔻��
	UFUNCTION()
		void OnOverlapBegin(AActor* PlayerActor, AActor* OtherActor);
};
