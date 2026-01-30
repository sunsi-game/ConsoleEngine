#include "Player.h"
#include "Core/Input.h"
#include "Engine/Engine.h"
#include "Actor/Box.h"
#include "Level/Level.h"

#include <iostream>
#include <Windows.h>

using namespace Wanted;

Player::Player()
	: super('P', Vector2(2,3), Color::Red) //Actor() 같은 결과다.
{
	// 그리기 우선순위 높게 설정.
	sortingOrder = 10;
}

void Player::BeginPlay()
{
	// 상위 함수 호출.
	// C++는 부모함수 가리키는 포인터가 없음.
	Actor::BeginPlay();

	//std::cout << "TestActor::BeginPlay().\n";
}

void Player::Tick(float deltaTime)
{
	super::Tick(deltaTime); //Actor::Tick(dletaTime);

	// Q키 종료.
	if (Wanted::Input::Get().GetKeyDown('Q'))
	{
		// Todo: 게임 엔진 종료 요청.
		Wanted::Engine::Get().QuitEngine();
	}

	// 스페이스로 박스 생성.
	// vk -> virtual key.
	if (Input::Get().GetKeyDown(VK_SPACE))
	{
		// 박스 생성.
		if (owner)
		{
			owner->AddNewActor(new Box(GetPostion()));

		}
	}

	// 이동.
	// GetKey(VK_RIGHT)
	if (Input::Get().GetKey('D') && GetPostion().x < 20)
	{
		Vector2 newPosition = GetPostion();
		newPosition.x += 1;
		SetPostion(newPosition);
	}

	// GetKey(VK_LEFT)
	if (Input::Get().GetKey('A') && GetPostion().x > 0)
	{
		Vector2 newPosition = GetPostion();
		newPosition.x -= 1;
		SetPostion(newPosition);
	}

	// GetKey(VK_DOWN)
	if (Input::Get().GetKey('S') && GetPostion().y < 10)
	{
		Vector2 newPosition = GetPostion();
		newPosition.y += 1;
		SetPostion(newPosition);
	}

	// GetKey(VK_UP)
	if (Input::Get().GetKey('W') && GetPostion().y > 0)
	{
		Vector2 newPosition = GetPostion();
		newPosition.y -= 1;
		SetPostion(newPosition);
	}

	//std::cout 
	//	<< "TestActor::Tick(). deltaTime: " << deltaTime
	//	<< ", FPS: " << (1.0f / deltaTime) << "\n";
}

void Player::Draw()
{
	Actor::Draw();
}
