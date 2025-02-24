#include "Start.h"
#include "Engine/Engine.h"

Start::Start()
	: DrawableActor("s")
{
	color = Color::Red;
	position = Vector2(2, 2);
}

void Start::Update(float deltaTime)
{
	Super::Update(deltaTime);

	if (Engine::Get().GetKeyDown(VK_LBUTTON))
	{
		if (Engine::Get().MousePosition().x > 0 && Engine::Get().MousePosition().x < Engine::screenSize.x - 1 && Engine::Get().MousePosition().y > 0 && Engine::Get().MousePosition().y < Engine::screenSize.y - 1)
		{
			position = Engine::Get().MousePosition();
		}		
	}
}