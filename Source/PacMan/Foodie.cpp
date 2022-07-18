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
	// 音
	UGameplayStatics::PlaySound2D(this, ConsumptionSound);

	// イベントディスパッチャーの呼び出し
	FoodieEatenEvent.Broadcast(FoodieType);

	// 餌の削除
	Destroy();

}

