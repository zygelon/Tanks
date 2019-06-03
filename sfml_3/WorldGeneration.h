#pragma once
#include <iostream>
#include "Global.h"
#include "Brick.h"
#include "AI.h"
#include "TankPlayer.h"
#include "SecondPlayer.h"
/*!
\brief This class just generate world for Singleplayer mode and Multiplayer Mode
*/
class WorldGeneration{
public:
	///do nothing
	WorldGeneration(){}
	///do nothing
	~WorldGeneration(){}
	///Generate singleplayer game
	static void GenerateSingleGame();
	///Generate multyplayer game
	static void GenerateMultiplayerGame();
};