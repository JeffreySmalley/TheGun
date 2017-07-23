// Fill out your copyright notice in the Description page of Project Settings.

#include "TheGun.h"
#include "PlayerGun.h"
#include "WeaponSettings.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerGun::APlayerGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> GunMesh(TEXT("/Game/Weapon/TheGun/TheGunModel.TheGunModel"));

	GunModel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gun"));
	GunModel->SetStaticMesh(GunMesh.Object);
	GunModel->SetSimulatePhysics(false);
	GunModel->SetNotifyRigidBodyCollision(false);
	RootComponent = GunModel;
}

// Called when the game starts or when spawned
void APlayerGun::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APlayerGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerGun::PullTrigger(bool Left)
{
	if (Left)
		triggerDownA = true;
	else
		triggerDownB = true;
}
void APlayerGun::ReleaseTrigger(bool Left)
{
	if (Left)
		triggerDownA = false;
	else
		triggerDownB = false;
}
