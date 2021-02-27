#pragma once
#include "SceneType.h"

namespace RB
{
	class GameData
	{
	public:
		int inputXAxis = 0;
		SceneType nextSceneType = SceneType::NONE;
		bool startGame = false;
		bool quitGame = false;
		bool yPressed = false;
		bool nPressed = false;
	};
}