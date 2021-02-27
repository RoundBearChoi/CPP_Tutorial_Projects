#pragma once

namespace RB
{
	class GameData
	{
	public:
		int inputXAxis = 0;
		int nextSceneIndex = 0;
		bool startGame = false;
		bool quitGame = false;
		bool yPressed = false;
		bool nPressed = false;
	};
}