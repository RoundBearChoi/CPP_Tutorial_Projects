#pragma once
#include "olcPixelGameEngine.h"
#include "DevSettings.h"
#include <vector>

namespace RB
{
	class Input
	{
	private:
		std::vector<int> buffer_A;
		std::vector<int> buffer_D;

		bool Pressed_A = false;
		bool Pressed_D = false;

		bool bStartGame = false;
		bool bQuitGame = false;

	public:
		void UpdateInput(olc::PixelGameEngine* ptrEngine)
		{
			//A
			if (ptrEngine->GetKey(olc::Key::A).bPressed)
			{
				buffer_A.push_back(1);
				Pressed_A = true;
			}
			
			if (ptrEngine->GetKey(olc::Key::A).bReleased)
			{
				if (buffer_A.size() > 0)
				{
					buffer_A.erase(buffer_A.begin());
				}
			}

			//D
			if (ptrEngine->GetKey(olc::Key::D).bPressed)
			{
				buffer_D.push_back(1);
				Pressed_D = true;
			}

			if (ptrEngine->GetKey(olc::Key::D).bReleased)
			{
				if (buffer_D.size() > 0)
				{
					buffer_D.erase(buffer_D.begin());
				}
			}

			//start
			if (ptrEngine->GetKey(olc::Key::ENTER).bHeld)
			{
				bStartGame = true;
			}

		}

		int GetHorizontalAxis()
		{
			bool left = false;
			bool right = false;

			if (buffer_A.size() > 0 || Pressed_A)
			{
				left = true;
			}

			if (buffer_D.size() > 0 || Pressed_D)
			{
				right = true;
			}

			if (left && right || !left && !right)
			{
				return 0;
			}
			else if (left)
			{
				return -1;
			}
			else if (right)
			{
				return 1;
			}

			return 0;
		}

		void ClearKeyPress()
		{
			Pressed_A = false;
			Pressed_D = false;
		}

		bool StartGame()
		{
			return bStartGame;
		}

		bool GetESCPress(olc::PixelGameEngine* ptrEngine)
		{
			//quit
			if (ptrEngine->GetKey(olc::Key::ESCAPE).bHeld)
			{
				IF_COUT
				{
					std::cout << std::endl;
					std::cout << "---quitting---" << std::endl;
				}

				return true;
			}
			else
			{
				return false;
			}
		}

		bool GetYPress(olc::PixelGameEngine* ptrEngine)
		{
			if (ptrEngine->GetKey(olc::Key::Y).bHeld)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool GetNPress(olc::PixelGameEngine* ptrEngine)
		{
			if (ptrEngine->GetKey(olc::Key::N).bHeld)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	};
}