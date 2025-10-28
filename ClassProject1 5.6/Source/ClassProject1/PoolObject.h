// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PoolObject.generated.h"

UCLASS()
class CLASSPROJECT1_API APoolObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APoolObject();

	/*PoolObject(size_t capacity, std::function<std::shared_ptr<T>()> createFunc)
		: m_capacity(capacity), m_createFunc(createFunc)
	{
		for (size_t i = 0; i < length; i++)
		{
			m_pool.push_back(m_createFunc());
		}
	}

	std::shared_ptr<T> Acquire()
	{
		if (m_pool.empty())
		{
			return nullptr;
		}
		else
		{
			auto obj = m_pool.back();
			m_pool.pop_back();
			m_active.push_back(obj);
			return obj;
		}
	}

	void Release(std::shared_ptr<T> obj)
	{
		auto it = std::find(m_active.begin(), m_active.end(), obj);
		if (it != m_active.end())
		{
			m_active.erase(it);
			m_pool.push_back(obj);
		}
	}*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Object Pool")
	TSubclassOf<AActor> PooledObjectClass;

	UPROPERTY(EditAnywhere, Category = "Object Pool")
	int32 PoolSize = 10;

	UFUNCTION(BlueprintCallable, Category = "Object Pool")
	AActor* AcquirePooledObject();

	UFUNCTION(BlueprintCallable, Category = "Object Pool")
	void ReleasePooledObject(AActor* PooledObject);

private:
	/*size_t m_capacity;
	std::function<std::shared_ptr<T>()> m_createFunc;
	std::vector<std::shared_ptr<T>> m_pool;
	std::vector<std::shared_ptr<T>> m_active;*/
	TArray<std::pair<AActor*, bool>> Actors;

};
