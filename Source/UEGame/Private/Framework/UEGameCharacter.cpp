// Copyright Epic Games, Inc. All Rights Reserved.

#include "Framework/UEGameCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// AUEGameCharacter

AUEGameCharacter::AUEGameCharacter()
{
	
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

}

//////////////////////////////////////////////////////////////////////////
// Input

void AUEGameCharacter::NotifyControllerChanged()
{
	Super::NotifyControllerChanged();

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(MainContext, 0);
		}
	}
}

void AUEGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AUEGameCharacter::Move);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Ongoing, this, &AUEGameCharacter::Move);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &AUEGameCharacter::Move);
		// Dash
		EnhancedInputComponent->BindAction(DashAction, ETriggerEvent::Started, this, &AUEGameCharacter::Dash);

		// Shot
		EnhancedInputComponent->BindAction(ShotAction, ETriggerEvent::Triggered, this, &AUEGameCharacter::Shot);

		// Menu
		EnhancedInputComponent->BindAction(ESCMenuAction, ETriggerEvent::Started, this, &AUEGameCharacter::ESC);

		// Parring
		EnhancedInputComponent->BindAction(ParryingAction, ETriggerEvent::Started, this, &AUEGameCharacter::Parrying);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AUEGameCharacter::Move(const FInputActionValue& Value)
{
	AxisValue = Value.Get<float>();

}

void AUEGameCharacter::Dash(const FInputActionValue& Value)
{
}

void AUEGameCharacter::Shot(const FInputActionValue& Value)
{
}

void AUEGameCharacter::ESC(const FInputActionValue& Value)
{
}

void AUEGameCharacter::Parrying(const FInputActionValue& Value)
{
}

