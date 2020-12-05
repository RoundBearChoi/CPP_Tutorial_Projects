#pragma once
#include <iostream>
#include "ItemRender.h"

namespace Roundbeargames
{
	class PistolRender : public ItemRender
	{
	public:
		~PistolRender() override
		{
			std::cout << "destructing PistolRender: " << renderID << std::endl;
		}

		void ShowImage() override
		{
			std::cout << R"(
Here's a pistol.

 +--^----------,--------,-----,--------^-,
 | |||||||||   `--------'     |          O
 `+---------------------------^----------|
   `\_,---------,---------,--------------'
     / XXXXXX /'|       /'
    / XXXXXX /  `\    /'
   / XXXXXX /`-------'
  / XXXXXX /
 / XXXXXX /
(________(                
 `------'
)" << std::endl;
		}
	};
}