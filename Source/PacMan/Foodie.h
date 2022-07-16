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

// �Ȃ񂩃f���Q�[�g������ۂ��@�悭�킩���
// �m�[�h�I�����ɌĂԃf���Q�[�g�炵���H
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
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Consume();

	UPROPERTY(EditAnywhere)
		EFoodieType FoodieType = EFoodieType::Regular;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FFoodieEatenEvent FoodieEatenEvent;

private:

	UPROPERTY(EditAnywhere)
		USoundCue* ConsumptionSound;


};
