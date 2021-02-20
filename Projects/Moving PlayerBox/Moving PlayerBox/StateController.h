#pragma once
#include "StateData.h"
#include "InputData.h"

namespace RB
{
    class StateController
    {
    protected:
        StateData stateData;
        VecData* vecDataHandle = nullptr;

    public:
        virtual bool MakeTransition(int index) = 0;
        virtual void CheckNextTransition() = 0;

        void Update(InputData &_inputData)
        {
            stateData.currentState->UpdateState(_inputData, *vecDataHandle);
        }

        void UU()
        {
            stateData.currentState->UUState();
        }

        void TargetVecData(VecData &vecData)
        {
            vecDataHandle = &vecData;
        }
    };
}