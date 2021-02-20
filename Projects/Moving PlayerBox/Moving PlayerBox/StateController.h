#pragma once
#include "StateData.h"
#include "UpdateData.h"
#include <iostream>

namespace RB
{
    class StateController
    {
    protected:
        StateData stateData;

    public:
        virtual bool MakeTransition(int index) = 0;
        virtual void CheckNextTransition() = 0;

        virtual ~StateController()
        {
            std::cout << "destructing StateController (virtual)" << std::endl;
        }

        void Update(UpdateData &updateData)
        {
            stateData.currentState->UpdateState(updateData);
        }
    };
}