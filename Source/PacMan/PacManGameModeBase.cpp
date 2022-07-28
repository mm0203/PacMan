// Fill out your copyright notice in the Description page of Project Settings.


#include "PacManGameModeBase.h"
#include "Kismet/KismetSystemLibrary.h" //追加
#include "Particles/Emitter.h"
#include "Foodie.h"
#include "EngineUtils.h"
#include "Kismet/KismetSystemLibrary.h" //追加
#include "Kismet/KismetStringLibrary.h" // 追加

APacManGameModeBase::APacManGameModeBase()
{

}

void APacManGameModeBase::GetFoodieCount()
{
    // TActorIterator で AActor 派生の任意のユーザー定義型のオブジェクトを列挙
	// AFoodie は列挙したい AActor 派生のユーザー定義型
	// GetWorld() は AActor のメンバー関数
    auto counter = 0;

    for (TActorIterator< AFoodie > i(GetWorld()); i; ++i)
    {
        counter++;
    }

    FString aa = UKismetStringLibrary::Conv_IntToString(counter);
    UKismetSystemLibrary::PrintString(
        this, 
        aa, 
        true, 
        true, 
        FColor::Cyan,
        2.0f);
}