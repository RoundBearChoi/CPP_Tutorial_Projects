#pragma once
#include "State.h"
#include "UpdateData.h"
#include "PlayerStateType.h"

namespace RB
{
	class PlayerGameStart : public State
	{
	public:
		PlayerGameStart()
		{
			std::cout << "---constructing PlayerGameStart---" << std::endl;
		}

		~PlayerGameStart()
		{
			std::cout << "destructing PlayerGameStart" << std::endl;
		}

		void UpdateState(UpdateData &updateData) override
		{
			updateData.pos = { 300.0f, 650.0f };
			*nextStatePtr = (int)PlayerStateType::IDLE;
		}
	};
}