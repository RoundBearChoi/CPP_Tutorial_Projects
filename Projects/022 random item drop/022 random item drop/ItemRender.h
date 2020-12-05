#pragma once

namespace Roundbeargames
{
	class ItemRender
	{
	protected:
		int renderID = 0;

	public:
		virtual void ShowImage() = 0;

		virtual ~ItemRender()
		{

		}

		void SetRenderID(int nIndex)
		{
			renderID = nIndex;
		}
	};
}