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

			//start slowmo
			SlowUpdateMessage shit;
			shit.targetFrameDelay = 80;
			shit.targetType = GameObjType::individual_shit;

			SlowUpdateMessage gen;
			gen.targetFrameDelay = 80;
			gen.targetType = GameObjType::shitgroup;

			SlowUpdateMessage player;
			player.targetFrameDelay = 80;
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
			specs.debugDecalIndex = (int)GameSpriteType::y_or_n460x330;
			specs.controllerType = ControllerType::TITLE_UI_CONTROLLER;
			specs.initialStateIndex = (int)UIElementStateType::Y_OR_N;

			objData.AddToCreationQueue(specs);
		}

		~PlayerDeath()
		{
			IF_COUT{ std::cout << "destructing State: PlayerDeath" << std::endl; }
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			if (slowDownTimer == 0)
			{
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

				slowDownTimer = 1;
			}
			else if (slowDownTimer < 0)
			{
				slowDownTimer++;
			}
		}
	};
}