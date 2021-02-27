#pragma once
#include "State.h"
#include "StateType.h"

namespace RB
{
	class PlayerGameStart : public State
	{
	public:
		PlayerGameStart(ObjData& objData)
		{
			IF_COUT
			{
				std::cout << std::endl;
				std::cout << "constructing State: GameStart" << std::endl;
			}

			objData.position = { 300.0f, 650.0f };
		}

		~PlayerGameStart()
		{
			IF_COUT{ std::cout << "destructing State: GameStart" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			frameCount++;
			
			if (frameCount >= 20)
			{
				objData.nextStateIndex = (int)PlayerStateType::IDLE;
			}
		}
	};
}