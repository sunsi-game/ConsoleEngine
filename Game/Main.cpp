#include <iostream>
#include "Engine/Engine.h"
#include "Level/TestLevel.h"
#include "Actor/TestActor.h"

using namespace Wanted;

int main()
{
	//Wanted::Engine engine;
	//engine.SetNewLevel(new TestLevel());
	//engine.Run();

	TestLevel* level = new TestLevel();
	Actor* actor = new TestActor(); // 성공.
	//Actor* actor = new Actor(); // 실패. -> 여기는 부모계층이라서 다르다.

	//TestActor* testActor = new TestActor();
	//if (actor->Is(testActor))
	//{
	//	std::cout << "actor is TestActor Type\n";
	//}
	//else
	//{
	//	std::cout << "actor is not TestActor Type\n";
	//}

	TestActor* testActor = actor->As<TestActor>(); // 형 변환 후 테스트 검사는 As를 통해 한다. -> 이 As는 RTTI.h.
	if (testActor)
	{
		std::cout << "actor is TestActor type.\n";
	}
	else
	{
		std::cout << "actor is not TestActor type.\n";
	}
}