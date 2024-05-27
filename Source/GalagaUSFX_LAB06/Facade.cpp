// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade.h"

#include "NaveEnemiga.h"
#include "NaveAerea_Caza.h"
#include "NaveAerea_Transporte.h"	
#include "NaveAcuatica_Espia.h"
#include "NaveAcuatica_Exploracion.h"
#include "NaveTerrestre_Artilleria.h"
#include "NaveTerrestre_Transporte.h"

#include "CreadorNaves.h"
#include "CreadorNavesAereas.h"
#include "CreadorNavesAcuaticas.h"
#include "CreadorNavesTerrestres.h"

#include "CreadorCapsulas.h"
#include "Capsula.h"

AFacade::AFacade()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFacade::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(FTHCrearEnemigosAleatorios, this, &AFacade::CrearEnemigos, 10.0f, true, 10.0f);

}

void AFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFacade::GenegarNavesEnemigas()
{
	ACreadorNaves* CreadorNavesAereas = GetWorld()->SpawnActor<ACreadorNavesAereas>(ACreadorNavesAereas::StaticClass());
	ACreadorNaves* CreadorNavesTerrestres = GetWorld()->SpawnActor<ACreadorNavesTerrestres>(ACreadorNavesTerrestres::StaticClass());
	ACreadorNaves* CreadorNavesAcuaticas = GetWorld()->SpawnActor<ACreadorNavesAcuaticas>(ACreadorNavesAcuaticas::StaticClass());

	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		// DESDE ACA SPAWNEAMOS LAS NAVES DE LAS FABRICAS DE NAVES AEREAS, TERRESTRES Y ACUATICAS
		// Creamos una nueva Posicion para las naves tipo Aereas
		FVector	PosicionNavesAereas = FVector(-450.0f, -200.0f, 200.0f);
		FRotator RotacionNavesAereas = FRotator(0.0f, 180.0f, 0.0f);  // Rotación en Z a 180 grados

		// Creamos 7 naves de la clase NaveAerea_Caza
		for (int i = 0; i < 7; i++)
		{
			// Llamamos a la fabrica de naves aereas para crear una nave de la clase NaveAerea_Caza
			ANaveEnemiga* NaveEnemiga = CreadorNavesAereas->OrdenarNave("NaveAerea_Caza", PosicionNavesAereas, RotacionNavesAereas);
			//NaveEnemiga->idClaveNave = ClaveNaves++; // Asignar la clave y luego incrementar
			TMClavesNavesEnemigas.Add(NaveEnemiga, ClaveNaves); // Agregamos la nave al TMap y la Clave de la naves aerea caza
			TMNavesEnemigas.Add(NaveEnemiga, PosicionNavesAereas); // Agregamos la nave al TMap y la Posicion de la nave aerea caza
			TANavesEnemigas.Add(NaveEnemiga); // Agregamos la nave a la lista de naves enemigas
			PosicionNavesAereas.Y += 200.0f; // Sirve para que las naves esten separadas en el eje X
		}
		// Actualizamos la posicion de las naves aereas caza para trabajar con las naves de la clase NaveAerea_Transporte
		PosicionNavesAereas.X = PosicionNavesAereas.X = -150.0f; // Actualizamos la posicion en el eje X
		PosicionNavesAereas.Y = PosicionNavesAereas.Y = -200.0f;  // Actualizamos la posicion en el eje Y

		// Creamos 7 naves de la clase NaveAerea_Transporte
		for (int i = 0; i < 7; i++)
		{
			// Llamamos a la fabrica de naves aereas para crear una nave de la clase NaveAerea_Transporte
			ANaveEnemiga* NaveEnemiga = CreadorNavesAereas->OrdenarNave("NaveAerea_Transporte", PosicionNavesAereas, RotacionNavesAereas);
			//NaveEnemiga->idClaveNave = ClaveNaves++; // Asignar la clave y luego incrementar
			TMClavesNavesEnemigas.Add(NaveEnemiga, ClaveNaves); // Agregamos la nave al TMap y la Clave de la naves aerea transporte
			TMNavesEnemigas.Add(NaveEnemiga, PosicionNavesAereas); // Agregamos la nave al TMap y la Posicion de la nave aerea transporte
			TANavesEnemigas.Add(NaveEnemiga); // Agregamos la nave a la lista de naves enemigas
			PosicionNavesAereas.Y += 200.0f; // Sirve para que las naves esten separadas en el eje X
		}


		// Definiendo nuevas posiciones de las Naves Terrestres
		FVector	PosicionNavesTerrestres = FVector(300.0f, -650.0f, 200.0f); // Posicion inicial de las Naves Terrestres
		FRotator RotacionNavesTerrestre = FRotator(0.0f, 180.0f, 0.0f);
		// Creamos 7 naves de la clase NaveTerrestre_Transporte
		for (int i = 0; i < 7; i++)
		{
			// Llamamos a la fabrica de naves terrestres para crear una nave de la clase NaveTerrestre_Transporte
			ANaveEnemiga* NaveEnemiga = CreadorNavesTerrestres->OrdenarNave("NaveTerrestre_Transporte", PosicionNavesTerrestres, RotacionNavesTerrestre);
			//NaveEnemiga->idClaveNave = ClaveNaves++; // Asignar la clave y luego incrementar
			//TMClavesNavesEnemigas.Add(NaveEnemiga, ClaveNaves); // Agregamos la nave al TMap y la Clave de la naves terrestre transporte
			////TMANavesEnemigas.Add(NaveEnemiga, PosicionNavesTerrestres); // Agregamos la nave al TMap y la Posicion de la nave terrestre transporte
			//TANavesEnemigas.Add(NaveEnemiga); // agregamos la nave a la lista de naves enemigas
			PosicionNavesTerrestres.Y += 250.0f; // sirve para que las naves esten separadas en el eje Y
		}

		// Actualizamos la posicion de las Naveterrestres_Transporte para trabajar con las naves de la clase NaveTerrestre_Artilleria
		PosicionNavesTerrestres.X = PosicionNavesTerrestres.X = 500.0f; // actualizo la posicion en la posicion X
		PosicionNavesTerrestres.Y = PosicionNavesTerrestres.Y = -650.0f; // actualizo la posicion en la posicion Y

		// Creamos 7 naves de la clase NaveTerrestre_Artilleria
		for (int i = 0; i < 7; i++)
		{
			// Llamamos a la fabrica de naves terrestres para crear una nave de la clase NaveTerrestre_Artilleria
			ANaveEnemiga* NaveEnemiga = CreadorNavesTerrestres->OrdenarNave("NaveTerrestre_Artilleria", PosicionNavesTerrestres, RotacionNavesTerrestre);
			//NaveEnemiga->idClaveNave = ClaveNaves++; // Asignar la clave y luego incrementar
			//TMClavesNavesEnemigas.Add(NaveEnemiga, ClaveNaves); // Agregamos la nave al TMap y la Clave de la naves terrestre artilleria
			////TMANavesEnemigas.Add(NaveEnemiga, PosicionNavesTerrestres); // Agregamos la nave al TMap y la Posicion de la nave terrestre artilleria
			//TANavesEnemigas.Add(NaveEnemiga); // agregamos la nave a la lista de naves enemigas
			PosicionNavesTerrestres.Y += 250.0f; // sirve para que las naves esten separadas en el eje Y
		}

		// Definiendo nuevas posiciones de las Naves Acuaticas
		FVector	PosicionNavesAcuaticas = FVector(900.0f, -700.0f, 180.0f); // Posicion inicial de las Naves Acuaticas
		FRotator RotacionNavesAcuaticas = FRotator(0.0f, 180.0f, 0.0f);

		// Creamos 7 naves de la clase NaveAcuatica_Exploracion
		for (int i = 0; i < 7; i++)
		{
			// Llamamos a la fabrica de naves acuaticas para crear una nave de la clase NaveAcuatica_Exploracion
			ANaveEnemiga* NaveEnemiga = CreadorNavesAcuaticas->OrdenarNave("NaveAcuatica_Exploracion", PosicionNavesAcuaticas, RotacionNavesAcuaticas);
			//NaveEnemiga->idClaveNave = ClaveNaves++; // Asignar la clave y luego incrementar
			//TMClavesNavesEnemigas.Add(NaveEnemiga, ClaveNaves); // Agregamos la nave al TMap y la Clave de la naves acuatica exploracion
			////TMANavesEnemigas.Add(NaveEnemiga, PosicionNavesAcuaticas); // Agregamos la nave al TMap y la Posicion de la nave acuatica exploracion
			//TANavesEnemigas.Add(NaveEnemiga); // agregamos la nave a la lista de naves enemigas
			PosicionNavesAcuaticas.Y += 250.0f; // sirve para que las naves esten separadas en el eje X
		}

		// Actualizamos la posicion de las Naves Acuaticas_Exploracion para trabajar con las naves de la clase NaveAcuatica_Espia
		PosicionNavesAcuaticas.X = PosicionNavesAcuaticas.X = 1200.0f; // actualizo la posicion en la posicion X
		PosicionNavesAcuaticas.Y = PosicionNavesAcuaticas.Y = -700.0f; // actualizo la posicion en la posicion Y

		// Creamos 7 naves de la clase NaveAcuatica_Espia
		for (int i = 0; i < 7; i++)
		{
			// Llamamos a la fabrica de naves acuaticas para crear una nave de la clase NaveAcuatica_Espia
			ANaveEnemiga* NaveEnemiga = CreadorNavesAcuaticas->OrdenarNave("NaveAcuatica_Espia", PosicionNavesAcuaticas, RotacionNavesAcuaticas);
			//NaveEnemiga->idClaveNave = ClaveNaves++; // Asignar la clave y luego incrementar
			//TMClavesNavesEnemigas.Add(NaveEnemiga, ClaveNaves); // Agregamos la nave al TMap y la Clave de la naves acuatica espia
			////TMANavesEnemigas.Add(NaveEnemiga, PosicionNavesAcuaticas); // Agregamos la nave al TMap y la Posicion de la nave acuatica espia
			//TANavesEnemigas.Add(NaveEnemiga); // agregamos la nave a la lista de naves enemigas
			PosicionNavesAcuaticas.Y += 250.0f; // sirve para que las naves esten separadas en el eje X

		}
	}	

}
void AFacade::DestruirNaves(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		// Verificar si la bala colisionó con una Nave Aérea Caza
		ANaveAerea_Caza* NaveAereaCaza = Cast<ANaveAerea_Caza>(OtherActor);
		if (NaveAereaCaza)
		{
			// Reducir la energía de la nave enemiga
			float const Cantidad = 10.0f; // Cantidad de daño que inflige la bala
			NaveAereaCaza->RecibirDanio(Cantidad);

			//NaveAereaCaza->Destroy(); // si descomento esto elimina la nave directamente
		}

		// Verificar si la bala colisionó con una Nave Aérea Transporte
		ANaveAerea_Transporte* NaveAereaTransporte = Cast<ANaveAerea_Transporte>(OtherActor);
		if (NaveAereaTransporte)
		{

			// Reducir la energía de la nave enemiga
			float const Cantidad = 10.0f; // Cantidad de daño que inflige la bala
			NaveAereaTransporte->RecibirDanio(Cantidad);

			//NaveAereaTransporte->Destroy(); // si descomento esto elimina la nave directamente
		}

		ANaveAcuatica_Espia* NaveAcuaticaEspia = Cast<ANaveAcuatica_Espia>(OtherActor);
		if (NaveAcuaticaEspia)
		{
			// Reducir la energía de la nave enemiga
			float const Cantidad = 10.0f; // Cantidad de daño que inflige la bala
			NaveAcuaticaEspia->RecibirDanio(Cantidad);

			//NaveAcuaticaEspia->Destroy(); // si descomento esto elimina la nave directamente
		}

		ANaveAcuatica_Exploracion* NaveAcuaticaExploracion = Cast<ANaveAcuatica_Exploracion>(OtherActor);
		if (NaveAcuaticaExploracion)
		{
			// Reducir la energía de la nave enemiga
			float const Cantidad = 10.0f; // Cantidad de daño que inflige la bala
			NaveAcuaticaExploracion->RecibirDanio(Cantidad);

			//NaveAcuaticaExploracion->Destroy(); // si descomento esto elimina la nave directamente
		}

		ANaveTerrestre_Artilleria* NaveTerrestreArtilleria = Cast<ANaveTerrestre_Artilleria>(OtherActor);
		if (NaveTerrestreArtilleria)
		{
			// Reducir la energía de la nave enemiga
			float const Cantidad = 10.0f; // Cantidad de daño que inflige la bala
			NaveTerrestreArtilleria->RecibirDanio(Cantidad);

			//NaveTerrestreArtilleria->Destroy(); // si descomento esto elimina la nave directamente
		}

		ANaveTerrestre_Transporte* NaveTerrestreTransporte = Cast<ANaveTerrestre_Transporte>(OtherActor);
		if (NaveTerrestreTransporte)
		{
			// Reducir la energía de la nave enemiga
			float const Cantidad = 10.0f; // Cantidad de daño que inflige la bala
			NaveTerrestreTransporte->RecibirDanio(Cantidad);

			//NaveTerrestreTransporte->Destroy(); // si descomento esto elimina la nave directamente
		}
	}
}





void AFacade::GenerarCapsulas()
{
	ACreadorCapsulas* CreadorCapsulas = GetWorld()->SpawnActor<ACreadorCapsulas>(ACreadorCapsulas::StaticClass());

	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		FVector SpawnLocation = FVector(FMath::RandRange(-1000.0f, 120.0f), FMath::RandRange(-1000.0f, 120.0f), 200.0f);/*
		FVector SpawnLocation3 = FVector(FMath::RandRange(-1000.0f, 120.0f), FMath::RandRange(-1000.0f, 120.0f), 200.0f);*/
		FRotator SpawnRotation = FRotator(0.0f, 0.0f, .0f);
		for (int i = 0; i < 5; i++)
		{
			ACapsula* Capsula = CreadorCapsulas->OrdenarCapsula("CapsulaLoca", SpawnLocation, SpawnRotation);
			SpawnLocation.Y += 250.0f;
		}
		FVector SpawnLocation2 = FVector(FMath::RandRange(-1000.0f, 120.0f), FMath::RandRange(-1000.0f, 120.0f), 200.0f);
		for (int i = 0; i < 3; i++)
		{
			ACapsula* Capsula = CreadorCapsulas->OrdenarCapsula("CapsulaEnergia", SpawnLocation2, SpawnRotation);
			SpawnLocation2.Y += 250.0f;
		}
	}
}


// Funciones extras para crear naves enemigas aleatoriamente (opcional) NO ES PARTE DEL FACADE

void AFacade::CrearEnemigosAleatoriamente(TArray<FString> TiposNaves, FVector PosicionInicial, FRotator RotacionNaves, float EspacioEntreNavesY, int CantidadNaves)
{
	// Obtener el mundo
	UWorld* const World = GetWorld();
	if (World == nullptr)
	{
		return;
	}

	// Posición Y inicial
	float PosicionY = PosicionInicial.Y;

	// Incremento en la posición Y para cada fila
	float IncrementoY = EspacioEntreNavesY * TiposNaves.Num();

	// Crear naves enemigas aleatoriamente
	for (int i = 0; i < CantidadNaves; i++)
	{
		// Obtener una posición aleatoria desde TMNavesEnemigas
		int32 RandomIndex = FMath::RandRange(0, TMNavesEnemigas.Num() - 1);
		auto It = TMNavesEnemigas.CreateIterator();
		for (int32 Index = 0; Index < RandomIndex; ++Index)
		{
			++It;
		}

		FVector PosicionNaveNueva = It->Value;
		FRotator RotacionNaveNueva = RotacionNaves; // Rotación en Z a 180 grados

		// Ajustar la posición Y basada en el índice de iteración
		PosicionNaveNueva.Y = PosicionY + (i * IncrementoY);

		// Obtener un tipo de nave enemiga aleatorio
		int32 RandomTypeIndex = FMath::RandRange(0, TiposNaves.Num() - 1);
		FString TipoNaveEnemiga = TiposNaves[RandomTypeIndex];

		// Llamamos a la fabrica de naves para crear una nave del tipo especificado
		ANaveEnemiga* NuevaNaveEnemiga = nullptr;
		if (TipoNaveEnemiga == "NaveAerea_Caza")
		{
			NuevaNaveEnemiga = World->SpawnActor<ANaveAerea_Caza>(ANaveAerea_Caza::StaticClass(), PosicionNaveNueva, RotacionNaveNueva);
		}
		else if (TipoNaveEnemiga == "NaveAerea_Transporte")
		{
			NuevaNaveEnemiga = World->SpawnActor<ANaveAerea_Transporte>(ANaveAerea_Transporte::StaticClass(), PosicionNaveNueva, RotacionNaveNueva);
		}
		// Agregar la nueva nave enemiga al mapa
		if (NuevaNaveEnemiga)
		{
			NuevaNaveEnemiga->idClaveNave = ClaveNaves++;
			TMClavesNavesEnemigas.Add(NuevaNaveEnemiga, NuevaNaveEnemiga->idClaveNave);
			TMNavesEnemigas.Add(NuevaNaveEnemiga, PosicionNaveNueva);
			TANavesEnemigas.Add(NuevaNaveEnemiga);
		}
	}
}

// (opcional) Función para crear enemigos de un tipo específico NO ES PARTE DEL FACADE
void AFacade::CrearEnemigos()
{
	// Lista de tipos de naves enemigas disponibles
	TArray<FString> TiposNaves;
	TiposNaves.Add("NaveAerea_Caza");
	TiposNaves.Add("NaveAerea_Transporte");

	// Espacio deseado entre las naves en el eje Y
	float EspacioEntreNavesY = 100.0f;

	// Posición inicial de las naves
	FVector PosicionInicial = FVector(0.0f, -650.0f, 200.0f);
	FRotator RotacionNaves = FRotator(0.0f, 180.0f, 0.0f);

	// Cantidad de naves a crear
	int CantidadNaves = 10;

	// Llamada a la función para crear las naves enemigas aleatoriamente
	CrearEnemigosAleatoriamente(TiposNaves, PosicionInicial, RotacionNaves, EspacioEntreNavesY, CantidadNaves);
}

