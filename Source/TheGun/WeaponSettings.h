// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SaveGame.h"
#include "WeaponSettings.generated.h"

/**
 * 
 */
UCLASS()
class THEGUN_API UWeaponSettings : public USaveGame
{
	GENERATED_BODY()
		

public:
	UWeaponSettings();
	UPROPERTY(BlueprintReadWrite, Category = Basic)
	FString WeaponSlotAProjectile;
	UPROPERTY(BlueprintReadWrite, Category = Basic)
	FString WeaponSlotAMuzzVel;
	UPROPERTY(BlueprintReadWrite, Category = Basic)
	FString WeaponSlotASpeed;

	UPROPERTY(BlueprintReadWrite, Category = Basic)
		FString WeaponSlotBProjectile;
	UPROPERTY(BlueprintReadWrite, Category = Basic)
		FString WeaponSlotBMuzzVel;
	UPROPERTY(BlueprintReadWrite, Category = Basic)
		FString WeaponSlotBSpeed;

	UPROPERTY(BlueprintReadWrite, Category = Basic)
		FString WeaponZoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Basic)
		int32 UserIndex;
	UPROPERTY(BlueprintReadOnly, Category = Basic)
		FString WeaponSaveSlot;

};
