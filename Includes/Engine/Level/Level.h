#pragma once
#pragma warning(disable: 4251) // 미봉책(방법이 없어 어쩔 수 없이 사용한다.).

// STL
// 동적 배열.
#include <vector>
#include "Common/Common.h"

namespace Wanted
{
	// 전방 선언.
	class Actor;

	// 담당 임무 : 레벨에 있는 모든 엑터(물체) 관리.
	class WANTED_API Level
	{
	public :
		Level();
		virtual ~Level();

		// 게임 플레이 이벤트.
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
		virtual void Draw();

		// 액터 추가 함수.
		void AddNewActor(Actor* newActor);
		
	protected :
		// Actor 배열.
		// 템플릿은 dll로 넘길 수가 없다.
		// 1. 템플릿 사용 X
		// 2. 근데 템플릿을 꼭 사용해야 할려면 경고 수준을 낮춘다.
		// 3. C4251 경고 메시지 꺼버리기
		std::vector<Actor*> actors; // 다형성으로 관리하고 있다. 
	};

}
