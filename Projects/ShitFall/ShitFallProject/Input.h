#pragma once
#include "olcPixelGameEngine.h"
#include "DevSettings.h"
#include <vector>

namespace RB
{
	class Input
	{
	private:
		bool Pressed_A = false;
		bool Pressed_D = false;

		bool Queued_A = false;
		bool Queued_D = false;

		bool bStartGame = false;
		bool bQuitGame = false;

	public:
		void UpdateInput(olc::PixelGameEngine* ptrEngine)
		{
			//A
			if (ptrEngine->GetKey(olc::Key::A).bPressed)
			{
				Pressed_A = true;
				Queued_A = true;
			}
			
			if (ptrEngine->GetKey(olc::Key::A).bReleased)
			{
				Pressed_A = false;
			}

			//D
			if (ptrEngine->GetKey(olc::Key::D).bPressed)
			{
				Pressed_D = true;
				Queued_D = true;
			}

			if (ptrEngine->GetKey(olc::Key::D).bReleased)
			{
				Pressed_D = false;
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

			if (Pressed_A || Queued_A)
			{
				left = true;
			}

			if (Pressed_D || Queued_D)
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

		void ClearKeyQueues()
		{
			Queued_A = false;
			Queued_D = false;
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