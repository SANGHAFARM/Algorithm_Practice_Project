#include "Game.h"

#include "Level/MenuLevel.h"

Game* Game::instance = nullptr;

Game::Game()
	: Engine()
{
	instance = this;

	menuLevel = new MenuLevel();
}

Game::~Game()
{
	if (showMenu)
	{
		delete backLevel;
		backLevel = nullptr;
		mainLevel = nullptr;
	}
	else
	{
		delete mainLevel;
		mainLevel = nullptr;
	}

	delete menuLevel;
	menuLevel = nullptr;
}

void Game::ToggleMenu()
{
	//system("cls");
	//Clear();
	ClearImageBuffer();

	// 마우스/윈도우 이벤트 활성화.
	//static HANDLE inputHandle = GetStdHandle(STD_INPUT_HANDLE);
	//static int flag = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_PROCESSED_INPUT | ENABLE_EXTENDED_FLAGS;
	//SetConsoleMode(inputHandle, flag);

	showMenu = !showMenu;
	if (showMenu)
	{
		backLevel = mainLevel;
		mainLevel = menuLevel;
	}
	else
	{
		mainLevel = backLevel;
	}
}