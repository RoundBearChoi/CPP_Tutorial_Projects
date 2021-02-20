#pragma once
#include "StateData.h"

namespace RB
{
    class StateController
    {
    protected:
        StateData stateData;

    public:
        UpdateData* ptrUpdateData = nullptr;
        virtual bool MakeTransition(int index) = 0;
        virtual void CheckNextTransition() = 0;

        void Update(float deltaTime, float inputXAxis)
        {
            ptrUpdateData->elapsedTime = deltaTime;
            stateData.currentState->UpdateState(*ptrUpdateData);
        }
    };
}