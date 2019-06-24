// Copyright 2015-2019 Mail.Ru Group. All Rights Reserved.

#include "Collection/PsDataBlueprintArrayProxy.h"

#include "PsDataCore.h"

UPsDataBlueprintArrayProxy::UPsDataBlueprintArrayProxy(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, Proxy()
{
}

void UPsDataBlueprintArrayProxy::Init(UPsData* Instance, const TSharedPtr<const FDataField> Field)
{
	check(!Proxy.IsValid());
	Proxy = FPsDataArrayProxy<UPsData*>(Instance, Field);
	check(IsValid());
}

bool UPsDataBlueprintArrayProxy::IsValid()
{
	return Proxy.IsValid();
}

void UPsDataBlueprintArrayProxy::Bind(const FString& Type, const FPsDataDynamicDelegate& Delegate) const
{
	Proxy.Bind(Type, Delegate);
}

void UPsDataBlueprintArrayProxy::Bind(const FString& Type, const FPsDataDelegate& Delegate) const
{
	Proxy.Bind(Type, Delegate);
}

void UPsDataBlueprintArrayProxy::Unbind(const FString& Type, const FPsDataDynamicDelegate& Delegate) const
{
	Proxy.Unbind(Type, Delegate);
}

void UPsDataBlueprintArrayProxy::Unbind(const FString& Type, const FPsDataDelegate& Delegate) const
{
	Proxy.Unbind(Type, Delegate);
}

FPsDataConstArrayProxy<UPsData*> UPsDataBlueprintArrayProxy::GetProxy()
{
	return Proxy;
}

void UPsDataBlueprintArrayProxy::BlueprintBind(const FString& Type, const FPsDataDynamicDelegate& Delegate)
{
	Proxy.Bind(Type, Delegate);
}

void UPsDataBlueprintArrayProxy::BlueprintUnbind(const FString& Type, const FPsDataDynamicDelegate& Delegate)
{
	Proxy.Unbind(Type, Delegate);
}

const TArray<UPsData*>& UPsDataBlueprintArrayProxy::GetRef()
{
	return Proxy.GetRef();
}

int32 UPsDataBlueprintArrayProxy::Add(UPsData* Element) {
    return Element != nullptr && this->IsValid() ? Proxy.Add(Element) : -1;
}

void UPsDataBlueprintArrayProxy::Insert(UPsData* Element, int32 Index) {
    if(Element != nullptr && this->IsValid()) {
        Proxy.Insert(Element, Index);
    }
}

void UPsDataBlueprintArrayProxy::RemoveAt(int32 Index) {
    if(this->IsValid()) {
        Proxy.RemoveAt(Index);
    }
}

int32 UPsDataBlueprintArrayProxy::Remove(UPsData* Element) {
    return Element != nullptr && this->IsValid() ? Proxy.Remove(Element) : -1;
}

UPsData* UPsDataBlueprintArrayProxy::Set(UPsData* Element, int32 Index) {
    return Element != nullptr && this->IsValid() ? Proxy.Set(Element, Index) : nullptr;
}

UPsData* UPsDataBlueprintArrayProxy::Get(int32 Index) {
    return this->IsValid() && this->IsValidIndex(Index) ? Proxy.Get(Index) : nullptr;
}

int32 UPsDataBlueprintArrayProxy::Find(UPsData* Element) {
    return Element != nullptr && this->IsValid() ? Proxy.Find(Element) : -1;
}

int32 UPsDataBlueprintArrayProxy::Num() {
    return this->IsValid() ? Proxy.Num() : 0;
}

bool UPsDataBlueprintArrayProxy::IsEmpty() {
    return this->IsValid() ? Proxy.IsEmpty() : true;
}

bool UPsDataBlueprintArrayProxy::IsValidIndex(int32 Index) {
    return this->IsValid() ? Proxy.IsValidIndex(Index) : true;
}
