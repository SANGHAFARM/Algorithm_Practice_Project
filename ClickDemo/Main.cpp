#include "Game/Game.h"
#include "Level/DemoLevel.h"

int main()
{
	// 메모리 누수 확인
	CheckMemoryLeak();

	Game game;
	game.Get().ToggleMenu();
	game.Run();
}