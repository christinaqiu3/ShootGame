// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DemoActor.generated.h"

UCLASS()
class CLASSPROJECT1_API ADemoActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADemoActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Demo")
	UStaticMeshComponent* MyMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pulling")
	FVector PullRange{ 600.0f, 600.0f, 600.0f };

	// FOR UFUNCTION DONT ADD SEMICOLON AT THE END FOR THE LIGHT PURPLE TEXT MACRO
	UFUNCTION(BlueprintCallable, Category = "Pulling")
	void PullInPlayer();

	UFUNCTION(BlueprintPure)
	static int SillyFunction(int a, int b);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pulling")
	TArray<AActor*> ActorsArray;
};
