#pragma once
#include "olcPixelGameEngine.h"
#include <vector>

namespace RB
{
	enum class InputType
	{
		A_PRESSED,
		A_RELEASED,

		D_PRESSED,
		D_RELEASED,
	};

	class Input
	{
	private:
		std::vector<InputType> inputBuffer;
		bool MoveLeft_Is_Held = false;
		bool MoveRight_Is_Held = false;

		bool Process_A()
		{
			return ProcessKey(MoveLeft_Is_Held, InputType::A_PRESSED, InputType::A_RELEASED);
		}

		bool Process_D()
		{
			return ProcessKey(MoveRight_Is_Held, InputType::D_PRESSED, InputType::D_RELEASED);
		}

		bool ProcessKey(bool& isHeld, InputType pressKeyType, InputType releaseKeyType)
		{
			bool pressed = false;
			bool released = false;

			for (int i = 0; i < inputBuffer.size(); i++)
			{
				if (inputBuffer[i] == pressKeyType)
				{
					pressed = true;
				}

				if (inputBuffer[i] == releaseKeyType)
				{
					released = true;
				}
			}

			inputBuffer.clear();

			if (pressed && released)
			{
				isHeld = false;
				return true;
			}
			else if (pressed && !released)
			{
				isHeld = true;
				return true;
			}
			else if (!pressed && released)
			{
				isHeld = false;
				return false;
			}
			else
			{
				return false;
			}
		}

	public:
		void UpdateInput(olc::PixelGameEngine* ptrEngine)
		{
			//A
			if (ptrEngine->GetKey(olc::A).bPressed)
			{
				inputBuffer.push_back(InputType::A_PRESSED);
			}

			if (ptrEngine->GetKey(olc::A).bReleased)
			{
				inputBuffer.push_back(InputType::A_RELEASED);
			}

			//D
			if (ptrEngine->GetKey(olc::D).bPressed)
			{
				inputBuffer.push_back(InputType::D_PRESSED);
			}

			if (ptrEngine->GetKey(olc::D).bReleased)
			{
				inputBuffer.push_back(InputType::D_RELEASED);
			}
		}

		int GetxAxis()
		{
			// both pressed OR nothing pressed
			//if (MoveLeft() && MoveRight() || !MoveLeft() && !MoveRight())
			//{
			//	return 0;
			//}
			//else if (MoveLeft())
			//{
			//	return -1;
			//}
			//else if (MoveRight())
			//{
			//	return 1;
			//}

			//if (MoveLeft())
			//{
			//	return -1;
			//}
			//else
			//{
			//	return 0;
			//}

			if (MoveRight())
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

		bool MoveLeft()
		{
			if (Process_A())
			{
				return true;
			}
			else
			{
				if (MoveLeft_Is_Held)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}

		bool MoveRight()
		{
			if (Process_D())
			{
				return true;
			}
			else
			{
				if (MoveRight_Is_Held)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}

		/*
		int GetHorizontalAxis(olc::PixelGameEngine* ptrEngine)
		{
			if (ptrEngine->GetKey(olc::Key::A).bHeld)
			{
				bHeldLeft = true;
			}
			else
			{
				bHeldLeft = false;
			}

			if (ptrEngine->GetKey(olc::Key::D).bHeld)
			{
				bHeldRight = true;
			}
			else
			{
				bHeldRight = false;
			}

			// both pressed OR nothing pressed
			if (bHeldLeft && bHeldRight || !bHeldLeft && !bHeldRight)
			{
				return 0;
			}
			else
			{
				if (bHeldLeft)
				{
					return -1;
				}
				else if (bHeldRight)
				{
					return 1;
				}
			}

			return 0;
		}
		*/

		bool ESCPressed(olc::PixelGameEngine* ptrEngine)
		{
			if (ptrEngine->GetKey(olc::Key::ESCAPE).bHeld)
			{
				return true;
			}

			return false;
		}
	};
}