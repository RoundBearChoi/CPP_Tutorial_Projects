#pragma once
#include "StateController.h"

namespace RB
{
	enum class RenderOffsetType
	{
		NONE,

		TOP_LEFT,
		TOP_CENTER,
		TOP_RIGHT,

		CENTER_LEFT,
		CENTER_CENTER,
		CENTER_RIGHT,

		BOTTOM_LEFT,
		BOTTOM_CENTER,
		BOTTOM_RIGHT,
	};

	class SceneObj
	{
	private:
		int id = 0;
		std::string name = "unassigned";
		StateController* stateController = nullptr;

	public:
		UpdateData updateData;

		~SceneObj()
		{
			delete stateController;
		}

		template<class T>
		void SetController()
		{
			if (stateController == nullptr)
			{
				if (std::is_base_of<StateController, T>::value)
				{
					stateController = new T();
				}
			}
		}

		StateController* GetController()
		{
			return stateController;
		}

		void Render(olc::PixelGameEngine* engine, olc::Decal* decal, RenderOffsetType renderOffset)
		{
			olc::vf2d offset(0.0f, 0.0f);
			float decalWidth = (float)(decal->sprite->width);
			float decalHeight = (float)(decal->sprite->height);

			if (renderOffset == RenderOffsetType::NONE)
			{
				// do nothing
			}
			else if (renderOffset == RenderOffsetType::CENTER_CENTER)
			{
				offset.x = -(decalWidth / 2.0f);
				offset.y = -(decalHeight / 2.0f);
			}
			else if (renderOffset == RenderOffsetType::BOTTOM_CENTER)
			{
				offset.x = -(decalWidth / 2.0f);
				offset.y = -(decalHeight);
			}

			engine->DrawDecal(updateData.pos + offset, decal);
		}

		void SetID(int _id)
		{
			id = _id;
		}

		void SetName(const std::string& _name)
		{
			name = _name;
		}
	};
}