#pragma once
#include "UpdateData.h"
#include "State.h"
#include <iostream>

namespace RB
{
    class StateController
    {
    public:
        State* currentState = nullptr;
        int nextState = 0;
        virtual bool MakeTransition(int index) = 0;
        virtual void CheckNextTransition() = 0;

        virtual ~StateController()
        {
            std::cout << "destructing StateController (virtual)" << std::endl;
            delete currentState;
        }

        template<class T>
        bool CreateState()
        {
            delete currentState;

            if (std::is_base_of<State, T>::value)
            {
                currentState = new T();
                currentState->nextStatePtr = &nextState;
                return true;
            }

            return false;
        }

        void Update(UpdateData &updateData)
        {
            currentState->UpdateState(updateData);
        }
    };
}