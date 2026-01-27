#include "Engine.h"
#include "Level/Level.h"
#include <iostream>
#include <Windows.h>

namespace Wanted {
	Engine::Engine()
	{
	}

	Engine::~Engine()
	{
		if (mainLevel)
		{
			delete mainLevel;
			mainLevel = nullptr;
		}
	}

	void Engine::Run()
	{
		// 시계의 정밀도
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency); //진동 수를 알아볼 수 있어, 정밀도를 알 수 있다.

		//프레임 계산용 변수
		//__int64
		int64_t currentTime = 0;
		int64_t previousTime = 0;
		
		// 하드웨어 타이머로 시간 구하기.
		LARGE_INTEGER time;
		QueryPerformanceCounter(&time); // 시간이 하드웨어 clock이다. 
		
		// 엔진 시작 직전에는 두 시간 값을 같게 맞춤.
		currentTime = time.QuadPart;
		previousTime = currentTime;

		// 기준 프레임(단위 : 초).
		float targetFrameRate = 240.0f;
		float oneFrameTime = 1.0f / targetFrameRate;


		// 엔진 루프 (게임 루프).
		while (!isQuit)
		{
			//현재 시간 구하기.
			QueryPerformanceCounter(&time);
			currentTime = time.QuadPart;

			// 프레임 시간 계산.
			float deltaTime
				= static_cast<float>(currentTime - previousTime);

			// 기준 좌표가 같게 하고 계산하는 것처럼.
			// 단위가 같아야 한다.
			// 초단위 변환.
			deltaTime = deltaTime
				/ static_cast<float>(frequency.QuadPart);
			
			// 고정 프레임 기법.
			if (deltaTime >= oneFrameTime)
			{
				ProcessInput();
				// 프레임 처리.
				BeginPlay();
				Tick(deltaTime);
				Draw();

				// 이전 시간 값 갱신.
				previousTime = currentTime;

				// 현재 입력 값을 이전 입력 값으로 저장
				for (int i = 0; i < 255; ++i)
				{
					keyStates[i].wasKeyDown 
						= keyStates[i].isKeyDown;
				}
			}
		}

		// Todo: 정리 작업.
		std::cout << "Engine has been shutdown....\n";
	}

	void Engine::QuitEngine()
	{
		isQuit = true;
	}

	bool Engine::GetKeyDown(int keyCode)
	{
		return keyStates[keyCode].isKeyDown
			&& !keyStates[keyCode].wasKeyDown;
	}

	bool Engine::GetKeyUp(int keyCode)
	{
		return !keyStates[keyCode].isKeyDown
			&& keyStates[keyCode].wasKeyDown;
	}

	bool Engine::GetKey(int keyCode)
	{
		return keyStates[keyCode].isKeyDown;
	}

	void Engine::SetNewLevel(Level* newLevel)
	{
		// 기존 레벨 있는지 확인.
		// 있으면 기존 레벨 제거.
		// Todo : 임시 코드. 레벨 전환할 때는 바로 제거하면 안됨.
		if (mainLevel)
		{
			delete mainLevel;
			mainLevel = nullptr;
		}

		// 레벨 설정.
		mainLevel = newLevel;
	}

	void Engine::ProcessInput() 
	{
		// 키 마다의 입력 읽기.
		// 운영체제가 제공하는 기능을 사용할 수 밖에 없음.
		for (int i = 0; i < 255; ++i)
		{
			keyStates[i].isKeyDown 
				= (GetAsyncKeyState(i) & 0x8000) > 0 ? true : false;
		}
	}

	void Engine::BeginPlay()
	{
		// 레벨이 있으면 이벤트 전달.
		if (!mainLevel)
		{
			// Silent is violent.
			// 침욱은 폭력이다.
			// -> 로그 메시지 남기자.
			std::cout << "mainLevel is empty.\n";
			return;
		}

		mainLevel->BeginPlay();
	}

	void Engine::Tick(float deltaTime)
	{
		// 프레임을 뒤집으면 순간 프레임이 나온다.
		// 원래는 1초간 기다려서 평균을 구하는 것이 맞는데
		// 엔진은 단순히 순간 프레임만 준다.

		//std::cout << "DeltaTime: " << deltaTime
		//	<< ", FPS: " << (1.0f / deltaTime) << "\n";
		//
		
		// ESC 키 눌리면 종료.
		if (GetKeyDown(VK_ESCAPE)) QuitEngine();
		
		if (!mainLevel)
		{
			std::cout << "Error: Engine::Tick().mainLevel is empty.\n";
			return;
		}

		mainLevel->Tick(deltaTime);
	}
	
	void Engine::Draw()
	{
		if (!mainLevel)
		{
			std::cout << "Error: Engine::Draw().mainLevel is empty.\n";
			return;
		}

		mainLevel->Draw();
	}
}