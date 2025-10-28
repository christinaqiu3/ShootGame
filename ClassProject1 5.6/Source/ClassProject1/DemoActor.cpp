// Fill out your copyright notice in the Description page of Project Settings.
#include "DemoActor.h"
#include "GameFramework/Actor.h"
//#include "GameFramework/UCharacterMovementComponent.h"


// Sets default values
ADemoActor::ADemoActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
}

// Called when the game starts or when spawned
void ADemoActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADemoActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	PullInPlayer();
}

void ADemoActor::PullInPlayer() {
	AActor* Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	FVector PlayerLocation = Player->GetActorLocation();

	bool IsInRange = (PlayerLocation - GetActorLocation()).Length() < 600.0f;
	if (IsInRange) {
		//UCharacterMovementComponent* Movement = Player->FindComponentByClass<UCharacterMovementComponent>();
		//Movement->AddImpulse({ 0.f, 0.f, 20000.f });
	}
}

int ADemoActor::SillyFunction(int a, int b) {
	return a + b;
}