#pragma once
#include "State.h"
#include "SlowUpdateMessage.h"
#include "GameSpriteType.h"
#include "StateType.h"

namespace RB
{
	class PlayerDeath : public State
	{
	private:
		int slowDownTimer = 0;

	public:
		PlayerDeath()
		{
			IF_COUT{ std::cout << "constructing State: PlayerDeath" << std::endl; }
		}

		~PlayerDeath()
		{
			IF_COUT{ std::cout << "destructing State: PlayerDeath" << std::endl; }
		}

		void OnEnter(ObjData& objData, GameData& gameData) override
		{
			//start slowmo
			SlowUpdateMessage shit;
			shit.targetFrameDelay = 50;
			shit.targetType = GameObjType::individual_shit;

			SlowUpdateMessage gen;
			gen.targetFrameDelay = 50;
			gen.targetType = GameObjType::shitgroup;

			SlowUpdateMessage player;
			player.targetFrameDelay = 50;
			player.targetType = GameObjType::player;

			objData.AddSlowMoMessage(shit);
			objData.AddSlowMoMessage(gen);
			objData.AddSlowMoMessage(player);

			//show y or n
			ObjSpecs specs;
			specs.width = 460.0f;
			specs.height = 330.0f;
			specs.objType = GameObjType::y_or_n;
			specs.offsetType = OffsetType::CENTER_CENTER;
			specs.decalIndex = (int)GameSpriteType::y_or_n460x330;

			//objData.AddToCreationQueue(specs);
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			if (slowDownTimer == 0)
			{
				SlowUpdateMessage shit;
				shit.targetFrameDelay = 130;
				shit.targetType = GameObjType::individual_shit;
			
				SlowUpdateMessage gen;
				gen.targetFrameDelay = 130;
				gen.targetType = GameObjType::shitgroup;
			
				SlowUpdateMessage player;
				player.targetFrameDelay = 130;
				player.targetType = GameObjType::player;
			
				objData.AddSlowMoMessage(shit);
				objData.AddSlowMoMessage(gen);
				objData.AddSlowMoMessage(player);
			
				slowDownTimer = 1;
			}
			else if (slowDownTimer < 0)
			{
				slowDownTimer++;
			}
		}
	};
}