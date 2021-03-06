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

			animationController.SetParams((int)GameSpriteType::ko_sheet_2, 800, 80, 5, 1, 5, false);
			animationController.data.transitionDelay = (int)TransitionDelayTable::PLAYER_DEATH;
			animationController.data.playOnce = true;
		}

		~PlayerDeath()
		{
			IF_COUT{ std::cout << "destructing State: PlayerDeath" << std::endl; }
		}

		void OnEnter(ObjData& objData, GameData& gameData) override
		{
			//change objsize
			objData.size.x = 160.0f;
			objData.size.y = 80.0f;

			//start slowmo
			SlowUpdateMessage shit;
			shit.targetFrameDelay = 80;
			shit.targetType = ObjTag::SHIT;
			
			SlowUpdateMessage gen;
			gen.targetFrameDelay = 80;
			gen.targetType = ObjTag::SHIT_GENERATOR;
			
			SlowUpdateMessage player;
			player.targetFrameDelay = 80;
			player.targetType = ObjTag::PLAYER;
			
			objData.vecSlowMoMessage.push_back(shit);
			objData.vecSlowMoMessage.push_back(gen);
			objData.vecSlowMoMessage.push_back(player);
			
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

		}
	};
}