#include "Game/Game.h"
#include "Level/DemoLevel.h"

int main()
{
	// �޸� ���� Ȯ��
	CheckMemoryLeak();

	Game game;
	game.Get().ToggleMenu();
	game.Run();
}