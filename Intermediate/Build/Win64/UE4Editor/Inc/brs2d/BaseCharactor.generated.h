// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BRS2D_BaseCharactor_generated_h
#error "BaseCharactor.generated.h already included, missing '#pragma once' in BaseCharactor.h"
#endif
#define BRS2D_BaseCharactor_generated_h

#define brs2d_Source_brs2d_BaseCharactor_h_11_RPC_WRAPPERS
#define brs2d_Source_brs2d_BaseCharactor_h_11_RPC_WRAPPERS_NO_PURE_DECLS
#define brs2d_Source_brs2d_BaseCharactor_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesABaseCharactor(); \
	friend BRS2D_API class UClass* Z_Construct_UClass_ABaseCharactor(); \
	public: \
	DECLARE_CLASS(ABaseCharactor, ACharacter, COMPILED_IN_FLAGS(0), 0, brs2d, NO_API) \
	DECLARE_SERIALIZER(ABaseCharactor) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<ABaseCharactor*>(this); }


#define brs2d_Source_brs2d_BaseCharactor_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesABaseCharactor(); \
	friend BRS2D_API class UClass* Z_Construct_UClass_ABaseCharactor(); \
	public: \
	DECLARE_CLASS(ABaseCharactor, ACharacter, COMPILED_IN_FLAGS(0), 0, brs2d, NO_API) \
	DECLARE_SERIALIZER(ABaseCharactor) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<ABaseCharactor*>(this); }


#define brs2d_Source_brs2d_BaseCharactor_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABaseCharactor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABaseCharactor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseCharactor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseCharactor); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ABaseCharactor(const ABaseCharactor& InCopy); \
public:


#define brs2d_Source_brs2d_BaseCharactor_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ABaseCharactor(const ABaseCharactor& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABaseCharactor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABaseCharactor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABaseCharactor)


#define brs2d_Source_brs2d_BaseCharactor_h_8_PROLOG
#define brs2d_Source_brs2d_BaseCharactor_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	brs2d_Source_brs2d_BaseCharactor_h_11_RPC_WRAPPERS \
	brs2d_Source_brs2d_BaseCharactor_h_11_INCLASS \
	brs2d_Source_brs2d_BaseCharactor_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define brs2d_Source_brs2d_BaseCharactor_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	brs2d_Source_brs2d_BaseCharactor_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	brs2d_Source_brs2d_BaseCharactor_h_11_INCLASS_NO_PURE_DECLS \
	brs2d_Source_brs2d_BaseCharactor_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID brs2d_Source_brs2d_BaseCharactor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
