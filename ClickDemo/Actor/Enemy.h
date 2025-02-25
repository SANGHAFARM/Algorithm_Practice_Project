#pragma once
#include "Actor/DrawableActor.h"

#include <vector>

class Enemy : public DrawableActor
{
	// 적 캐릭터가 이동할 방향
	enum class Direction
	{
		None = -1,
		Up,
		Down,
		Left,
		Right
	};

	RTTI_DECLARATIONS(Enemy, DrawableActor)

public:
	Enemy(const char* image, int xPosition, int yPosition);

	// Enemy 이동 함수
	void EnemyMoves(std::vector<std::vector<int>>& map);

private:
	// 이동 방향
	Direction direction = Direction::None;
};

