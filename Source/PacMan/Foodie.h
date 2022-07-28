// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Foodie.generated.h"

// �O���錾
class USoundCue;

// �a�̎��
UENUM(BlueprintType)
enum class EFoodieType : uint8
{
	Regular,	// �ʏ�
	PowerUp		// �p���[�A�b�v
};

// ���I�}���`�L���X�g�f���Q�[�g(�C�x���g�f�B�X�p�b�`���[)�錾 (�^,������)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFoodieEatenEvent, EFoodieType, FoodieType);

UCLASS()
class PACMAN_API AFoodie : public AActor
{
	GENERATED_BODY()
	
public:	
	AFoodie();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// �a�̊l��
	void Consume();

	// �a�̃^�C�v
	UPROPERTY(EditAnywhere)
		EFoodieType FoodieType = EFoodieType::Regular;

	// ���I�}���`�L���X�g�f���Q�[�g(�C�x���g�f�B�X�p�b�`���[)�̒�`
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FFoodieEatenEvent FoodieEatenEvent;

private:

	// �a�擾���̉�
	UPROPERTY(EditAnywhere)
		USoundCue* ConsumptionSound;

};
