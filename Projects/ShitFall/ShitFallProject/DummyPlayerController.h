#pragma once
#include "ObjController.h"
#include "StateType.h"
#include "PlayerDummy.h"
#include "DevSettings.h"

namespace RB
{
	class DummyPlayerController : public ObjController
	{
	public:
		DummyPlayerController(int _initialStateIndex)
		{
			IF_COUT{ std::cout << "constructing DummyPlayerController" << std::endl; }
			
			MakeTransition(_initialStateIndex);
		}

		~DummyPlayerController() override
		{
			IF_COUT{ std::cout << "destructing DummyPlayerController" << std::endl; }

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