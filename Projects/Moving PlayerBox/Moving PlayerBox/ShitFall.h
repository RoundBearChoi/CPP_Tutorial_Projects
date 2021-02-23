#pragma once
#include "State.h"

namespace RB
{
	class ShitFall : public State
	{
	private:
		float speed = 1.0f;
		bool collisionChecked = false;

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

		void UpdateState(ObjData& objData, const GameData& gameData) override
		{
			if (objData.position.y < 650.0f)
			{
				speed = speed * 1.0122f;
				objData.position.y += speed;
			}
			else
			{
				objData.position.y = 650.0f;
				nextStateIndex = (int)ShitStateType::SHIT_SPLASH;
			}

			float collisionHeight = 650.0f - 80.0f - 16.5f; // player bottom y - player height - half shit height

			//only need to check collision once
			if (objData.position.y > collisionHeight)
			{
				collisionChecked = true;
			}
		}
	};
}