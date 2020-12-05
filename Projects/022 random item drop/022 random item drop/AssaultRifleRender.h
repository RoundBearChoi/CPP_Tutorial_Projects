#pragma once
#include <iostream>
#include "ItemRender.h"

namespace Roundbeargames
{
	class AssaultRifleRender : public ItemRender
	{
		~AssaultRifleRender() override
		{
			std::cout << "destructing AssaultRifleRender: " << renderID << std::endl;
		}

		void ShowImage() override
		{
			std::cout << R"(
Here's an assault rifle.

                         .-----------------TTTT_-----_______
                       /''''''''''(______O] ----------____  \______/]_
    __...---'"""\_ --''   Q                               ___________@
|'''                   ._   _______________=---------"""""""
|                ..--''|   l L |_l   |
|          ..--''      .  /-___j '   '
|    ..--''           /  ,       '   '
|--''                /           `    \
                     L__'         \    -
                                   -    '-.
                                    '.    /
                                      '-./
)" << std::endl;
		}
	};
}