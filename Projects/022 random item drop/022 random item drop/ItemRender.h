#pragma once

namespace Roundbeargames
{
	class ItemRender
	{
	public:
		void Render()
		{
			std::cout << R"(
Here's a random pistol.

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