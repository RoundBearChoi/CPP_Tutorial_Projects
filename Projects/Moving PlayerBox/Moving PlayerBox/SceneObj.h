#pragma once
#include "StateController.h"
#include "UpdateData.h"

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
		UpdateData updateData;
		StateController* stateController = nullptr;

	public:
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
					stateController->ptrUpdateData = &updateData;
				}
			}
		}

		bool SetUpdateData()
		{
			if (stateController != nullptr)
			{
				stateController->ptrUpdateData = &updateData;
				return true;
			}

			return false;
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

		//temp

		void SetPos(float x, float y)
		{
			updateData.pos.x = x;
			updateData.pos.y = y;
		}
		
		void SetSpeed(float x, float y)
		{
			updateData.speed.x = x;
			updateData.speed.y = y;
		}
		
		olc::vf2d GetPos()
		{
			return updateData.pos;
		}
		
		olc::vf2d GetSpeed()
		{
			return updateData.speed;
		}

		void UpdatePos(float fElapsedTime, float xAxis)
		{
			if (xAxis > 0.0f)
			{
				updateData.pos += updateData.speed * fElapsedTime;
			}
			else if (xAxis < 0.0f)
			{
				updateData.pos -= updateData.speed * fElapsedTime;
			}
		}
	};
}