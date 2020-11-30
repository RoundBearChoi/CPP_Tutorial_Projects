#pragma once

class Vec2
{
public:
	int x = 0;
	int y = 0;

	Vec2 operator+ (Vec2 param)
	{
		Vec2 temp;
		temp.x = x + param.x;
		temp.y = y + param.y;
		return temp;
	}

	Vec2 operator- (Vec2 param)
	{
		Vec2 temp;
		temp.x = x - param.x;
		temp.y = y - param.y;
		return temp;
	}

	void operator= (Vec2 param)
	{
		x = param.x;
		y = param.y;
	}

	bool operator== (Vec2 param)
	{
		if (x == param.x &&
			y == param.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};