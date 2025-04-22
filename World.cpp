#include "World.h"
#include "Actor.h"

#include "Player.h"
#include "Wall.h"

UWorld::UWorld()
{
	SpawnActor(new APlayer());
	SpawnActor(new AWall());
}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}
	Actors.clear();
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}

void UWorld::SpawnActor(AActor* NewActor)
{
	Actors.push_back(NewActor);
}

void UWorld::DestroyActor(AActor* DestroyedActor)
{
	Actors.erase(find(Actors.begin(), Actors.end(), DestroyedActor));
}

std::vector<AActor*>& UWorld::GetAllActors()
{
	return Actors;
}
