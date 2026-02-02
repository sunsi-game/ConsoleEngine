#include "Wall.h"

Wall::Wall(const Vector2& position)
	: super('#', position, Color::White)
{
	// 그리기 우선 순위 설정.
	sortingOrder = 0;

}