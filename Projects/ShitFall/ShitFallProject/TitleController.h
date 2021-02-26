#pragma once
#include <iostream>
#include "ObjController.h"
#include "TitleIdle.h"
#include "TitleMoveDown.h"
#include "TitleMoveUp.h"

namespace RB
{
	class TitleController : public ObjController
	{
	public:
		TitleController(int _initialStateIndex)
		{
			IF_COUT{ std::cout << "constructing TitleController" << std::endl; }
			
			MakeTransition(_initialStateIndex);
		}

		~TitleController() override
		{
			IF_COUT{ std::cout << "destructing TitleController" << std::endl; }

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