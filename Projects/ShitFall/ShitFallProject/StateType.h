#pragma once

namespace RB
{
	enum class UIElementStateType
	{
		NONE,

		BACKGROUND_IDLE,

		TEXT_IDLE,
		MOVE_DOWN,
		MOVE_UP,

		FLICKER_ON,
		FLICKER_OFF,

		Y_OR_N,
	};

	enum class PlayerStateType
	{
		NONE,

		DUMMY,
		GAME_START,
		IDLE,
		MOVE_LEFT,
		MOVE_RIGHT,
		DEAD,
	};

	enum class ShitStateType
	{
		NONE,

		GENERATOR,
		RANDOM_POSITION,
		FALL,
		SHIT_SPLASH,
	};
}