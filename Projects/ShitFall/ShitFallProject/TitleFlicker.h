#pragma once
#include "State.h"

namespace RB
{
	class TitleFlicker : public State
	{
	public:
		TitleFlicker()
		{
			IF_COUT{ std::cout << "constructing State: TitleFlicker" << std::endl; }
		}

		~TitleFlicker()
		{
			IF_COUT{ std::cout << "destructing State: TitleFlicker" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			objData.position = { 300.0f, 350.0f };
		}
	};
}