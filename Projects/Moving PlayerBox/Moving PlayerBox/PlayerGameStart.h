#pragma once
#include "State.h"
#include "PlayerStateType.h"

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

		void UpdateState(ObjData& objData, const GameData& gameData) override
		{
			objData.position = { 300.0f, 650.0f };
			nextStateIndex = (int)PlayerStateType::IDLE;
		}
	};
}