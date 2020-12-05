#pragma once
#include <iostream>
#include "ItemRender.h"

namespace Roundbeargames
{
	class ShotgunRender : public ItemRender
	{

	public:
		~ShotgunRender() override
		{
			std::cout << "destructing ShotgunRender: " << renderID << std::endl;
		}

		void ShowImage() override
		{
			std::cout << R"(
Here's a shotgun.

 ,______________________________________       
|_________________,----------._ [____]  ""-,__  __....-----=====
               (_(||||||||||||)___________/   ""                |
                  `----------'            "-,                   |
                                             `,  _,--....___    |
                                               `/           
)" << std::endl;
		}
	};
}