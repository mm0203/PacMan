// Fill out your copyright notice in the Description page of Project Settings.


#include "MyLevelScript.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"

int AMyLevelScript::FoodieCounter;

AMyLevelScript::AMyLevelScript()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AMyLevelScript::BeginPlay()
{
    Super::BeginPlay();

    FoodieCounter = 0;

	// ƒŒƒxƒ‹ã‚É‚ ‚é‰a‚ğ‘S‚Ä—ñ‹“
    for (TActorIterator<AFoodie> it(GetWorld()); it; ++it)
    {
        FoodieCounter++;
    }

    // ‰a‚Ì”•\¦
    GetFoodieCount(FoodieCounter);
}

void AMyLevelScript::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // ‘S•”‚Ì‰a‚ğæ“¾‚µ‚½‚çƒŒƒxƒ‹‘JˆÚ
    if (FoodieCounter <= 0)
    {
        //FTimerHandle _TimerHandle;
        //GetWorld()->GetTimerManager().SetTimer(_TimerHandle, this, &AEnemyPawn::Hunt, 1.0f, false, 1.5f);
        UGameplayStatics::OpenLevel(GetWorld(), LevelToLoad);
        UKismetSystemLibrary::PrintString(this,"LevelOpen");
    }
}

void AMyLevelScript::GetFoodieCount(int num)
{
    FString cnt = UKismetStringLibrary::Conv_IntToString(num);
    UKismetSystemLibrary::PrintString(this, cnt);
}
