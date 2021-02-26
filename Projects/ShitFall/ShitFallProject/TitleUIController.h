#pragma once
#include <iostream>
#include "ObjController.h"

#include "TitleIdle.h"
#include "TitleMoveDown.h"
#include "TitleMoveUp.h"
#include "TitleFlickerOn.h"
#include "TitleFlickerOff.h"

namespace RB
{
	class TitleUIController : public ObjController
	{
	public:
		TitleUIController(int _initialStateIndex)
		{
			IF_COUT{ std::cout << "constructing TitleUIController" << std::endl; }

			MakeTransition(_initialStateIndex);
		}

		~TitleUIController() override
		{
			IF_COUT{ std::cout << "destructing TitleUIController" << std::endl; }

			delete currentState;
		}

		void MakeTransition(int index) override
		{
			if (index == (int)TitleStateType::IDLE_TEXT)
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
			else if (index == (int)TitleStateType::FLICKER_ON)
			{
				CreateState<TitleFlickerOn>();
			}
			else if (index == (int)TitleStateType::FLICKER_OFF)
			{
				CreateState<TitleFlickerOff>();
			}
		}
	};
}