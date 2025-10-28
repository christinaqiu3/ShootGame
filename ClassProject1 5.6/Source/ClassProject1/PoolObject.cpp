// Fill out your copyright notice in the Description page of Project Settings.


#include "PoolObject.h"

// Sets default values
APoolObject::APoolObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APoolObject::BeginPlay()
{
	Super::BeginPlay();

	if(!PooledObjectClass) 
	{
		UE_LOG(LogTemp, Warning, TEXT("PooledObjectClass is not set in PoolObject"));
		return;
	}
	
	for (int32 i = 0; i < PoolSize; ++i)
	{
		AActor* PooledActor = GetWorld()->SpawnActor<AActor>(PooledObjectClass, FVector::ZeroVector, FRotator::ZeroRotator);
		if (PooledActor)
		{
			PooledActor->SetActorHiddenInGame(true);
			PooledActor->SetActorEnableCollision(false);
			Actors.Add(std::make_pair(PooledActor, false));
		}
	}
}

AActor* APoolObject::AcquirePooledObject()
{
	for (auto& Pair : Actors)
	{
		if (!Pair.second) // If not in use
		{
			Pair.second = true; // Mark as in use
			Pair.first->SetActorHiddenInGame(false);
			Pair.first->SetActorEnableCollision(true);
			return Pair.first;
		}
	}
	
	UE_LOG(LogTemp, Warning, TEXT("No available pooled objects!"));
	return nullptr; // No available objects
}

void APoolObject::ReleasePooledObject(AActor* PooledObject)
{
	for (auto& Pair : Actors)
	{
		if (Pair.first == PooledObject)
		{
			Pair.second = false; // Mark as not in use
			Pair.first->SetActorHiddenInGame(true);
			Pair.first->SetActorEnableCollision(false);
			return;
		}
	}
	
	UE_LOG(LogTemp, Warning, TEXT("Attempted to release an object that is not part of the pool!"));
}

// Called every frame
void APoolObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

