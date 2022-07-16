// Fill out your copyright notice in the Description page of Project Settings.


#include "PacmanPawn.h"

#include "Foodie.h"

// Sets default values
APacmanPawn::APacmanPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APacmanPawn::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &APacmanPawn::OnOverlapBegin);
	
}

// Called every frame
void APacmanPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// �������ԂȂ�
	if (!Frozen)
	{
		// �w�肵�������ɓ�����
		AddMovementInput(GetActorForwardVector());
	}
}

// �L�[���͂̌Ăяo��
void APacmanPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// �v���C���[�̌�����ς���
void APacmanPawn::SetDirection(const FVector Direction)
{
	if (Direction == FVector::UpVector) 		// ��
	{
		SetActorRotation(FRotator(0, 270, 0));
	}
	else if (Direction == FVector::DownVector)	// ��
	{
		SetActorRotation(FRotator(0, 90, 0));
	}
	else if (Direction == FVector::RightVector)	// �E
	{
		SetActorRotation(FRotator(0, 0, 0));
	}
	else if (Direction == FVector::LeftVector)	// ��
	{
		SetActorRotation(FRotator(0, 180, 180));
	}
}

void APacmanPawn::OnOverlapBegin(AActor * PlayerActor, AActor * OtherActor)
{

	if (OtherActor->ActorHasTag("Foodie.Regular")) 
	{
	
		Cast<AFoodie>(OtherActor)->Consume();

	}

	if (OtherActor->ActorHasTag("Foodie.PowerUp"))
	{

		Cast<AFoodie>(OtherActor)->Consume();

	}


}
