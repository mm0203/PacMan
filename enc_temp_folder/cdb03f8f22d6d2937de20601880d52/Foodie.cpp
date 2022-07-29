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

	// 音
	UGameplayStatics::PlaySound2D(this, ConsumptionSound);

	// イベントディスパッチャーの呼び出し
	FoodieEatenEvent.Broadcast(FoodieType);

	// 餌の削除
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

