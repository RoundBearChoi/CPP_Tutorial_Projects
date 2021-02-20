#pragma once
#include "StateData.h"
#include "InputData.h"

namespace RB
{
    class StateController
    {
    protected:
        StateData stateData;

    public:
        VecData* ptrVecData = nullptr;
        virtual bool MakeTransition(int index) = 0;
        virtual void CheckNextTransition() = 0;

        void Update(InputData &_inputData)
        {
            stateData.currentState->UpdateState(_inputData, *ptrVecData);
        }

        void UU()
        {
            if (stateData.currentState != nullptr)
            {
                stateData.currentState->UUState();
            }
        }
    };
}