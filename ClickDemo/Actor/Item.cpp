#include "Item.h"

Item::Item(Vector2 position)
	: DrawableActor("@")
{
	color = Color::Blue;
	this->position = position;
}
