#include "Game/Game.h"
#include "Level/DemoLevel.h"

int main()
{
	// �޸� ���� Ȯ��
	CheckMemoryLeak();

	Game game;
	game.LoadLevel(new DemoLevel());
	game.Run();
}