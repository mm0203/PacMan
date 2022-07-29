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

	// ���x����ɂ���a��S�ė�
    for (TActorIterator<AFoodie> it(GetWorld()); it; ++it)
    {
        FoodieCounter++;
    }

    // �a�̐��\��
    GetFoodieCount(FoodieCounter);
}

void AMyLevelScript::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // �S���̉a���擾�����烌�x���J��
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
