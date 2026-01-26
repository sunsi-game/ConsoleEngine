#pragma once

// STL
// 동적 배열.
#include <vector>

namespace Wanted
{
	// 전방 선언.
	class Actor;

	// 담당 임무 : 레벨에 있는 모든 엑터(물체) 관리.
	class Level
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
		std::vector<Actor*> actors;
	};

}
