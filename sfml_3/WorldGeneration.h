#pragma once
#include <iostream>
#include "Global.h"
#include "Brick.h"
#include "AI.h"
#include "TankPlayer.h"
#include "SecondPlayer.h"

class WorldGeneration{
public:
	WorldGeneration(){}
	~WorldGeneration(){}

	static void GenerateSingleGame();
	
	static void GenerateMultiplayerGame();
};