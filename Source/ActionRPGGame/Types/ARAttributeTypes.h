// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "AREnumTypes.h"
#include "Slate.h"
#include "ARAttributeTypes.generated.h"

USTRUCT(BlueprintType)
struct FAttribute
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
		FName AttributeName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
		float ModValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
		TEnumAsByte<EAttrOp> OperationType;
	FAttribute() {};
};

USTRUCT(BlueprintType)
struct FAttributeModified
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(BlueprintReadOnly, Category = "Attribute")
		FName AttributeName;

	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
		float ActuallDamage;

	FAttributeModified() {};
};

/*
	It's not really damage. Attribute can have all math operations.
	Whether we can call it demegae depnds on math operation and which attribute it affect.
*/
USTRUCT(BlueprintType)
struct FARDamageEvent
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "Attribute")
		FAttribute Attribute;

	UPROPERTY()
		TSubclassOf<class UDamageType> DamageTypeClass;

	static const int32 ClassID = 0;

	virtual int32 GetTypeID() const { return FARDamageEvent::ClassID; }
	virtual bool IsOfType(int32 InID) const { return FARDamageEvent::ClassID == InID; };
};

USTRUCT(BlueprintType)
struct FARPointDamageEvent : public FARDamageEvent
{
	GENERATED_USTRUCT_BODY()
public:
	/** Direction the shot came from. Should be normalized. */
	UPROPERTY()
		FVector_NetQuantizeNormal ShotDirection;

	UPROPERTY()
	struct FHitResult HitInfo;

	static const int32 ClassID = 1;

	virtual int32 GetTypeID() const { return FARPointDamageEvent::ClassID; }
	virtual bool IsOfType(int32 InID) const { return FARPointDamageEvent::ClassID == InID; };
};

USTRUCT(BlueprintType)
struct FARRadialDamageEvent : public FARDamageEvent
{
	GENERATED_USTRUCT_BODY()
public:
	/** Direction the shot came from. Should be normalized. */
	UPROPERTY()
		FVector_NetQuantizeNormal ShotDirection;

	UPROPERTY()
	struct FHitResult HitInfo;

	static const int32 ClassID = 2;

	virtual int32 GetTypeID() const { return FARRadialDamageEvent::ClassID; }
	virtual bool IsOfType(int32 InID) const { return FARRadialDamageEvent::ClassID == InID; };
};

USTRUCT(BlueprintType)
struct FAttributeChanged
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "Attribute")
		FAttribute Attribute;

	UPROPERTY(BlueprintReadWrite, Category = "Attribute")
		AActor* ChangeTarget;

	UPROPERTY(BlueprintReadWrite, Category = "Attribute")
		AActor* ChangeCauser;

	UPROPERTY(BlueprintReadWrite, Category = "Attribute")
		class AActor* ChangeInstigator;

	UPROPERTY(BlueprintReadWrite, Category = "Attribute")
		UDamageType* DamageType;
};

USTRUCT(BlueprintType)
struct FHitInfo
{
	GENERATED_USTRUCT_BODY()
public:

};