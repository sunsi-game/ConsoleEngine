#pragma once

#include "Common/Common.h"

namespace Wanted
{
	// 이 클래스를 dll로 만들 때 dll에 접근해야 하는 클래스야.
	// 외부에도 접근가능한 클래스라면 __declspec(dllexport)를 앞에 사용해야 한다.
	class WANTED_API Actor
	{
	public :
		Actor();
		virtual ~Actor();

		// 게임 플레이 이벤트.
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		virtual void Draw();

		// Getter.
		inline bool HasBeganPlay() const { return hasBeganPlay; }
		bool IsActive() const { return isActive && !destroyRequested; }
		

	protected:
		// 이미 BeginPlay 이벤트를 받았는지 여부.
		bool hasBeganPlay = false;

		// 활성화 상태 여부.
		bool isActive = true;

		// 현재 프레임에 삭제 요청 받았는지 여부.
		bool destroyRequested = false;

	private :
	};
}

