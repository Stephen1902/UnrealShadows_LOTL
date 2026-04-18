// Copyright 2026 DME GAMES

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "US_PlayerCharacter.generated.h"

UCLASS()
class UNREALSHADOWS_LOTL_API AUS_PlayerCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UCameraComponent> FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputMappingContext> DefaultMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> MoveAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> LookAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> SprintAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> InteractAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stealth", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UPawnNoiseEmitterComponent> NoiseEmitter;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UUS_WeaponProjectileComponent> Weapon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Data", meta = (AllowPrivateAccess = "true"))
	class UDataTable* CharacterDataTable;
	
	struct FUS_CharacterStats* CharacterStats;
	
public:
	// Sets default values for this character's properties
	AUS_PlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Move(const struct FInputActionValue& Value);
	
	void Look(const FInputActionValue& Value);

	UFUNCTION(Server, Reliable)
	void SprintStart_Server();
	
	UFUNCTION(Server, Reliable)
	void SprintEnd_Server();
	
	void SprintStart(const FInputActionValue& Value);
	void SprintEnd(const FInputActionValue& Value);
	
	void Interact(const FInputActionValue& Value);

	UFUNCTION(Server, Reliable)
	void Interact_Server();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void UpdateCharacterStats(int32 CharacterLevel);
	
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	FORCEINLINE FUS_CharacterStats* GetCharacterStats() const { return CharacterStats; }
	FORCEINLINE UUS_WeaponProjectileComponent* GetWeapon() const { return Weapon; }
	
private:
	UPROPERTY()
	AActor* InteractableActor;
};
