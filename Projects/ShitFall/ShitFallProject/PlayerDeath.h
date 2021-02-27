#pragma once
#include "State.h"
#include "SlowUpdateMessage.h"

namespace RB
{
	class PlayerDeath : public State
	{
	private:
		bool startedSlowDown = false;

	public:
		PlayerDeath()
		{
			IF_COUT{ std::cout << "constructing State: PlayerDeath" << std::endl; }
			
		}

		~PlayerDeath()
		{
			IF_COUT{ std::cout << "destructing State: PlayerDeath" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			if (!startedSlowDown)
			{
				startedSlowDown = true;

				SlowUpdateMessage shit;
				shit.targetFrameDelay = 50;
				shit.targetType = GameObjType::individual_shit;

				SlowUpdateMessage gen;
				gen.targetFrameDelay = 50;
				gen.targetType = GameObjType::shitgroup;

				objData.AddSlowMoMessage(shit);
				objData.AddSlowMoMessage(gen);
			}
		}
	};
}