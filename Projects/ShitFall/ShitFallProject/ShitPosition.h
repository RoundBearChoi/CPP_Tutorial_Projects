#pragma once
#include "State.h"
#include "RandomInteger.h"
#include "olcPixelGameEngine.h"

namespace RB
{
	class ShitPosition : public State
	{
	private:
		RandomInteger randomInteger;
		olc::vf2d randomStart{ 0.0f, 0.0f };

	public:
		ShitPosition()
		{
			std::cout << std::endl;
			std::cout << "constructing State: ShitPosition" << std::endl;

			int x = randomInteger.GetInteger(0, 600);
			randomStart = { (float)x, -16.0f };
			//randomStart = { 300.0f - 25.0f - 16.0f, -16.0f };
		}

		~ShitPosition()
		{
			std::cout << std::endl;
			std::cout << "destructing State: ShitPosition" << std::endl;
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			objData.position = randomStart;

			objData.nextStateIndex = (int)ShitStateType::FALL;
		}
	};
}