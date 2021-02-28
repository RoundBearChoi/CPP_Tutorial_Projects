#pragma once
#include "State.h"

namespace RB
{
	class ShitFall : public State
	{
	private:
		float speed = 1.0f;

	public:
		ShitFall()
		{
			IF_COUT{ std::cout << "constructing State: ShitFall" << std::endl; }

			stateAnimation.SetParams((int)GameSpriteType::shit, 37, 37, 1, 1, 1, false);
		}

		~ShitFall()
		{
			IF_COUT
			{
				std::cout << std::endl;
				std::cout << "destructing State: ShitFall" << std::endl;
			}
		}

		void OnEnter(ObjData& objData, GameData& gameData) override
		{

		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			frameCount++;

			if (objData.collided)
			{
				//switch to a downward splash
			}
			else
			{
				if (objData.position.y < 630.0f)
				{
					speed = speed * 1.0122f;
					objData.position.y += speed;
				}
				else
				{
					//objData.nextStateIndex = (int)ShitStateType::SHIT_SPLASH;
				}
			}
		}
	};
}