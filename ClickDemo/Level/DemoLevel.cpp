#include "DemoLevel.h"

#include "Engine/Engine.h"
#include "Game/Game.h"

#include "Actor/Fence.h"
#include "Actor/Goal.h"
#include "Actor/Item.h"
#include "Actor/Player.h"
#include "Actor/Enemy.h"

#include "Algorithm/Node.h"
#include "Algorithm/AStar.h"

DemoLevel::DemoLevel()
{
	LoadMap();

	InitializeMap();

	player = new Player();
	if (player)
	{
		AddActor(player);
	}

	SpawnEnemies(10);
}

void DemoLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	if (Engine::Get().GetKeyDown(VK_RETURN))
	{

	}

	if (Engine::Get().GetKeyDown(VK_RBUTTON))
	{
		if (Engine::Get().MousePosition().x > 0 && Engine::Get().MousePosition().x < Engine::screenSize.x - 1 && Engine::Get().MousePosition().y > 0 && Engine::Get().MousePosition().y < Engine::screenSize.y - 1)
		{	
			StartAStar(Engine::Get().MousePosition());
		}
	}

	GoThroughPath(deltaTime);

	EnemyMoves(deltaTime);

	ProcessCollisionPlayerAndEnemy();
	ProcessCollisionPlayerAndItem();
	ProcessCollisionPlayerAndGoal();
}

void DemoLevel::LoadMap()
{
	FILE* file = nullptr;
	fopen_s(&file, "../Assets/Map.txt", "rt");

	if (file)
	{
		char buffer[256] = {};

		while (!feof(file))
		{
			fgets(buffer, 256, file);

			std::vector<int> v;
			for (int i = 0; buffer[i] != '\0'; i++)
			{
				if (buffer[i] == '\n')
				{
					continue;
				}

				v.push_back(buffer[i] - '0');
			}

			fenceMap.push_back(v);
		}

		fclose(file);
	}
}

void DemoLevel::InitializeMap()
{
	for (int i = 0; i < fenceMap.size(); i++)
	{
		for (int j = 0; j < fenceMap[i].size(); j++)
		{
			if (fenceMap[i][j] == 1)
			{
				Fence* fence = new Fence("#", j, i);
				if (fence)
				{
					AddActor(fence);
					fences.emplace_back(fence);
				}
			}
			else if (fenceMap[i][j] == 2)
			{
				Item* item = new Item(Vector2(j, i));
				if (item)
				{
					AddActor(item);
					items.emplace_back(item);
				}

				itemCounts++;
			}
			else if (fenceMap[i][j] == 3)
			{
				Goal* goal = new Goal(Vector2(j, i));
				if (goal)
				{
					AddActor(goal);
					goals.emplace_back(goal);
				}
			}
		}
	}
}

void DemoLevel::StartAStar(Vector2 newPosition)
{
	path = std::queue<Vector2>();

	Node* startNode = new Node(player->Position());
	Node* goalNode = new Node(newPosition);

	AStar aStar;

	// °æ·Î Å½»ö
	std::vector<Node*> way = aStar.FindPath(startNode, goalNode, fenceMap);
	SafeDelete(goalNode);

	if (way.size() == 0)
	{
		return;
	}

	for (auto* w : way)
	{
		path.emplace(w->GetPosition());
	}

	if (!path.empty())
	{
		path.pop();
	}
}

void DemoLevel::GoThroughPath(float deltaTime)
{
	static float elapsedTime = 0.0f;
	static float moveTime = 0.15f;

	elapsedTime += deltaTime;
	if (elapsedTime < moveTime)
	{
		return;
	}

	elapsedTime = 0.0f;
		
	if (!path.empty())
	{
		Vector2 next = path.front();
		path.pop();

		player->SetPosition(next);
	}
}

void DemoLevel::SpawnEnemies(int enemyCount)
{
	int enemyCnt = 0;

	while (enemyCnt < enemyCount)
	{
		int randX = Random(1, Engine::screenSize.x - 2);
		int randY = Random(1, Engine::screenSize.y - 2);

		bool flag = false;
		for (int i = 0; i < enemies.size(); i++)
		{
			if (enemies[i]->Position() == Vector2(randX, randY))
			{
				flag = true;
				break;
			}
		}

		if (flag)
		{
			continue;
		}

		if (player->Position() != Vector2(randX, randY) && fenceMap[randY][randX] == 0)
		{
			Enemy* enemy = new Enemy("*", randX, randY);
			if (enemy)
			{
				enemies.emplace_back(enemy);
				AddActor(enemy);
				enemyCnt++;
			}
		}
	}
}

void DemoLevel::EnemyMoves(float deltaTime)
{
	static float elapsedTime = 0.0f;
	static float enemyMovesTime = 0.1f;

	elapsedTime += deltaTime;
	if (elapsedTime < enemyMovesTime)
	{
		return;
	}

	elapsedTime = 0.0f;

	for (auto* enemy : enemies)
	{
		enemy->EnemyMoves(fenceMap);
	}
}

void DemoLevel::ProcessCollisionPlayerAndEnemy()
{
	if (enemies.size() == 0)
	{
		return;
	}

	for (auto* enemy : enemies)
	{
		if (player->Position() == enemy->Position())
		{
			Game::Get().ToggleMenu();
		}
	}
}

void DemoLevel::ProcessCollisionPlayerAndItem()
{
	if (itemCounts == 0)
	{
		return;
	}

	for (int i = 0; i < items.size();)
	{
		if (items[i]->Position() == player->Position())
		{
			items[i]->Destroy();
			items[i] = nullptr;
			items.erase(items.begin() + i);
			itemCounts--;
			break;
		}

		++i;
	}
}

void DemoLevel::ProcessCollisionPlayerAndGoal()
{
	if (itemCounts > 0)
	{
		return;
	}

	for (auto* goal : goals)
	{
		if (player->Position() == goal->Position())
		{
			Game::Get().ToggleMenu();
		}
	}
}
