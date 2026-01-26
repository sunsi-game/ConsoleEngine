#include "Level.h"
#include "Actor/Actor.h"

namespace Wanted
{
	Level::Level()
	{

	}
	Level::~Level()
	{
		// 메모리 정리.
		for (Actor*& actor : actors)
		{
			// 액터 객체 메모리 해제.
			if (actor)
			{
				delete actor;
				actor = nullptr;
			}
		}

		// 배열 초기화
		actors.clear();
	}

	void Level::BeginPlay()
	{
		// 액터에 이벤트 흘리기.
		for (Actor* actor : actors)
		{
			// 이미 BeginPlay 호출된 액터는 건너뛰기.
			if (actor->HasBeganPlay())
			{
				continue;
			}
		}
	}

	void Level::Tick(float deltaTime)
	{
		// 액터에 이벤트 흘리기.
		for (Actor* actor : actors)
		{
			actor->Tick(deltaTime);
		}
	}

	void Level::Draw()
	{
		// 액터에 이벤트 흘리기.
		for (Actor* actor : actors)
		{
			actor->Draw();
		}
	}
	void Level::AddNewActor(Actor* newActor)
	{
		// Todo: 나중에 프레임 처리 고려해서 따로 추가 작업 해야 함.
		// emplace_back과 push_back의 차이점
		actors.emplace_back(newActor); //R-value 고려하여 나온 함수다.

	}
}