// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputLibrary.h"
#include "Sub.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class UNREALARCH_API ASub : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASub();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sub | Movement")
	float ImpulseStrength = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sub | Movement")
	float TorqueStrength = 5.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sub | Graphics")
	UStaticMeshComponent* SubMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sub | Input")
	UInputMappingContext* ShipMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sub | Input")
	UInputAction* PropelUpAction;

	void PropelUp(const FInputActionValue& Value);

private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

};
