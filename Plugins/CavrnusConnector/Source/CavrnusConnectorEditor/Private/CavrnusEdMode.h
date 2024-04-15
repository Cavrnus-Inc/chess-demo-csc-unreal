// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EdMode.h"

/**
 * Editor mode for cavrnus platform.
 */
class FCavrnusEdMode : public FEdMode
{
public:
	FCavrnusEdMode();
	virtual ~FCavrnusEdMode();

public:
	const static FEditorModeID EM_CavrnusEditorModeID;
};
