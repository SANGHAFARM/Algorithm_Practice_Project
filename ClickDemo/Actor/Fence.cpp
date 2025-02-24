#include "Fence.h"

Fence::Fence(const char* image = "", int x = 0, int y = 0)
	: DrawableActor(image)
{
	color = Color::White;
	position = Vector2(x, y);
}
