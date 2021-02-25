#pragma once
#include "State.h"

namespace RB
{
	class TitleFlicker : public State
	{
	public:
		TitleFlicker()
		{
			std::cout << "constructing State: TitleFlicker" << std::endl;
		}

		~TitleFlicker()
		{
			std::cout << "destructing State: TitleFlicker" << std::endl;
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			objData.position = { 300.0f, 350.0f };
		}
	};
}