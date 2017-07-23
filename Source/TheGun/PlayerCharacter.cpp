#include "TheGun.h"
#include "PlayerCharacter.h"
#include "PlayerGun.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("WeaponArm"));
	SpringArm->AttachTo(RootComponent);
	SpringArm->bDoCollisionTest = false;
	SpringArm->bAbsoluteRotation = true;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->RelativeLocation = FVector(0, 0, 40);
	SpringArm->TargetArmLength = -100.0f;
	SpringArm->bEnableCameraLag = false;
	SpringArm->CameraLagSpeed = 3.0f;


	//Gun->AttachRootComponentTo(SpringArm, USpringArmComponent::SocketName);
	/*
	Weapon = NewNamedObject<UChildActorComponent>(this, TEXT("PlayerWeapon"));
	Weapon->SetChildActorClass(APlayerGun::StaticClass());
	Weapon->CreateChildActor();
	//Gun->RelativeLocation;
	Weapon->AttachTo(SpringArm, USpringArmComponent::SocketName);
	Weapon->ChildActorName = "Weapon";
	*/
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Player Character Loaded!"));
	}
	/*
	Gun = (APlayerGun*)GetWorld()->SpawnActor(APlayerGun::StaticClass());
	Gun->AttachRootComponentTo(SpringArm, USpringArmComponent::SocketName);
	*/
	LimitRotation();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	InputComponent->BindAxis("LookX", this, &APlayerCharacter::AddControllerYawInput);
	InputComponent->BindAxis("LookY", this, &APlayerCharacter::AddControllerPitchInput);
	InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::OnJumpPressed);
	InputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::OnJumpReleased);
	InputComponent->BindAction("ShootA", IE_Pressed, this, &APlayerCharacter::OnShootPressedLeft);
	InputComponent->BindAction("ShootA", IE_Released, this, &APlayerCharacter::OnShootReleasedLeft);
	InputComponent->BindAction("ShootB", IE_Pressed, this, &APlayerCharacter::OnShootPressedRight);
	InputComponent->BindAction("ShootB", IE_Released, this, &APlayerCharacter::OnShootReleasedRight);
	InputComponent->BindAction("ReloadA", IE_Pressed, this, &APlayerCharacter::LeftReload);
	InputComponent->BindAction("ReloadB", IE_Pressed, this, &APlayerCharacter::RightReload);
	InputComponent->BindAction("Pause", IE_Pressed, this, &APlayerCharacter::PauseGame);

}

//Called to move pawn forward
void APlayerCharacter::MoveForward(float Val)
{
	if ((Controller != NULL) && (Val != 0.0f))
	{
		//get pawn rotation
		FRotator Rotation = Controller->GetControlRotation();
		//make pitch 0 when on ground or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		//find out X direction and move
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Val);
	}
}

//Called to strafe pawn
void APlayerCharacter::MoveRight(float Val)
{
	if ((Controller != NULL) && (Val != 0.0f))
	{
		//get pawn rotation
		const FRotator Rotation = Controller->GetControlRotation();
		//get Y direction and move
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, Val);
	}
}

//called when jump is pressed
void APlayerCharacter::OnJumpPressed()
{
	bPressedJump = true;
}

//called when jump is released
void APlayerCharacter::OnJumpReleased()
{
	bPressedJump = false;
}

void APlayerCharacter::LimitRotation()
{
	
}

void APlayerCharacter::FellOutOfWorld(const class UDamageType& dmgType)
{
	//Super::FellOutOfWorld(dmgType);
	Fell();
}