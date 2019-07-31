// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ReLoginProjectGameMode.generated.h"

UCLASS(minimalapi)
class AReLoginProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AReLoginProjectGameMode();

protected:
    virtual APawn* SpawnDefaultPawnFor_Implementation(AController* NewPlayer, AActor* StartSpot) override;
};



