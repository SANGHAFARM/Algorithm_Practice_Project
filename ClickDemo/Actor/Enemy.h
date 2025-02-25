#pragma once
#include "Actor/DrawableActor.h"

#include <vector>

class Enemy : public DrawableActor
{
	// �� ĳ���Ͱ� �̵��� ����
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

	// Enemy �̵� �Լ�
	void EnemyMoves(std::vector<std::vector<int>>& map);

private:
	// �̵� ����
	Direction direction = Direction::None;
};

