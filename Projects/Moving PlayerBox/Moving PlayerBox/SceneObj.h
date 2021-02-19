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
		olc::vf2d pos = olc::vf2d(0.0f, 0.0f);
		olc::vf2d speed = olc::vf2d(0.0f, 0.0f);
		StateController* controller = nullptr;

	public:
		~SceneObj()
		{
			delete controller;
		}

		template<class T>
		void SetController()
		{
			//only set once
			if (controller == nullptr)
			{
				if (std::is_base_of<StateController, T>::value)
				{
					controller = new T();
				}
			}
		}

		void TransitionController(int index)
		{
			controller->MakeTransition(index);
		}

		void UpdateController()
		{
			controller->Update();
		}

		//temp

		void SetPos(float x, float y)
		{
			pos.x = x;
			pos.y = y;
		}

		void SetSpeed(float x, float y)
		{
			speed.x = x;
			speed.y = y;
		}

		olc::vf2d GetPos()
		{
			return pos;
		}

		olc::vf2d GetSpeed()
		{
			return speed;
		}

		void UpdatePos(float fElapsedTime, float xAxis)
		{
			if (xAxis > 0.0f)
			{
				pos += speed * fElapsedTime;
			}
			else if (xAxis < 0.0f)
			{
				pos -= speed * fElapsedTime;
			}
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

			engine->DrawDecal(pos + offset, decal);
		}
	};
}