#pragma once
#include <iostream>
#include "GameData.h"

namespace RB
{
	class ObjController
	{
	public:
		virtual void UpdateObj(olc::vf2d& position, const GameData& updateData) = 0;
		virtual void CheckNextTransition() = 0;
		virtual bool MakeTransition(int index) = 0;

		virtual ~ObjController()
		{
			std::cout << "destructing ObjController (virtual)" << std::endl;
		}
	};
}