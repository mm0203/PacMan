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

    if (FoodieCounter <= 185)
    {
        FLatentActionInfo LatentInfo;

        UGameplayStatics::LoadStreamLevel(
            this,
            LevelToLoad,
            false,
            false,
            LatentInfo);

        UKismetSystemLibrary::PrintString(
            this,
            "Levelopen",
            true,
            true,
            FColor::Cyan,
            2.0f);
    }
}

void AMyLevelScript::GetFoodieCount(int num)
{
    FString aa = UKismetStringLibrary::Conv_IntToString(num);
    UKismetSystemLibrary::PrintString(
        this,
        aa,
        true,
        true,
        FColor::Cyan,
        2.0f);
}
