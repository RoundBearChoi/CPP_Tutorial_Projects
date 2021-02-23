#pragma once
#include <iostream>
#include "ObjController.h"
#include "TitleStateType.h"
#include "TitleIdle.h"
#include "TitleMoveDown.h"
#include "TitleMoveUp.h"

namespace RB
{
	class TitleController : public ObjController
	{
	public:
		TitleController()
		{
			std::cout << "constructing TitleController" << std::endl;

			MakeTransition((int)TitleStateType::START);
		}

		~TitleController() override
		{
			std::cout << "destructing TitleController" << std::endl;
			delete currentState;
		}

		void MakeTransition(int index) override
		{
			if (index == (int)TitleStateType::START)
			{
				CreateState<TitleIdle>();
			}
			else if (index == (int)TitleStateType::MOVE_DOWN)
			{
				CreateState<TitleMoveDown>();
			}
			else if (index == (int)TitleStateType::MOVE_UP)
			{
				CreateState<TitleMoveUp>();
			}
		}
	};
}