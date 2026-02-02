#pragma once

#include "Actor/Actor.h"

using namespace Wanted;

class Ground : public Actor
{
	RTTI_DECLARATIONS(Ground, Actor)

public:
	// 위치 지정이 가능하도록 생성자 선언.
	Ground(const Vector2& position);
};