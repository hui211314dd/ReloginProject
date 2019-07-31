// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "ReLoginProjectGameMode.h"
#include "ReLoginProjectCharacter.h"
#include "MyPlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "EngineUtils.h"

AReLoginProjectGameMode::AReLoginProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

    PlayerControllerClass = AMyPlayerController::StaticClass();
}

APawn* AReLoginProjectGameMode::SpawnDefaultPawnFor_Implementation(AController* NewPlayer, AActor* StartSpot)
{
    UWorld* MyWorld = GetWorld();
    if (MyWorld)
    {
        for (TActorIterator<APawn> It(MyWorld); It; ++It)
        {
            return *It;
        }
    }

    // Don't allow pawn to be spawned with any pitch or roll
    FRotator StartRotation(ForceInit);
    StartRotation.Yaw = StartSpot->GetActorRotation().Yaw;
    FVector StartLocation = StartSpot->GetActorLocation();

    FTransform Transform = FTransform(StartRotation, StartLocation);
    return SpawnDefaultPawnAtTransform(NewPlayer, Transform);
}
