#include "MenuLevel.h"
#include "Game/Game.h"
#include "Level/DemoLevel.h"

MenuLevel::MenuLevel()
{
	menuItems.PushBack(new MenuItem("Restart Game", []() {
		Game::Get().ToggleMenu();
		Game::Get().LoadLevel(new DemoLevel()); })
	);
	menuItems.PushBack(new MenuItem("Quit Game", []() { Game::Get().QuitGame(); }));
	length = menuItems.Size();
}

MenuLevel::~MenuLevel()
{
	for (auto* item : menuItems)
	{
		delete item;
	}
}

void MenuLevel::Update(float deltaTime)
{
	if (Game::Get().GetKeyDown(VK_UP))
	{
		currentIndex = (currentIndex - 1 + length) % length;
	}
	if (Game::Get().GetKeyDown(VK_DOWN))
	{
		currentIndex = (currentIndex + 1) % length;
	}

	if (Game::Get().GetKeyDown(VK_RETURN))
	{
		menuItems[currentIndex]->onSelected();
		currentIndex = 0;
	}
}

void MenuLevel::Draw()
{
	Super::Draw();

	for (int ix = 0; ix < length; ++ix)
	{
		int x = Engine::Get().ScreenSize().x / 2 - 4;
		int y = Engine::Get().ScreenSize().y / 2 - 1 + ix;

		if (currentIndex == ix)
		{
			Engine::Get().Draw(Vector2(x, y), menuItems[ix]->menuText, selectedColor);
		}
		else
		{
			Engine::Get().Draw(Vector2(x, y), menuItems[ix]->menuText, unselectedColor);
		}
	}
}