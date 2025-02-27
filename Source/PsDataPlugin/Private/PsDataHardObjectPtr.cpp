// Copyright 2015-2019 Mail.Ru Group. All Rights Reserved.

#include "PsDataHardObjectPtr.h"

/***********************************
* UPsDataSingleton
***********************************/

UPsDataHardObjectPtrSingleton* UPsDataHardObjectPtrSingleton::Singleton = nullptr;

UPsDataHardObjectPtrSingleton::UPsDataHardObjectPtrSingleton(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UPsDataHardObjectPtrSingleton::Init()
{
	check(!Singleton);
	Singleton = NewObject<UPsDataHardObjectPtrSingleton>();
	Singleton->AddToRoot();
}

UPsDataHardObjectPtrSingleton* UPsDataHardObjectPtrSingleton::Get()
{
#if WITH_HOT_RELOAD
	if (!Singleton)
	{
		Init();
	}
	return Singleton;
#else
	check(Singleton);
	return Singleton;
#endif //WITH_HOT_RELOAD
}

void UPsDataHardObjectPtrSingleton::RetainObject(const UObject* Object)
{
	if (Object != nullptr)
	{
		auto& ObjectCounters = Get()->ObjectCounters;
		if (!ObjectCounters.Contains(Object))
		{
			ObjectCounters.Add(Object, 0);
		}

		auto& Count = ObjectCounters.FindChecked(Object);
		check(Count >= 0);
		Count++;
	}
}

void UPsDataHardObjectPtrSingleton::ReleaseObject(const UObject* Object)
{
	if (GExitPurge || IsIncrementalPurgePending())
	{
		return;
	}

	if (Object != nullptr)
	{
		auto& ObjectCounters = Get()->ObjectCounters;
		auto& Count = ObjectCounters.FindChecked(Object);
		check(Count > 0);
		--Count;
		if (Count == 0)
		{
			ObjectCounters.Remove(Object);
		}
	}
}
