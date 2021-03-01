#pragma once
#include "Scene.h"
#include "DecalLoader.h"
#include "GameDecalPath.h"

//states for game scene
#include "BackgroundIdle.h"
#include "PlayerGameStart.h"
#include "PlayerIdle.h"
#include "PlayerMoveLeft.h"
#include "PlayerMoveRight.h"
#include "ShitGenerator.h"
#include "ShitPosition.h"
#include "ShitMoveDown.h"
#include "ShitSplash.h"
#include "PlayerDeath.h"
#include "YesOrNo.h"

namespace RB
{
	class GameScene : public Scene
	{
	public:
		GameScene(DecalLoader* _decalLoader)
		{
			IF_COUT{ std::cout << "constructing GameScene" << std::endl; }
			
			decalLoader = _decalLoader;
		}

		~GameScene()
		{
			IF_COUT{ std::cout << "destructing GameScene" << std::endl; }
		}

		void InitScene() override
		{
			ObjSpecs background;
			ObjSpecs player;
			ObjSpecs shitgroup;

			background.width = 600.0f;
			background.height = 700.0f;
			background.objTag = ObjTag::NONE;
			background.offsetType = OffsetType::NONE;
			background.decalIndex = (int)GameSpriteType::background;
			
			player.width = 50.0f;
			player.height = 80.0f;
			player.objTag = ObjTag::PLAYER;
			player.offsetType = OffsetType::BOTTOM_CENTER;
			player.decalIndex = (int)GameSpriteType::playerbox_green;

			shitgroup.width = 0.0f;
			shitgroup.height = 0.0f;
			shitgroup.objTag = ObjTag::SHIT_GENERATOR;
			shitgroup.offsetType = OffsetType::CENTER_CENTER;
			shitgroup.decalIndex = (int)GameSpriteType::redbox_10x10;

			objList.CreateObj<BackgroundIdle>(background);
			objList.CreateObj<PlayerGameStart>(player);
			objList.CreateObj<ShitGenerator>(shitgroup);
		}

		void UpdateScene(olc::PixelGameEngine* ptrEngine, GameData& gameData) override
		{
			objList.UpdateObjs(gameData);
		}

		void RenderObjs(olc::PixelGameEngine* ptrEngine) override
		{
			//objList.RenderObjs(ptrEngine, decalLoader);

			GameObj* background = objList.GetObj(0);
			background->Render(ptrEngine, decalLoader->GetDecal(background->data.decalIndex));
		}

		void RenderStates(olc::PixelGameEngine* ptrEngine) override
		{
			objList.RenderStates(ptrEngine, decalLoader);
		}
	};
}