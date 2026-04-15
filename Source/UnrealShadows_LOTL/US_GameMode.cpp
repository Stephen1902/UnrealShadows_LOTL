// Copyright 2026 DME GAMES

#include "US_GameMode.h"
#include "US_GameStateBase.h"
#include "US_PlayerController.h"
#include "US_PlayerState.h"
#include "US_PlayerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUS_GameMode::AUS_GameMode()
{
	GameStateClass = AUS_GameStateBase::StaticClass();
	PlayerStateClass = AUS_PlayerState::StaticClass();
	PlayerControllerClass = AUS_PlayerController::StaticClass();
	static ConstructorHelpers::FClassFinder<AUS_PlayerCharacter> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_Character"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
