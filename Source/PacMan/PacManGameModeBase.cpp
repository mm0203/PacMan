// Fill out your copyright notice in the Description page of Project Settings.


#include "PacManGameModeBase.h"
#include "Kismet/KismetSystemLibrary.h" //�ǉ�
#include "Particles/Emitter.h"
#include "Foodie.h"
#include "EngineUtils.h"
#include "Kismet/KismetSystemLibrary.h" //�ǉ�
#include "Kismet/KismetStringLibrary.h" // �ǉ�

APacManGameModeBase::APacManGameModeBase()
{

}

void APacManGameModeBase::GetFoodieCount()
{
    // TActorIterator �� AActor �h���̔C�ӂ̃��[�U�[��`�^�̃I�u�W�F�N�g���
	// AFoodie �͗񋓂����� AActor �h���̃��[�U�[��`�^
	// GetWorld() �� AActor �̃����o�[�֐�
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