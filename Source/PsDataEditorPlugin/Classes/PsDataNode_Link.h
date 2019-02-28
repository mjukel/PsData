// Copyright 2015-2019 Mail.Ru Group. All Rights Reserved.

#pragma once

#include "PsDataNode_Variable.h"

#include "CoreMinimal.h"

#include "PsDataNode_Link.generated.h"

UCLASS()
class PSDATAEDITORPLUGIN_API UPsDataNode_Link : public UPsDataNode_Variable
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY()
	FString Path;

	UPROPERTY()
	UClass* ReturnType;

	UPROPERTY()
	bool bCollection;

public:
	// Begin UEdGraphNode interface.
	virtual void AllocateDefaultPins() override;
	// End UEdGraphNode interface.

	// Begin UK2Node interface
	virtual bool IsNodePure() const override { return true; }
	virtual FText GetMenuCategory() const override;
	virtual FLinearColor GetNodeTitleColor() const override;
	virtual FSlateIcon GetIconAndTint(FLinearColor& OutColor) const override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	// End UK2Node interface.

	/** Set link path from meta data */
	void SetLinkPath(const FString& LinkPath);

	/** Update allocated pin */
	virtual void UpdatePin(EPsDataVariablePinType PinType, UEdGraphPin* Pin);

	/** Update function reference */
	virtual void UpdateFunctionReference();
};
