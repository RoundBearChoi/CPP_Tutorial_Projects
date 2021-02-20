#pragma once
#include "StateData.h"
#include "UpdateData.h"

namespace RB
{
    class StateController
    {
    protected:
        StateData stateData;

    public:
        virtual bool MakeTransition(int index) = 0;
        virtual void CheckNextTransition() = 0;

        void Update(UpdateData &updateData)
        {
            stateData.currentState->UpdateState(updateData);
        }
    };
}