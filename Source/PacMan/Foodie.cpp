// Fill out your copyright notice in the Description page of Project Settings.


#include "Foodie.h"

#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

AFoodie::AFoodie()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFoodie::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFoodie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFoodie::Consume()
{
	// ��
	UGameplayStatics::PlaySound2D(this, ConsumptionSound);

	// �C�x���g�f�B�X�p�b�`���[�̌Ăяo��
	FoodieEatenEvent.Broadcast(FoodieType);

	// �a�̍폜
	Destroy();

}

