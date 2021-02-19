#pragma once
#include "State.h"

namespace RB
{
    class StateController
    {
    protected:
        State* currentState = nullptr;
        int id = 0;

    public:
        ~StateController()
        {
            delete currentState;
        }

        void Update()
        {
            currentState->UpdateState();
        }

        virtual void MakeTransition(int index) = 0;

        template<class T>
        void CreateState()
        {
            delete currentState;
        
            if (std::is_base_of<State, T>::value)
            {
                currentState = new T();
            }
        }
    };
}