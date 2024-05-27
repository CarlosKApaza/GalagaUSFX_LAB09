// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GalagaUSFX_LAB06GameMode.generated.h"

class ANaveEnemiga; //Forward Declaration

UCLASS(MinimalAPI)
class AGalagaUSFX_LAB06GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalagaUSFX_LAB06GameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
//------------------------------Builder PortaNavesAereasNiv1--------------------------------//
	// builder concreto 1
	UPROPERTY(VisibleAnywhere, Category = "BuilderPortaNavesAereasNiv1")
	class ABuilderPortaNavesAereasNiv1* BuilderPortaNavesAereasNiv1;
	// builder director
	UPROPERTY(VisibleAnywhere, Category = "DirectorPortaNavesAereas")
	class ADirectorPortaNavesAereas* DirectorPortaNavesAereas;


public:

	FTimerHandle FTHMostrarClaves;
	
	

	//void MostrarClavesNaves(); 
	//void OcultarClavesNaves(); 


	//void CrearEnemigosAleatoriamente(TArray<FString> TiposNaves, FVector PosicionInicial, FRotator RotacionNaves, float EspacioEntreNavesY, int CantidadNaves); //Funcion para crear enemigos aleatoriamente
	//void CrearEnemigos(); //Funcion para crear enemigos de un tipo especifico


	UPROPERTY(VisibleAnywhere, Category = "FacadeShip")
	class AFacade* Facade;
};



