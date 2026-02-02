#include <iostream>
#include "Engine/Engine.h"
#include "Level/SokobanLevel.h"
#include "Actor/Player.h"
#include "Game/Game.h"

using namespace Wanted;

int main()
{
	//Wanted::Engine engine;
	//engine.SetNewLevel(new SokobanLevel());
	//engine.Run();

	Game game;
	game.Run();
}