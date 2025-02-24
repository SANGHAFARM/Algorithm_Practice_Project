#pragma once

#include "Level/Level.h"
#include "Engine/Engine.h"

#include <vector>

class Fence;
class Start;
class Player;

class DemoLevel : public Level
{
	// RTTI Á¤ÀÇ.
	RTTI_DECLARATIONS(DemoLevel, Level)

public:
	DemoLevel();

	virtual void Update(float deltaTime) override;

private:
	void InitializeMap();

	void StartAStar();

	std::vector<Fence*> fences;

	std::vector<std::vector<int>> fenceMap;

	Start* start;
	Player* player;
};