#include "Target.h"

Target::Target(const Vector2& position)
	: super('T', position, Color::Green)
{
	// 그리기 우선 순위 설정.
	sortingOrder = 3;
}
