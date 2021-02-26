#pragma once
#include "ObjController.h"
#include "StateType.h"
#include "TitleFlicker.h"
#include "DevSettings.h"

namespace RB
{
	class PressEnterController : public ObjController
	{
	public:
		PressEnterController()
		{
			IF_COUT{ std::cout << "constructing PressEnterController" << std::endl; }
			
			MakeTransition((int)TitleStateType::FLICKER);
		}

		~PressEnterController() override
		{
			IF_COUT{ std::cout << "destructing PressEnterController" << std::endl; }

			delete currentState;
		}

		void MakeTransition(int index) override
		{
			if (index == (int)TitleStateType::FLICKER)
			{
				CreateState<TitleFlicker>();
			}
		}
	};
}