#pragma once
#include "olcPixelGameEngine.h"
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

		bool A_Queued = false;
		bool D_Queued = false;

		bool bStartGame = false;
		bool bQuitGame = false;

	public:
		void UpdateInput(olc::PixelGameEngine* ptrEngine)
		{
			//A
			if (ptrEngine->GetKey(olc::Key::A).bPressed)
			{
				buffer_A.push_back(1);
				std::cout << "a pressed" << std::endl;
				Pressed_A = true;
			}
			
			if (ptrEngine->GetKey(olc::Key::A).bReleased)
			{
				if (buffer_A.size() > 0)
				{
					std::cout << "a released" << std::endl;
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

			//quit
			if (ptrEngine->GetKey(olc::Key::ESCAPE).bHeld)
			{
				bQuitGame = true;
			}
		}

		int GetHorizontalAxis()
		{
			bool left = false;
			bool right = false;

			if (buffer_A.size() > 0 || A_Queued)
			{
				left = true;
			}

			if (buffer_D.size() > 0 || D_Queued)
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

		void ClearQueue()
		{
			A_Queued = false;
			D_Queued = false;
		}

		void Queue()
		{
			if (Pressed_A)
			{
				A_Queued = true;
			}

			if (Pressed_D)
			{
				D_Queued = true;
			}

			Pressed_A = false;
			Pressed_D = false;
		}

		bool ESCPressed()
		{
			if (bQuitGame)
			{
				std::cout << std::endl;
				std::cout << "---quitting---" << std::endl;
				return true;
			}
			else
			{
				return false;
			}
		}

		bool StartGame()
		{
			return bStartGame;
		}
	};
}