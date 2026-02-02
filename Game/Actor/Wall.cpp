#include "Wall.h"

Wall::Wall(const Vector2& position)
	: Actor('#', position, Color::White)
{
	// 그리기 우선 순위 설정.
	sortingOrder = 0;
}