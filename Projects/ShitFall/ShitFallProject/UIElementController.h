#pragma once
#include <iostream>
#include "ObjController.h"

#include "BackgroundIdle.h"
#include "TitleIdle.h"
#include "TitleMoveDown.h"
#include "TitleMoveUp.h"
#include "TitleFlickerOn.h"
#include "TitleFlickerOff.h"

namespace RB
{
	class UIElementController : public ObjController
	{
	public:
		UIElementController(int _initialStateIndex)
		{
			IF_COUT{ std::cout << "constructing TitleUIController" << std::endl; }

			MakeTransition(_initialStateIndex);
		}

		~UIElementController() override
		{
			IF_COUT{ std::cout << "destructing TitleUIController" << std::endl; }

			delete currentState;
		}

		void MakeTransition(int index) override
		{
			if (index == (int)UIElementStateType::BACKGROUND_IDLE)
			{
				CreateState<BackgroundIdle>(index);
			}
			else if (index == (int)UIElementStateType::TEXT_IDLE)
			{
				CreateState<TitleIdle>(index);
			}
			else if (index == (int)UIElementStateType::MOVE_DOWN)
			{
				CreateState<TitleMoveDown>(index);
			}
			else if (index == (int)UIElementStateType::MOVE_UP)
			{
				CreateState<TitleMoveUp>(index);
			}
			else if (index == (int)UIElementStateType::FLICKER_ON)
			{
				CreateState<TitleFlickerOn>(index);
			}
			else if (index == (int)UIElementStateType::FLICKER_OFF)
			{
				CreateState<TitleFlickerOff>(index);
			}
		}
	};
}