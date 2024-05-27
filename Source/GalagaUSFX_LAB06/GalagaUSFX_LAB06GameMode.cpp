// Copyright Epic Games, Inc. All Rights Reserved.

#include "GalagaUSFX_LAB06GameMode.h"
#include "GalagaUSFX_LAB06Pawn.h"


#include "BuilderPortaNavesAereasNiv1.h"
#include "DirectorPortaNavesAereas.h"
#include "PortaNavesAereas.h"


#include "Facade.h"

AGalagaUSFX_LAB06GameMode::AGalagaUSFX_LAB06GameMode()
{
	DefaultPawnClass = AGalagaUSFX_LAB06Pawn::StaticClass();
}

void AGalagaUSFX_LAB06GameMode::BeginPlay()
{
	Super::BeginPlay();

	Facade = GetWorld()->SpawnActor<AFacade>(AFacade::StaticClass());
	switch (FMath::RandRange(1, 1))
	{
	case 1:
		Facade->GenegarNavesEnemigas();
		Facade->GenerarCapsulas();
		break;
	}
	


	UWorld* World = GetWorld();
	if (World != nullptr)
	{
	//	IMPLEMENTACION DE PATRON BUILDER PARA CONSTRUIR EL PORTANAVES AEREAS
		//-----------------------------------------------------BUILDER----------------------------------------------------------------------------------//
		DirectorPortaNavesAereas = GetWorld()->SpawnActor<ADirectorPortaNavesAereas>(ADirectorPortaNavesAereas::StaticClass());

		switch (FMath::RandRange(1, 1))
		{
		case 1:
			BuilderPortaNavesAereasNiv1 = GetWorld()->SpawnActor<ABuilderPortaNavesAereasNiv1>(ABuilderPortaNavesAereasNiv1::StaticClass());//Spawning Concrete Builder
			DirectorPortaNavesAereas->SetBuilderPortaNavesAereas(BuilderPortaNavesAereasNiv1);//Setting Builder to Director 
			DirectorPortaNavesAereas->ConstruirPortaNaveAerea();//Constructing Ships 
			break;

			APortaNavesAereas* PortaNaveAerea = DirectorPortaNavesAereas->GetPortaNaveAerea();
			PortaNaveAerea->CaracteristicasPortaNaveAerea();
		}
	}
}

//
//// Función para crear enemigos aleatoriamente
//void AGalagaUSFX_LAB06GameMode::CrearEnemigosAleatoriamente(TArray<FString> TiposNaves, FVector PosicionInicial, FRotator RotacionNaves, float EspacioEntreNavesY, int CantidadNaves)
//{
//	// Obtener el mundo
//	UWorld* const World = GetWorld();
//	if (World == nullptr)
//	{
//		return;
//	}
//
//	// Posición Y inicial
//	float PosicionY = PosicionInicial.Y;
//
//	// Incremento en la posición Y para cada fila
//	float IncrementoY = EspacioEntreNavesY * TiposNaves.Num();
//
//	// Crear naves enemigas aleatoriamente
//	for (int i = 0; i < CantidadNaves; i++)
//	{
//		// Obtener una posición aleatoria desde TMNavesEnemigas
//		int32 RandomIndex = FMath::RandRange(0, TMNavesEnemigas.Num() - 1);
//		auto It = TMNavesEnemigas.CreateIterator();
//		for (int32 Index = 0; Index < RandomIndex; ++Index)
//		{
//			++It;
//		}
//
//		FVector PosicionNaveNueva = It->Value;
//		FRotator RotacionNaveNueva = RotacionNaves; // Rotación en Z a 180 grados
//
//		// Ajustar la posición Y basada en el índice de iteración
//		PosicionNaveNueva.Y = PosicionY + (i * IncrementoY);
//
//		// Obtener un tipo de nave enemiga aleatorio
//		int32 RandomTypeIndex = FMath::RandRange(0, TiposNaves.Num() - 1);
//		FString TipoNaveEnemiga = TiposNaves[RandomTypeIndex];
//
//		// Llamamos a la fabrica de naves para crear una nave del tipo especificado
//		ANaveEnemiga* NuevaNaveEnemiga = nullptr;
//		if (TipoNaveEnemiga == "NaveAerea_Caza")
//		{
//			NuevaNaveEnemiga = World->SpawnActor<ANaveAerea_Caza>(ANaveAerea_Caza::StaticClass(), PosicionNaveNueva, RotacionNaveNueva);
//		}
//		else if (TipoNaveEnemiga == "NaveAerea_Transporte")
//		{
//			NuevaNaveEnemiga = World->SpawnActor<ANaveAerea_Transporte>(ANaveAerea_Transporte::StaticClass(), PosicionNaveNueva,RotacionNaveNueva);
//		}
//		// Agregar la nueva nave enemiga al mapa
//		if (NuevaNaveEnemiga)
//		{
//			NuevaNaveEnemiga->idClaveNave = ClaveNaves++;
//			TMClavesNavesEnemigas.Add(NuevaNaveEnemiga, NuevaNaveEnemiga->idClaveNave);
//			TMNavesEnemigas.Add(NuevaNaveEnemiga, PosicionNaveNueva);
//			TANavesEnemigas.Add(NuevaNaveEnemiga);
//		}
//	}
//}



//void AGalagaUSFX_LAB06GameMode::CrearEnemigos()
//{
//	// Lista de tipos de naves enemigas disponibles
//	TArray<FString> TiposNaves;
//	TiposNaves.Add("NaveAerea_Caza");
//	TiposNaves.Add("NaveAerea_Transporte");
//
//	// Espacio deseado entre las naves en el eje Y
//	float EspacioEntreNavesY = 100.0f;
//
//	// Posición inicial de las naves
//	FVector PosicionInicial = FVector(0.0f, -650.0f, 200.0f);
//	FRotator RotacionNaves = FRotator(0.0f, 180.0f, 0.0f);
//
//	// Cantidad de naves a crear
//	int CantidadNaves = 10;
//
//	// Llamada a la función para crear las naves enemigas aleatoriamente
//	CrearEnemigosAleatoriamente(TiposNaves, PosicionInicial, RotacionNaves, EspacioEntreNavesY, CantidadNaves);
//}


//// Actualizamos el puntaje en la funcion RecibirDanio
//int32 ANaveAerea_Caza::RecibirDanio(float dano)
//{
//	// Restamos la energia de la nave
//	energia -= dano;
//
//	// Verificamos si la nave ha sido destruida
//	if (energia <= 0)
//	{
//		// Destruimos la nave
//		Destroy();
//
//		// Actualizamos el puntaje
//		Puntaje += recompensaNave;
//
//		return recompensaNave; // Si la nave ha sido destruida, retornamos la recompensa
//	}
//	return 0; // Si la nave no ha sido destruida, retornamos 0
//}


//void AGalagaUSFX_LAB06GameMode::Score()
//{
//	// Implementar la función para mostrar el score
//// Mostrar el puntaje en la pantalla
//	if (GEngine)
//	{
//		FString PuntajeStr = FString::FromInt(Puntaje);
//		FString Mensaje = "Puntaje: " + PuntajeStr;
//		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, Mensaje);
//	}
//}
//
