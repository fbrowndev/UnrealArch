// Fill out your copyright notice in the Description page of Project Settings.


#include "Sub.h"

// Sets default values
ASub::ASub()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SubMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SubMesh"));
	SetRootComponent(SubMesh);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(SubMesh);
}

// Called when the game starts or when spawned
void ASub::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Display, TEXT("The Impulse strength is: %f"), ImpulseStrength);
	UE_LOG(LogTemp, Display, TEXT("The torque strength is: %f"), TorqueStrength);
}

// Called every frame
void ASub::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASub::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

