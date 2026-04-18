// Copyright 2026 DME GAMES

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "US_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class UNREALSHADOWS_LOTL_API AUS_GameMode : public AGameModeBase
{
	GENERATED_BODY()

	AUS_GameMode();

public:
	UFUNCTION(BlueprintCallable, Category = "Minions")
	void AlertMinions(class AActor* AlertInstigator, const FVector& Location, float Radius);

	
};
