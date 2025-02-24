#include "Player.h"
#include "Engine/Engine.h"

Player::Player()
	: DrawableActor("e")
{
	color = Color::Green;
	position = Vector2(9, 5);
}

void Player::Update(float deltaTime)
{
	DrawableActor::Update(deltaTime);

	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}

	if (Engine::Get().GetKeyDown(VK_RBUTTON))
	{
		if (Engine::Get().MousePosition().x > 0 && Engine::Get().MousePosition().x < Engine::screenSize.x - 1 && Engine::Get().MousePosition().y > 0 && Engine::Get().MousePosition().y < Engine::screenSize.y - 1)
		{
			position = Engine::Get().MousePosition();
		}
	}
}