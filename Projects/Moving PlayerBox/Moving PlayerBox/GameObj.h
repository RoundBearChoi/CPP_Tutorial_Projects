#pragma once
#include "PlayerController.h"

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

	class GameObj
	{
	private:
		int id = 0;
		std::string name = "unassigned";
		PlayerController* playerController = nullptr;

	public:
		UpdateData updateData;

		GameObj(int _id)
		{
			std::cout << "construcing GameObj: " << _id << std::endl;
			id = _id;
		}

		~GameObj()
		{
			std::cout << "destructing GameObj: " << id << std::endl;
			delete playerController;
		}

		template<class T>
		void SetController()
		{
			if (playerController == nullptr)
			{
				if (std::is_base_of<PlayerController, T>::value)
				{
					playerController = new T();
				}
			}
		}

		PlayerController* GetController()
		{
			return playerController;
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

		void SetName(const std::string& _name)
		{
			name = _name;
		}
	};
}