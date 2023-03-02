// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomPlayerController.h"
#include "PlayerStarter.h"
#include "GameFramework/GameModeBase.h"



void ACustomPlayerController::OnUnPossess()
{
	Super::OnUnPossess();

	UE_LOG(LogTemp, Warning, TEXT("OnUnposses"));

	if (IsValid(WorldInstance))
	{
		WorldInstance->GetTimerManager().ClearTimer(Respawn_TimerHandle);
		WorldInstance->GetTimerManager().SetTimer(Respawn_TimerHandle, this, &ThisClass::Respawn, RespawnDelay);
	}
}

void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("BeginPlay Custom player"));

	WorldInstance = GetWorld();
	APawn* PlayerPawn = GetPawn();
	if (IsValid(PlayerPawn))
	{
		PlayerPawnClass = PlayerPawn->GetClass();
		UE_LOG(LogTemp, Warning, TEXT("IsValid(PlayerPawn)"));
	}
}

void ACustomPlayerController::Respawn()
{
	UE_LOG(LogTemp, Warning, TEXT("Respawn Custom player"));

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), PlayerStarter::StaticClass(), FoundActors);

	APawn* DefaultPawn = WorldInstance->SpawnActor<APawn>(PlayerPawnClass, SpawnLocation, FRotator::ZeroRotator);
	
	if (IsValid(DefaultPawn))
	{
		UE_LOG(LogTemp, Warning, TEXT("ACustomPlayerController Default pawn is valid"));
		Possess(DefaultPawn);
	}
}