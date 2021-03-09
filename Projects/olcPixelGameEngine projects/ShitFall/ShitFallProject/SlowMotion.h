#pragma once
#include <vector>
#include "SlowUpdate.h"

namespace RB
{
	class SlowMotion
	{
	private:
		std::vector<SlowUpdate> vecSlowUpdates;

	public:
		void UpdateSlowMoCounter()
		{
			for (int i = 0; i < vecSlowUpdates.size(); i++)
			{
				vecSlowUpdates[i].UpdateSlowMoCounter();
			}
		}

		bool SkipUpdate(ObjTag _targetType)
		{
			if (vecSlowUpdates.size() == 0)
			{
				return false;
			}

			for (int i = 0; i < vecSlowUpdates.size(); i++)
			{
				if (!vecSlowUpdates[i].CanUpdate())
				{
					if (_targetType == vecSlowUpdates[i].GetTargetType())
					{
						return true;
					}
				}
			}

			return false;
		}

		void AddSlowMo(GameObj* obj)
		{
			std::vector<SlowUpdateMessage>& vec = obj->data.vecSlowMoMessage;

			//go through every queue
			for (int i = 0; i < vec.size(); i++)
			{
				SlowUpdateMessage message = vec[i];

				if (vecSlowUpdates.size() > 0)
				{
					bool sameTargetFound = false;

					for (int sIndex = 0; sIndex < vecSlowUpdates.size(); sIndex++)
					{
						if (vecSlowUpdates[sIndex].GetTargetType() == message.targetType)
						{
							//change existing value
							vecSlowUpdates[sIndex].SetDelayTime(message.targetFrameDelay);
							sameTargetFound = true;
							break;
						}
					}

					if (!sameTargetFound)
					{
						//add new value
						SlowUpdate slowUpdate(message.targetType, message.targetFrameDelay);
						vecSlowUpdates.push_back(slowUpdate);
					}
				}
				else
				{
					//add new value
					SlowUpdate slowUpdate(message.targetType, message.targetFrameDelay);
					vecSlowUpdates.push_back(slowUpdate);
				}
			}

			if (vec.size() > 0)
			{
				vec.clear();
			}
		}
	};
}