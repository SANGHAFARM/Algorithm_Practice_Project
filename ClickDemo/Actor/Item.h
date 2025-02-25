#pragma once

#include "Actor/DrawableActor.h"

class Item : public DrawableActor
{
	RTTI_DECLARATIONS(Item, DrawableActor)

public:
	Item(Vector2 position);

};