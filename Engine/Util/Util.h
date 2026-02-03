#pragma once

#include "Math/Vector2.h"
#include "Math/Color.h"
using namespace Wanted;

// 헬퍼(Helper) 기능 제공.
namespace Util
{
	// 콘솔 커서 위치 이동(설정)하는 함수.
	inline void SetConsolePosition(const Vector2& position)
	{
		//COORD coord = {};
		//coord.X = static_cast<short>(position.x);
		//coord.Y = static_cast<short>(position.y);

		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),
			static_cast<COORD>(position)
		);
	}

	// 콘솔 텍스트 설정 함수.
	inline void SetConsoleTextColor(Color color)
	{
		SetConsoleTextAttribute(
			GetStdHandle(STD_OUTPUT_HANDLE),
			static_cast<unsigned short>(color)
		);
	}

	// 커서 끄기.
	inline void TurnOffCursor()
	{
		CONSOLE_CURSOR_INFO info = {};

		GetConsoleCursorInfo(
			GetStdHandle(STD_OUTPUT_HANDLE),
			&info
		);

		info.bVisible = false;
		SetConsoleCursorInfo(
			GetStdHandle(STD_OUTPUT_HANDLE),
			&info
		);
	}

	// 커서 켜기.
	inline void TurnOnCursor()
	{
		CONSOLE_CURSOR_INFO info = {};

		GetConsoleCursorInfo(
			GetStdHandle(STD_OUTPUT_HANDLE),
			&info
		);

		info.bVisible = true;
		SetConsoleCursorInfo(
			GetStdHandle(STD_OUTPUT_HANDLE),
			&info
		);
	}

}

// 메모리 정리 함수.
template<typename T>
void SafeDelete(T*& pointer)
{
	if (pointer)
	{
		delete pointer;
		pointer = nullptr;
	}
}

template<typename T>
void SafeDeleteArray(T*& pointer)
{
	if (pointer)
	{
		delete[] pointer;
		pointer = nullptr;
	}
}