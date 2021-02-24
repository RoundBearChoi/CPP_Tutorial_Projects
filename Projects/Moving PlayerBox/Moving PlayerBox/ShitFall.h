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
			std::cout << "constructing State: ShitFall" << std::endl;
		}

		~ShitFall()
		{
			std::cout << std::endl;
			std::cout << "destructing State: ShitFall" << std::endl;
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
					nextStateIndex = (int)ShitStateType::SHIT_SPLASH;
				}
			}
		}
	};
}