#pragma once
#include "State.h"

namespace RB
{
	class TitleIdle : public State
	{
	public:
		TitleIdle()
		{
			std::cout << "constructing State: TitleIdle" << std::endl;
		}

		~TitleIdle()
		{
			std::cout << "destructing State: TitleIdle" << std::endl;
		}

		void UpdateState(ObjData& objData, const GameData& gameData)
		{
			objData.position = { 300.0f, 160.0f };
		}
	};
}