#pragma once

#include "Actor/DrawableActor.h"

class Fence : public DrawableActor
{
	RTTI_DECLARATIONS(Fence, DrawableActor)

public:
	Fence(const char* image, int x, int y);
};