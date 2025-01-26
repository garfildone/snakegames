// Snake Game, Copyright LifeEXE. All Rights Reserved.


#include "Framework/SG_GameMode.h"
#include "SG_GameMode.h"
#include "GSnake/Core/Types.h"
#include "GSnake/Core/Grid.h"
#include "World/SG_Grid.h"
#include "Framework/SG_Pawn.h"


void ASG_GameMode::StartPlay() 
{
    Super::StartPlay();

    // init core game
    const Snake::Settings GS{GridSize.X, GridSize.Y};
    Game = MakeUnique<Snake::Game>(GS);
    check(Game.IsValid());

    // init world grid
    const FTransform GridOrigin = FTransform::Identity;
    check(GetWorld());
    GridVisual = GetWorld()->SpawnActorDeferred<ASG_Grid>(GridVisualClass, GridOrigin);
    check(GridVisual);
    GridVisual->SetModel(Game->grid(), CellSize);
    GridVisual->FinishSpawning(GridOrigin);

    // set pawn location fitting grid in viewport
    auto* PC = GetWorld()->GetFirstPlayerController();
    check(PC);

    auto* Pawn = Cast<ASG_Pawn>(PC->GetPawn());
    check(Pawn)
    check(Game->grid().IsValid());
    Pawn->UpdateLocation(Game->grid()->dim(), CellSize, GridOrigin);
}
