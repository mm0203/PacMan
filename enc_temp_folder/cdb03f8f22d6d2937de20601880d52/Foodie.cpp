// Fill out your copyright notice in the Description page of Project Settings.


#include "Foodie.h"

#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "MyLevelScript.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h"

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

	int& FoodieCnt = AMyLevelScript::GetFoodieCounter();

	FoodieCnt--;

	FString aa = UKismetStringLibrary::Conv_IntToString(FoodieCnt);
	UKismetSystemLibrary::PrintString(
		this,
		aa,
		true,
		true,
		FColor::Cyan,
		2.0f);
}

