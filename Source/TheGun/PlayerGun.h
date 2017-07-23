// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PlayerGun.generated.h"

UCLASS(Blueprintable)
class THEGUN_API APlayerGun : public AActor
{
	GENERATED_BODY()
private:
	UParticleSystemComponent *OurParticleSystem;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Gun, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* GunModel;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gun, meta = (AllowPrivateAccess = "true"))
	bool triggerDownA;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Gun, meta = (AllowPrivateAccess = "true"))
	bool triggerDownB;
public:
	// Sets default values for this actor's properties
	APlayerGun();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	
	UFUNCTION(BlueprintCallable, Category = "Gun")
	void PullTrigger(bool Left);

	UFUNCTION(BlueprintCallable, Category = "Gun")
	void ReleaseTrigger(bool Left);

};
