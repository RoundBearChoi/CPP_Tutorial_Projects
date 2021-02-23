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

		void UpdateState(ObjData& objData, const GameData& gameData)
		{
			if (objData.position.y < 700.0f + 16.0f)
			{
				speed = speed * 1.0122f;
				objData.position.y += speed;
			}
		}
	};
}