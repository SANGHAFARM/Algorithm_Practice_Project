#include "Enemy.h"
#include "Engine/Engine.h"

Enemy::Enemy(const char* image, int xPosition, int yPosition) : DrawableActor(image)
{
	// 랜덤으로 이동할 방향 선택
	int random = Random(1, 10);
	if (random % 2 == 0)
	{
		// 짝수인 경우에는 좌/우로 이동하도록 설정
		direction = Direction::Left;		
	}
	else
	{
		// 홀수인 경우에는 위/아래로 이동하도록 설정
		direction = Direction::Up;
	}

	// 시작 위치 설정
	this->position = Vector2(xPosition, yPosition);
}

void Enemy::EnemyMoves(std::vector<std::vector<int>>& map)
{
	if (direction == Direction::Up)
	{
		if (map[position.y - 1][position.x] == 0)
		{
			position = Vector2(position.x, position.y - 1);
		}
		else
		{
			direction = Direction::Down;
		}
	}
	else if (direction == Direction::Down)
	{
		if (map[position.y + 1][position.x] == 0)
		{
			position = Vector2(position.x, position.y + 1);
		}
		else
		{
			direction = Direction::Up;
		}
	}
	else if (direction == Direction::Left)
	{
		if (map[position.y][position.x - 1] == 0)
		{
			position = Vector2(position.x - 1, position.y);
		}
		else
		{
			direction = Direction::Right;
		}
	}
	else if (direction == Direction::Right)
	{
		if (map[position.y][position.x + 1] == 0)
		{
			position = Vector2(position.x + 1, position.y);
		}
		else
		{
			direction = Direction::Left;
		}
	}
}
