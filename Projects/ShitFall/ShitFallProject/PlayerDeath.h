#pragma once
#include "State.h"
#include "SlowUpdateMessage.h"
#include "GameSpriteType.h"

namespace RB
{
	class YesOrNo;

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
			shit.targetType = ObjTag::SHIT;
			
			SlowUpdateMessage gen;
			gen.targetFrameDelay = 50;
			gen.targetType = ObjTag::SHIT_GENERATOR;
			
			SlowUpdateMessage player;
			player.targetFrameDelay = 50;
			player.targetType = ObjTag::PLAYER;
			
			objData.AddSlowMoMessage(shit);
			objData.AddSlowMoMessage(gen);
			objData.AddSlowMoMessage(player);
			
			//show y or n
			State* newState = State::CreateState<YesOrNo>();
			vecCreateObjs.push_back(newState);

			ObjSpecs specs;
			specs.width = 460.0f;
			specs.height = 330.0f;
			specs.objTag = ObjTag::UI_ELEMENT;
			specs.offsetType = OffsetType::CENTER_CENTER;
			specs.decalIndex = (int)GameSpriteType::y_or_n460x330;
			vecCreationSpecs.push_back(specs);
		}

		void UpdateState(ObjData& objData, GameData& gameData) override
		{
			if (slowDownTimer == 0)
			{
				SlowUpdateMessage shit;
				shit.targetFrameDelay = 130;
				shit.targetType = ObjTag::SHIT;
			
				SlowUpdateMessage gen;
				gen.targetFrameDelay = 130;
				gen.targetType = ObjTag::SHIT_GENERATOR;
			
				SlowUpdateMessage player;
				player.targetFrameDelay = 130;
				player.targetType = ObjTag::PLAYER;
			
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