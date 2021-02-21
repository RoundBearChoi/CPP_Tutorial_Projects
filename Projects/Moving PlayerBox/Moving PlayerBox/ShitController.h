#pragma once
#include "ObjController.h"
#include "ShitState.h"
#include "ShitStateType.h"
#include "ShitFall.h"

namespace RB
{
	class ShitController : public ObjController
	{
	public:
		ShitState* currentState = nullptr;
		int nextState = 0;

		ShitController()
		{
			std::cout << "constructing ShitController" << std::endl;

			MakeTransition((int)ShitStateType::FALL);
		}

		~ShitController() override
		{
			std::cout << "destructing ShitController" << std::endl;
			delete currentState;
		}

		virtual void UpdateObj(olc::vf2d& position, const GameData& updateData) override
		{

		}

		virtual void CheckNextTransition() override
		{

		}

		virtual bool MakeTransition(int index) override
		{
			if (index == (int)ShitStateType::FALL)
			{
				return CreateState<ShitFall>();
			}

			return false;
		}

		virtual bool MakeChildObj() override
		{
			return false;
		}

		template<class T>
		bool CreateState()
		{
			delete currentState;

			if (std::is_base_of<ShitState, T>::value)
			{
				currentState = new T();
				currentState->nextStatePtr = &nextState;
				return true;
			}

			return false;
		}
	};
}