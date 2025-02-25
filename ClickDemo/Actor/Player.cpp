#include "Player.h"
#include "Engine/Engine.h"
#include "Game/Game.h"

Player::Player()
	: DrawableActor("i")
{
	color = Color::Green;
	position = Vector2(1, 1);
}

void Player::Update(float deltaTime)
{
	DrawableActor::Update(deltaTime);

	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		// 메뉴 토글
		Game::Get().ToggleMenu();
	}
}