// Copyright 2015-2019 Mail.Ru Group. All Rights Reserved.

#pragma once

#include "PsData.h"
#include "PsDataArrayProxy.h"

#include "CoreMinimal.h"

#include "PsDataBlueprintArrayProxy.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UPsDataBlueprintArrayProxy : public UObject
{
	GENERATED_UCLASS_BODY()

private:
	FPsDataArrayProxy<UPsData*> Proxy;

public:
	/** Initialize */
	void Init(UPsData* Instance, const TSharedPtr<const FDataField> Field);

	/** Is valid */
	UFUNCTION(BlueprintPure, meta = (Category = "PsData|Collection"))
	bool IsValid();

    UFUNCTION(BlueprintCallable, meta = (Category = "PsData|Collection"))
    int32 Add(UPsData* Element);

    UFUNCTION(BlueprintCallable, meta = (Category = "PsData|Collection"))
    void Insert(UPsData* Element, int32 Index);

    UFUNCTION(BlueprintCallable, meta = (Category = "PsData|Collection"))
    void RemoveAt(int32 Index);

    UFUNCTION(BlueprintCallable, meta = (Category = "PsData|Collection"))
    int32 Remove(UPsData* Element);

    UFUNCTION(BlueprintCallable, meta = (Category = "PsData|Collection"))
    UPsData* Set(UPsData* Element, int32 Index);

    UFUNCTION(BlueprintPure, meta = (Category = "PsData|Collection"))
    UPsData* Get(int32 Index);

    UFUNCTION(BlueprintPure, meta = (Category = "PsData|Collection"))
    int32 Find(UPsData* Element);

    UFUNCTION(BlueprintPure, meta = (Category = "PsData|Collection"))
    int32 Num();

    UFUNCTION(BlueprintPure, meta = (Category = "PsData|Collection"))
    bool IsEmpty();

    UFUNCTION(BlueprintPure, meta = (Category = "PsData|Collection"))
    bool IsValidIndex(int32 Index);

	/** Bind */
	void Bind(const FString& Type, const FPsDataDynamicDelegate& Delegate) const;

	/** Bind */
	void Bind(const FString& Type, const FPsDataDelegate& Delegate) const;

	/** Bind */
	void Unbind(const FString& Type, const FPsDataDynamicDelegate& Delegate) const;

	/** Bind */
	void Unbind(const FString& Type, const FPsDataDelegate& Delegate) const;

	/** Get const proxy */
	FPsDataConstArrayProxy<UPsData*> GetProxy();

protected:
	/** Blueprint bind */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Bind", Category = "PsData|Collection"))
	void BlueprintBind(const FString& Type, const FPsDataDynamicDelegate& Delegate);

	/** Blueprint unbind */
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Unbind", Category = "PsData|Collection"))
	void BlueprintUnbind(const FString& Type, const FPsDataDynamicDelegate& Delegate);

	/** Blueprint get ref */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Map", Category = "PsData|Collection"))
	const TArray<UPsData*>& GetRef();
};
