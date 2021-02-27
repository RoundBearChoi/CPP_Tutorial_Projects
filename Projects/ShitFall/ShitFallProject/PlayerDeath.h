#pragma once
#include "State.h"
#include "SlowUpdateMessage.h"

namespace RB
{
	class PlayerDeath : public State
	{
	private:
		int slowDownTimer = 0;

	public:
		PlayerDeath(ObjData& objData)
		{
			IF_COUT{ std::cout << "constructing State: PlayerDeath" << std::endl; }

			SlowUpdateMessage shit;
			shit.targetFrameDelay = 30;
			shit.targetType = GameObjType::individual_shit;

			SlowUpdateMessage gen;
			gen.targetFrameDelay = 30;
			gen.targetType = GameObjType::shitgroup;

			SlowUpdateMessage player;
			player.targetFrameDelay = 30;
			player.targetType = GameObjType::player;

			objData.AddSlowMoMessage(shit);
			objData.AddSlowMoMessage(gen);
			objData.AddSlowMoMessage(player);
		}

		~PlayerDeath()
		{
			IF_COUT{ std::cout << "destructing State: PlayerDeath" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			if (slowDownTimer == 10)
			{
				SlowUpdateMessage shit;
				shit.targetFrameDelay = 0;
				shit.targetType = GameObjType::individual_shit;

				SlowUpdateMessage gen;
				gen.targetFrameDelay = 0;
				gen.targetType = GameObjType::shitgroup;

				SlowUpdateMessage player;
				player.targetFrameDelay = 0;
				player.targetType = GameObjType::player;

				objData.AddSlowMoMessage(shit);
				objData.AddSlowMoMessage(gen);
				objData.AddSlowMoMessage(player);

				slowDownTimer = 11;
			}
			else if (slowDownTimer < 10)
			{
				slowDownTimer++;
			}
		}
	};
}