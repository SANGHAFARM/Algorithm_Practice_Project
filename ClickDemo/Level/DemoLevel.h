#pragma once

#include "Level/Level.h"
#include "Engine/Engine.h"

#include <vector>
#include <queue>

class Fence;
class Goal;
class Item;
class Player;
class Enemy;
class Node;

class DemoLevel : public Level
{
	// RTTI ����.
	RTTI_DECLARATIONS(DemoLevel, Level)

public:
	DemoLevel(int map);

	virtual void Update(float deltaTime) override;

private:
	// �ؽ�Ʈ ���Ϸ� ����� ���� �ҷ��ͼ� fenceMap�� ����
	void LoadMap(int map);

	// fenceMap�� ����� ������ �������� �� �׸���
	void InitializeMap();

	// A* �˰����� �����Ͽ� path�� queue ���·� ����
	void StartAStar(Vector2 newPosition);

	// path�� ����� ���� ������� �÷��̾� �̵�
	void GoThroughPath(float deltaTime);

	// ���� ��ġ�� Enemy ���� ����
	void SpawnEnemies(int enemyCount);

	// Enemy �̵� �Լ�
	void EnemyMoves(float deltaTime);

	// �÷��̾�� Enemy, Item, Goal �浹 ó��
	void ProcessCollisionPlayerAndEnemy();
	void ProcessCollisionPlayerAndItem();
	void ProcessCollisionPlayerAndGoal();

private:
	// �ؽ�Ʈ ������ ������ ������ 2���� �迭
	std::vector<std::vector<int>> fenceMap;

	// A* �˰������� ����� ���� ���
	std::queue<Vector2> path;

	// Actor ���� �迭
	std::vector<Fence*> fences;
	std::vector<Goal*> goals;
	std::vector<Item*> items;
	std::vector<Enemy*> enemies;

	// �÷��̾�
	Player* player;

	// �ʿ� �����ϴ� Item ����
	int itemCounts = 0;
};