#pragma once
#include <iostream>
#include "UpdateData.h"

namespace RB
{
	class ObjController
	{
	public:
		virtual void UpdateObj(UpdateData& updateData) = 0;
		virtual void CheckNextTransition() = 0;
		virtual bool MakeTransition(int index) = 0;

		virtual ~ObjController()
		{
			std::cout << "destructing ObjController (virtual)" << std::endl;
		}
	};
}