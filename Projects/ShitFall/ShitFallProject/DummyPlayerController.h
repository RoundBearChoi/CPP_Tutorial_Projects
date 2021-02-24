#pragma once
#include "ObjController.h"
#include "StateType.h"
#include "PlayerDummy.h"

namespace RB
{
	class DummyPlayerController : public ObjController
	{
	public:
		DummyPlayerController()
		{
			std::cout << "constructing DummyPlayerController" << std::endl;

			MakeTransition((int)PlayerStateType::DUMMY);
		}

		~DummyPlayerController() override
		{
			std::cout << "destructing DummyPlayerController" << std::endl;
			delete currentState;
		}

		void MakeTransition(int index) override
		{
			if (index == (int)PlayerStateType::DUMMY)
			{
				CreateState<PlayerDummy>();
			}
		}
	};
}