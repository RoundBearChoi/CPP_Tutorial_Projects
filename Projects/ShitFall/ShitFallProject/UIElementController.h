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
		UIElementController(ObjData& objData, int _initialStateIndex)
		{
			IF_COUT{ std::cout << "constructing TitleUIController" << std::endl; }

			MakeTransition(objData, _initialStateIndex);
		}

		~UIElementController() override
		{
			IF_COUT{ std::cout << "destructing TitleUIController" << std::endl; }

			delete currentState;
		}

		void MakeTransition(ObjData& objData, int index) override
		{
			if (index == (int)UIElementStateType::BACKGROUND_IDLE)
			{
				CreateState<BackgroundIdle>(objData, index);
			}
			else if (index == (int)UIElementStateType::TEXT_IDLE)
			{
				CreateState<TitleIdle>(objData, index);
			}
			else if (index == (int)UIElementStateType::MOVE_DOWN)
			{
				CreateState<TitleMoveDown>(objData, index);
			}
			else if (index == (int)UIElementStateType::MOVE_UP)
			{
				CreateState<TitleMoveUp>(objData, index);
			}
			else if (index == (int)UIElementStateType::FLICKER_ON)
			{
				CreateState<TitleFlickerOn>(objData, index);
			}
			else if (index == (int)UIElementStateType::FLICKER_OFF)
			{
				CreateState<TitleFlickerOff>(objData, index);
			}
		}
	};
}