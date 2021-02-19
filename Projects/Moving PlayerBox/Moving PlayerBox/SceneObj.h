#pragma once
#include "StateController.h"
#include "PositionalData.h"
#include "InputData.h"

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
		PositionalData positionalData;
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
					stateController->TargetPositionalData(positionalData);
				}
			}
		}

		void TransitionController(int index)
		{
			stateController->MakeTransition(index);
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

			engine->DrawDecal(positionalData.pos + offset, decal);
		}

		//temp

		void SetPos(float x, float y)
		{
			positionalData.pos.x = x;
			positionalData.pos.y = y;
		}
		
		void SetSpeed(float x, float y)
		{
			positionalData.speed.x = x;
			positionalData.speed.y = y;
		}
		
		olc::vf2d GetPos()
		{
			return positionalData.pos;
		}
		
		olc::vf2d GetSpeed()
		{
			return positionalData.speed;
		}

		void UpdatePos(float fElapsedTime, float xAxis)
		{
			if (xAxis > 0.0f)
			{
				positionalData.pos += positionalData.speed * fElapsedTime;
			}
			else if (xAxis < 0.0f)
			{
				positionalData.pos -= positionalData.speed * fElapsedTime;
			}
		}
	};
}