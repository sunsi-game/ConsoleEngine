#include "TestLevel.h"
#include "Actor/Player.h"
#include "Actor/Wall.h"
#include "Actor/Ground.h"
#include "Actor/Box.h"
#include "Actor/Target.h"

#include <iostream>


TestLevel::TestLevel()
{
	// TestActor 액터를 레벨에 추가.
	// AddNewActor(new Player());
	LoadMap("Map.txt");
	//LoadMap("Stage1.txt");
}

void TestLevel::LoadMap(const char* filename)
{
	// 파일 로드.
	// 최종 파일 경로 만들기. ("../Assets/filename")
	char path[2048] = {};
	sprintf_s(path, 2048, "../Assets/%s", filename);

	// 파일 열기.
	FILE* file = nullptr;
	fopen_s(&file, path, "rt");

	// 예외 처리.
	if (!file)
	{
		// 표준 오류.
		std::cerr << "Failed to open Map file.\n";

		// 디버그 모드에서 중단점으로 중단해주는 기능.
		__debugbreak();
	}

	// 맵 읽기.
	// 맵 크기 파악 : File Position 포인터를 파일의 끝으로 이동.
	fseek(file, 0, SEEK_END);

	// 이 위치 읽기.
	size_t fileSize = ftell(file);

	// File Postion 처음으로 되돌리기.
	rewind(file);

	// 맵 데이터 저장용 버퍼 할당.
	char* data = new char[fileSize + 1];

	// 데이터 읽기.
	size_t readSize = fread(data, sizeof(char), fileSize, file);

	// 읽어온 문자열을 분석 (파싱 - Parsing)해서 출력
	// 인덱스르 사용해 한문자씩 읽기.
	int index = 0;

	// 객체를 생성할 위치 값.
	Wanted::Vector2 position;


	while (true)
	{
		// 종료	조건.
		if (index >= fileSize)
		{
			break;
		}

		// 캐릭터 읽기.
		char mapCharacter = data[index];
		++index;

		// 개행 문자 처리.
		if (mapCharacter == '\n')
		{
			//std::cout << std::endl;
			// y 좌표 증가, x 좌표 초기화.
			++position.y;
			position.x = 0;
			continue;
		}

		/*
		--- 맵 파일 예제 (Map.txt) ---
		# : 벽 (Wall)
		. : 바닥 (Floor)
		p : 플레이어 (Player)
		b : 상자 (Box)
		t : 목표 지점 (Target)
		--------------------------------
		*/

		// 한 문자 읽기.
		switch (mapCharacter)
		{
		case '#' :
		case '1' :
			//std::cout << "#";
			AddNewActor(new Wall(position));
			break;

		case '.':
			//std::cout << " ";
			AddNewActor(new Ground(position));
			break;

		case 'p':
			//std::cout << "P";
			// 플레이어는 이동 가능함.
			// 플레이어가 생성될 때 그 밑에 땅이 있어야 함.
			AddNewActor(new Player(position));
			AddNewActor(new Ground(position));
			break;

		case 'b':
			//std::cout << "B";
			// 박스는 이동 가능함.
			// 박스가 옮겨졌을 때 그 밑에 땅이 있어야 함.
			AddNewActor(new Box(position));
			AddNewActor(new Ground(position));
			break;

		case 't':
			//std::cout << "T";
			AddNewActor(new Target(position));
			break;
		}

		// x 좌표 증가 처리.
		++position.x;
	}

	// 사용한 버퍼 해제.
	delete[] data;
	
	// 파일이 정상적으로 열렸으면 닫기.
	fclose(file);
}
