// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category = "Stats")
	float Damage = 50.f;

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* Projectile = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UProjectileMovementComponent* ProjectileMovementComponent = nullptr;

	UFUNCTION()//it's like UPROPERTY, but for function
	void OnHit(UPrimitiveComponent* PrimitiveComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		FVector Impulse, const FHitResult& HitResult);

	UPROPERTY(Editanywhere, Category = "Effects")
	class UParticleSystem* HitEffect = nullptr;

	UPROPERTY(EditAnywhere, Category = "Effects")
	class UParticleSystemComponent* SmokeTrail = nullptr;

	UPROPERTY(EditAnywhere, Category = "Effects")
	class USoundBase* HitSound = nullptr;

	UPROPERTY(EditAnywhere, Category = "Effects")
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass = nullptr;

};
