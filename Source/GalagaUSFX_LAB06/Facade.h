// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Facade.generated.h"

UCLASS()
class GALAGAUSFX_LAB06_API AFacade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFacade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void GenegarNavesEnemigas();
	void GenerarCapsulas();

	void CrearEnemigosAleatoriamente(TArray<FString> TiposNaves, FVector PosicionInicial, FRotator RotacionNaves, float EspacioEntreNavesY, int CantidadNaves);
	void CrearEnemigos();
    void DestruirNaves(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);





public:
	FTimerHandle FTHCrearEnemigosAleatorios;

	TArray<class ANaveEnemiga*> TANavesEnemigas; //Array de Naves Enemigas
	int ClaveNaves = 0; // clave para las naves enemigas

	UPROPERTY()
	TMap<class ANaveEnemiga*, int> TMClavesNavesEnemigas; //Mapa de Naves Enemigas
	TMap<class ANaveEnemiga*, FVector> TMNavesEnemigas; //Mapa de Naves Enemigas

};
