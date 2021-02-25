#pragma once

namespace RB
{
	enum class TitleStateType
	{
		NONE,

		START,
		MOVE_DOWN,
		MOVE_UP,

		FLICKER,
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
		POSITION,
		FALL,
		SHIT_SPLASH,
	};
}