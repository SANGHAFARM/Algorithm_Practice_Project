#include "Goal.h"
#include "Engine/Engine.h"

Goal::Goal(Vector2 position)
	: DrawableActor("+")
{	
	color = Color::Red;	
	this->position = position;
}