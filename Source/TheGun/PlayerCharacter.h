// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS(Blueprintable)
class THEGUN_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
protected:
	//forward and back movement
	UFUNCTION()
		void MoveForward(float Val);
	//strafing movement
	UFUNCTION()
		void MoveRight(float Val);
	//tells engine jump is pressed
	UFUNCTION()
		void OnJumpPressed();
	//tells engine jump is released
	UFUNCTION()
		void OnJumpReleased();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Weapon, meta = (AllowPrivateAccess = "True"))
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Weapon, meta = (AllowPrivateAccess = "True"))
	class APlayerGun* Gun;

	UFUNCTION(Category = "Shoot", BlueprintImplementableEvent, BlueprintCallable)
	void OnShootPressedLeft();
	UFUNCTION(Category = "Shoot", BlueprintImplementableEvent, BlueprintCallable)
	void OnShootReleasedLeft();

	UFUNCTION(Category = "Shoot", BlueprintImplementableEvent, BlueprintCallable)
		void OnShootPressedRight();
	UFUNCTION(Category = "Shoot", BlueprintImplementableEvent, BlueprintCallable)
		void OnShootReleasedRight();
	UFUNCTION(Category = "Shoot", BlueprintImplementableEvent, BlueprintCallable)
		void LeftReload();
	UFUNCTION(Category = "Shoot", BlueprintImplementableEvent, BlueprintCallable)
		void RightReload();
	UFUNCTION()
	void LimitRotation();
	UFUNCTION(Category = "Shoot", BlueprintImplementableEvent, BlueprintCallable)
	void PauseGame();


	UFUNCTION(Category = "Death", BlueprintImplementableEvent, BlueprintCallable)
	void Fell();

	virtual void FellOutOfWorld(const class UDamageType& dmgType);
};
