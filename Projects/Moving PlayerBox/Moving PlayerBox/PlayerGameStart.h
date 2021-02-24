#pragma once
#include "State.h"
#include "StateType.h"

namespace RB
{
	class PlayerGameStart : public State
	{
	public:
		PlayerGameStart()
		{
			std::cout << std::endl;
			std::cout << "constructing State: GameStart" << std::endl;
		}

		~PlayerGameStart()
		{
			std::cout << "destructing State: GameStart" << std::endl;
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			frameCount++;
			objData.position = { 300.0f, 650.0f };

			if (frameCount >= 20)
			{
				nextStateIndex = (int)PlayerStateType::IDLE;
			}
		}
	};
}