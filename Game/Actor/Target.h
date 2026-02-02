#pragma once

#include "Actor/Actor.h"

using namespace Wanted;

class Target : public Actor
{
	RTTI_DECLARATIONS(Target, Actor)

public:
	// 위치 지정이 가능하도록 생성자 선언.
	Target(const Vector2& position);

};

