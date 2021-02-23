#pragma once
#include <iostream>
#include "ObjController.h"
#include "TitleStateType.h"
#include "TitleIdle.h"

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
		}
	};
}