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
		UIElementController(int _initialStateIndex, ObjData& objData)
		{
			IF_COUT{ std::cout << "constructing TitleUIController" << std::endl; }

			MakeTransition(_initialStateIndex, objData);
		}

		~UIElementController() override
		{
			IF_COUT{ std::cout << "destructing TitleUIController" << std::endl; }

			delete currentState;
		}

		void MakeTransition(int index, ObjData& objData) override
		{
			if (index == (int)UIElementStateType::BACKGROUND_IDLE)
			{
				CreateState<BackgroundIdle>(index, objData);
			}
			else if (index == (int)UIElementStateType::TEXT_IDLE)
			{
				CreateState<TitleIdle>(index, objData);
			}
			else if (index == (int)UIElementStateType::MOVE_DOWN)
			{
				CreateState<TitleMoveDown>(index, objData);
			}
			else if (index == (int)UIElementStateType::MOVE_UP)
			{
				CreateState<TitleMoveUp>(index, objData);
			}
			else if (index == (int)UIElementStateType::FLICKER_ON)
			{
				CreateState<TitleFlickerOn>(index, objData);
			}
			else if (index == (int)UIElementStateType::FLICKER_OFF)
			{
				CreateState<TitleFlickerOff>(index, objData);
			}
		}
	};
}