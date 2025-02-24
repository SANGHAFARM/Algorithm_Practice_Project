#include "DemoLevel.h"

#include "Engine/Engine.h"

#include "Actor/Player.h"
#include "Actor/Start.h"
#include "Actor/Fence.h"

#include "Algorithm/Node.h"
#include "Algorithm/AStar.h"

DemoLevel::DemoLevel()
{
	fenceMap.assign(Engine::screenSize.y, std::vector<int>(Engine::screenSize.x, 0));

	InitializeMap();

	start = new Start();
	if (start)
	{
		AddActor(start);
	}

	player = new Player();
	if (player)
	{
		AddActor(player);
	}
}

void DemoLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	if (Engine::Get().GetKeyDown(VK_RETURN))
	{
		StartAStar();
	}

	if (Engine::Get().GetKeyDown(VK_SPACE))
	{

	}
}

void DemoLevel::InitializeMap()
{
	// ȭ�� ���� x��ǥ/y��ǥ
	int screenSizeX = Engine::Get().ScreenSize().x;
	int screenSizeY = Engine::Get().ScreenSize().y;

	for (int i = 0; i < screenSizeX; i++)
	{
		Fence* fence1 = new Fence("#", i, 0);
		if (fence1)
		{
			AddActor(fence1);
			fences.emplace_back(fence1);
			fenceMap[fence1->Position().y][fence1->Position().x] = 1;
		}

		Fence* fence2 = new Fence("#", i, screenSizeY - 1);
		if (fence2)
		{
			AddActor(fence2);
			fences.emplace_back(fence2);
			fenceMap[fence2->Position().y][fence2->Position().x] = 1;
		}
	}

	for (int i = 1; i < screenSizeY - 1; i++)
	{
		Fence* fence1 = new Fence("#", 0, i);
		if (fence1)
		{
			AddActor(fence1);
			fences.emplace_back(fence1);
			fenceMap[fence1->Position().y][fence1->Position().x] = 1;
		}

		Fence* fence2 = new Fence("#", screenSizeX - 1, i);
		if (fence2)
		{
			AddActor(fence2);
			fences.emplace_back(fence2);
			fenceMap[fence2->Position().y][fence2->Position().x] = 1;
		}
	}
}

void DemoLevel::StartAStar()
{
	Node* startNode = new Node(start->Position());
	Node* goalNode = new Node(player->Position());

	AStar aStar;

	// ��� Ž��
	std::vector<Node*> path = aStar.FindPath(startNode, goalNode, fenceMap);

	// ��� Ȯ��
	if (!path.empty())
	{
		// �� ���
		std::cout << "��θ� �ʿ� ǥ���� ��� : \n";
		aStar.DisplayGridWithPath(fenceMap, path);
	}
	else
	{
		std::cout << "��θ� ã�� ���߽��ϴ�\n";
	}

	//SafeDelete(startNode);
	SafeDelete(goalNode);
}
