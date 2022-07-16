// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PacmanPawn.generated.h"

UCLASS()
class PACMAN_API APacmanPawn : public APawn
{
	GENERATED_BODY()

public:
	APacmanPawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// ‘€ì‚Ì“ü—Íİ’è
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:

	// “®‚¯‚é‚©‚Ç‚¤‚©
	UPROPERTY(BlueprintReadOnly)
	bool Frozen = true;

public:

	// ˆÚ“®•ûŒü‚ğƒZƒbƒg
	void SetDirection(const FVector Direction);

	// ~‚Ü‚Á‚Ä‚¢‚é‚©
	bool IsFrozen() { return Frozen; }

	// “®‚¯‚é‚©~‚Ü‚Á‚Ä‚¢‚é‚©‚ğİ’è
	UFUNCTION(BlueprintCallable)
		void SetFrozen(bool Value) { Frozen = Value; }

private:

	// “–‚½‚è”»’è
	UFUNCTION()
		void OnOverlapBegin(AActor* PlayerActor, AActor* OtherActor);
};
