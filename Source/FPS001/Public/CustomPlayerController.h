// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CustomPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FPS001_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void OnUnPossess() override;

protected:
	UPROPERTY(EditAnywhere)
	float RespawnDelay = 1.0f;

	virtual void BeginPlay() override;	
	void Respawn();

private:
	FTimerHandle Respawn_TimerHandle;
	
	UPROPERTY()
	UWorld* WorldInstance;

	TSubclassOf<APawn> PlayerPawnClass;
};
