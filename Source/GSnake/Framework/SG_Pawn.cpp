// Snake Game, Copyright LifeEXE. All Rights Reserved.


#include "Framework/SG_Pawn.h"
#include "Camera/CameraComponent.h"

namespace
{
    float FOVTan(float FOVDegrees) 
    {
        return FMath::Tan(FMath::DegreesToRadians(FOVDegrees * 0.5f));
    }

    float VerticalFOV(float HorFOVDegrees, float ViewportAspectHW) 
    {
        return FMath::RadiansToDegrees(2.0f * FMath::Atan(FMath::Tan(FMath::DegreesToRadians(HorFOVDegrees) * 0.5f) * ViewportAspectHW));
    }
    } // namespace

ASG_Pawn::ASG_Pawn()
{
    PrimaryActorTick.bCanEverTick = false;

    Origin = CreateDefaultSubobject<USceneComponent>("Origin");
    check(Origin);
    SetRootComponent(Origin);

    Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
    check(Camera);
    Camera->SetupAttachment(Origin);
}

void ASG_Pawn::UpdateLocation(const Snake::Dim& Dim, int32 CellSize, const FTransform& GridOrigin) 
{
    const float WorldWidth = Dim.width * CellSize;
    const float WorldHeight = Dim.height * CellSize;

    float LocationZ = 0.0f;
    auto* Viewport = GEngine->GameViewport->Viewport;
    const float ViewportAspect = static_cast<float>(Viewport->GetSizeXY().Y) / Viewport->GetSizeXY().X;
    const float GridAspect = static_cast<float>(Dim.width) / Dim.height;

    if (ViewportAspect <= GridAspect)
    {
        LocationZ = WorldWidth / FOVTan(Camera->FieldOfView);
    }
    else
    {
        const float VFOV = VerticalFOV(Camera->FieldOfView, 1.0f / ViewportAspect);
        LocationZ = WorldHeight / FOVTan(VFOV);
    }

    const FVector NewPawnLocation = GridOrigin.GetLocation() + 0.5f * FVector(WorldHeight, WorldWidth, LocationZ);
    SetActorLocation(NewPawnLocation);
}

