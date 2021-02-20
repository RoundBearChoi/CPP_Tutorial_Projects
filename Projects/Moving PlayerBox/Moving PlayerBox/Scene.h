#pragma once

namespace RB
{
	class Scene
	{
	private:
		DecalLoader decalLoader;
		Input input;
		SceneObjList sceneObjList;

	public:
		void InitScene()
		{
			decalLoader.LoadAll();

			sceneObjList.CreateObj("player");
			sceneObjList.CreateObj("background");

			sceneObjList.GetObj(0)->SetController<PlayerController>();
			sceneObjList.GetObj(0)->GetController()->MakeTransition((int)PlayerStateType::GAME_START);
		}

		void UpdateScene(olc::PixelGameEngine* ptrEngine, float deltaTime)
		{
			sceneObjList.UpdateAll(deltaTime, input.GetHorizontalAxis(ptrEngine));

			sceneObjList.GetObj(1)->Render(ptrEngine, decalLoader.background_decal, RenderOffsetType::NONE);
			sceneObjList.GetObj(0)->Render(ptrEngine, decalLoader.playerbox_green_decal, RenderOffsetType::BOTTOM_CENTER);
			sceneObjList.GetObj(0)->Render(ptrEngine, decalLoader.diamond_red_decal, RenderOffsetType::CENTER_CENTER);
		}
	};
}