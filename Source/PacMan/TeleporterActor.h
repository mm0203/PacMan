// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TeleporterActor.generated.h"

class USoundCue;

UCLASS()
class PACMAN_API ATeleporterActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATeleporterActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void TeleportToTarget(AActor* Actor);

	UPROPERTY(EditAnywhere)
		ATeleporterActor* Target = nullptr;

	// �e���|�[�g���̉�
	UPROPERTY(EditAnywhere)
		USoundCue* TeleportSound;

	// �����蔻��
	UFUNCTION()
		void OnOverlapBegin(AActor* TeleporterActor, AActor* OtherActor);


};
