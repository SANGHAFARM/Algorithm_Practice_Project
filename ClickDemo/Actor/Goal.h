#pragma once

#include "Actor/DrawableActor.h"

class Goal : public DrawableActor
{
	RTTI_DECLARATIONS(Goal, DrawableActor)

public:
	Goal(Vector2 position);

};