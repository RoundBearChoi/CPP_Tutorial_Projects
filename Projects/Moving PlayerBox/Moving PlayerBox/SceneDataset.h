#pragma once
#include "SceneObjList.h"
#include "Input.h"

namespace RB
{
	class SceneDataset
	{
	public:
		SceneObjList* ptrObjList = nullptr;
		Input* ptrInput = nullptr;
	};
}