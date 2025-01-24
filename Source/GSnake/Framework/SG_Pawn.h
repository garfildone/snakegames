// Snake Game, Copyright LifeEXE. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Core/Types.h"
#include "SG_Pawn.generated.h"

class UCameraComponent;

UCLASS()
class GSNAKE_API ASG_Pawn : public APawn
{
	GENERATED_BODY()

public:
	ASG_Pawn();

	void UpdateLocation(const Snake::Dim& Dim, int32 CellSize, const FTransform& GridOrigin);

protected:
    UPROPERTY(VisibleAnywhere)
    USceneComponent* Origin;

	 UPROPERTY(VisibleAnywhere)
    UCameraComponent* Camera;

};
