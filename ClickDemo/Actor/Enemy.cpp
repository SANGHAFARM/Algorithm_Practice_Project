#include "Enemy.h"
#include "Engine/Engine.h"

Enemy::Enemy(const char* image, int xPosition, int yPosition) : DrawableActor(image)
{
	// �������� �̵��� ���� ����
	int random = Random(1, 10);
	if (random % 2 == 0)
	{
		// ¦���� ��쿡�� ��/��� �̵��ϵ��� ����
		direction = Direction::Left;		
	}
	else
	{
		// Ȧ���� ��쿡�� ��/�Ʒ��� �̵��ϵ��� ����
		direction = Direction::Up;
	}

	// ���� ��ġ ����
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
