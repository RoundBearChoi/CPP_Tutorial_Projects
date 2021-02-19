#pragma once
#include "SceneObj.h"

namespace RB
{
	class State
	{
	public:
		virtual void UpdateState() = 0;

		virtual ~State()
		{

		}
	};
}