// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GalagaUSFX_LAB06/Facade.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFacade() {}
// Cross Module References
	GALAGAUSFX_LAB06_API UClass* Z_Construct_UClass_AFacade_NoRegister();
	GALAGAUSFX_LAB06_API UClass* Z_Construct_UClass_AFacade();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_GalagaUSFX_LAB06();
	GALAGAUSFX_LAB06_API UClass* Z_Construct_UClass_ANaveEnemiga_NoRegister();
// End Cross Module References
	void AFacade::StaticRegisterNativesAFacade()
	{
	}
	UClass* Z_Construct_UClass_AFacade_NoRegister()
	{
		return AFacade::StaticClass();
	}
	struct Z_Construct_UClass_AFacade_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_TMClavesNavesEnemigas_ValueProp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TMClavesNavesEnemigas_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TMClavesNavesEnemigas_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_TMClavesNavesEnemigas;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFacade_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GalagaUSFX_LAB06,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFacade_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Facade.h" },
		{ "ModuleRelativePath", "Facade.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AFacade_Statics::NewProp_TMClavesNavesEnemigas_ValueProp = { "TMClavesNavesEnemigas", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AFacade_Statics::NewProp_TMClavesNavesEnemigas_Key_KeyProp = { "TMClavesNavesEnemigas_Key", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_ANaveEnemiga_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFacade_Statics::NewProp_TMClavesNavesEnemigas_MetaData[] = {
		{ "Comment", "// clave para las naves enemigas\n" },
		{ "ModuleRelativePath", "Facade.h" },
		{ "ToolTip", "clave para las naves enemigas" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_AFacade_Statics::NewProp_TMClavesNavesEnemigas = { "TMClavesNavesEnemigas", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFacade, TMClavesNavesEnemigas), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AFacade_Statics::NewProp_TMClavesNavesEnemigas_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFacade_Statics::NewProp_TMClavesNavesEnemigas_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFacade_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFacade_Statics::NewProp_TMClavesNavesEnemigas_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFacade_Statics::NewProp_TMClavesNavesEnemigas_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFacade_Statics::NewProp_TMClavesNavesEnemigas,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFacade_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFacade>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFacade_Statics::ClassParams = {
		&AFacade::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AFacade_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AFacade_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFacade_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFacade_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFacade()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFacade_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFacade, 2304218105);
	template<> GALAGAUSFX_LAB06_API UClass* StaticClass<AFacade>()
	{
		return AFacade::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFacade(Z_Construct_UClass_AFacade, &AFacade::StaticClass, TEXT("/Script/GalagaUSFX_LAB06"), TEXT("AFacade"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFacade);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
