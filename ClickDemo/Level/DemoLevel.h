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
	// RTTI 정의.
	RTTI_DECLARATIONS(DemoLevel, Level)

public:
	DemoLevel(int map);

	virtual void Update(float deltaTime) override;

private:
	// 텍스트 파일로 저장된 값을 불러와서 fenceMap에 저장
	void LoadMap(int map);

	// fenceMap에 저장된 내용을 바탕으로 맵 그리기
	void InitializeMap();

	// A* 알고리즘을 실행하여 path에 queue 형태로 저장
	void StartAStar(Vector2 newPosition);

	// path에 저장된 값의 순서대로 플레이어 이동
	void GoThroughPath(float deltaTime);

	// 랜덤 위치에 Enemy 액터 생성
	void SpawnEnemies(int enemyCount);

	// Enemy 이동 함수
	void EnemyMoves(float deltaTime);

	// 플레이어와 Enemy, Item, Goal 충돌 처리
	void ProcessCollisionPlayerAndEnemy();
	void ProcessCollisionPlayerAndItem();
	void ProcessCollisionPlayerAndGoal();

private:
	// 텍스트 파일의 내용을 저장할 2차원 배열
	std::vector<std::vector<int>> fenceMap;

	// A* 알고리즘으로 저장된 최적 경로
	std::queue<Vector2> path;

	// Actor 저장 배열
	std::vector<Fence*> fences;
	std::vector<Goal*> goals;
	std::vector<Item*> items;
	std::vector<Enemy*> enemies;

	// 플레이어
	Player* player;

	// 맵에 존재하는 Item 개수
	int itemCounts = 0;
};