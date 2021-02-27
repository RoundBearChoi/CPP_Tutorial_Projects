#pragma once
#include "State.h"
#include "DevSettings.h"

namespace RB
{
	class YesOrNo : public State
	{
	public:
		YesOrNo(ObjData& objData)
		{
			IF_COUT{ std::cout << "constructing State: YesOrNo" << std::endl; }

			objData.position = { 300.0f, 0.0f };
		}

		~YesOrNo()
		{
			IF_COUT{ std::cout << "destructing State: YesOrNo" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{

		}
	};
}