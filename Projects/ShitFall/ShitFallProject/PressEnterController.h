#pragma once
#include "ObjController.h"
#include "StateType.h"
#include "DevSettings.h"

#include "TitleFlickerOn.h"
#include "TitleFlickerOff.h"

namespace RB
{
	class PressEnterController : public ObjController
	{
	public:
		PressEnterController()
		{
			IF_COUT{ std::cout << "constructing PressEnterController" << std::endl; }
			
			MakeTransition((int)TitleStateType::FLICKER_ON);
		}

		~PressEnterController() override
		{
			IF_COUT{ std::cout << "destructing PressEnterController" << std::endl; }

			delete currentState;
		}

		void MakeTransition(int index) override
		{
			if (index == (int)TitleStateType::FLICKER_ON)
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