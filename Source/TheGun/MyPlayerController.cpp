// Fill out your copyright notice in the Description page of Project Settings.

#include "TheGun.h"
#include "MyPlayerController.h"




void AMyPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	ClampRotation();
}

void AMyPlayerController::ClampRotation()
{
	FRotator tempRoation = GetControlRotation();

	if (tempRoation.Pitch > 45 && tempRoation.Pitch < 300)
	{
		tempRoation.Pitch = 45;
	}
	if (tempRoation.Pitch > 50 && tempRoation.Pitch < 315)
	{
		tempRoation.Pitch = 315;
	}
	SetControlRotation(tempRoation);
	
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::FromInt(tempRoation.Pitch));

}