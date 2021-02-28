#pragma once
#include <iostream>
#include "StateController.h"

#include "BackgroundIdle.h"
#include "TitleIdle.h"
#include "TitleMoveDown.h"
#include "TitleMoveUp.h"
#include "TitleFlickerOn.h"
#include "TitleFlickerOff.h"
#include "YesOrNo.h"

namespace RB
{
	class UIElementController : public StateController
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
			delete currentState;
			currentStateIndex = index;

			if (index == (int)UIElementStateType::BACKGROUND_IDLE)
			{
				currentState = stateCreator.CreateState<BackgroundIdle>(objData);
			}
			else if (index == (int)UIElementStateType::TEXT_IDLE)
			{
				currentState = stateCreator.CreateState<TitleIdle>(objData);
			}
			else if (index == (int)UIElementStateType::MOVE_DOWN)
			{
				currentState = stateCreator.CreateState<TitleMoveDown>(objData);
			}
			else if (index == (int)UIElementStateType::MOVE_UP)
			{
				currentState = stateCreator.CreateState<TitleMoveUp>(objData);
			}
			else if (index == (int)UIElementStateType::FLICKER_ON)
			{
				currentState = stateCreator.CreateState<TitleFlickerOn>(objData);
			}
			else if (index == (int)UIElementStateType::FLICKER_OFF)
			{
				currentState = stateCreator.CreateState<TitleFlickerOff>(objData);
			}
			else if (index == (int)UIElementStateType::Y_OR_N)
			{
				currentState = stateCreator.CreateState<YesOrNo>(objData);
			}
		}
	};
}