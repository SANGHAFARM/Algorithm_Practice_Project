#include "Engine/Engine.h"
#include "Level/DemoLevel.h"

int main()
{
	// �޸� ���� Ȯ��
	CheckMemoryLeak();

	Engine engine;
	engine.LoadLevel(new DemoLevel());
	engine.Run();
}