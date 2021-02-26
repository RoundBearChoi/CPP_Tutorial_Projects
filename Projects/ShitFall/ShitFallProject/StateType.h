#pragma once

namespace RB
{
	enum class TitleStateType
	{
		NONE,

		IDLE_TEXT,
		MOVE_DOWN,
		MOVE_UP,

		FLICKER_ON,
		FLICKER_OFF,
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