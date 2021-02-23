#pragma once
#include "ObjSpecs.h"
#include "PlayerController.h"
#include "ShitGeneratorController.h"
#include "ShitFallController.h"
#include "RenderOffsetType.h"
#include "ObjData.h"

namespace RB
{
	class GameObj
	{
	private:
		GameObjType objType = GameObjType::NONE;
		ObjController* ptrController = nullptr;
		std::vector<GameObj*> vecChildrenPtr;

		void AddChild(int specIndex);

	public:
		ObjData data;

		GameObj(ObjSpecs specs);
		~GameObj();

		void UpdateChildren();
		bool IsObjType(GameObjType _objType);
		void Render(olc::PixelGameEngine* engine, olc::Decal* decal, RenderOffsetType renderOffset);

		void SetController(ControllerType _controllerType);
		ObjController* GetController();
	};
}