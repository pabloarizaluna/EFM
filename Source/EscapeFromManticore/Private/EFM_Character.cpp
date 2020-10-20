// Fill out your copyright notice in the Description page of Project Settings.

//#include "EFM_Character.h"
#include "Public/EFM_Character.h"

#include "Components/InputComponent.h"

// Sets default values
AEFM_Character::AEFM_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEFM_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEFM_Character::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector() * value);
}

void AEFM_Character::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector() * value);
}

void AEFM_Character::AddControllerPitchInput(float value)
{
	Super::AddControllerPitchInput(bIsLookInversion? -value : value);
}

// Called every frame
void AEFM_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEFM_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AEFM_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AEFM_Character::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &AEFM_Character::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRight", this, &ACharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
}

