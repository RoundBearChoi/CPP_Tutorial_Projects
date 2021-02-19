#pragma once
#include "State.h"
#include "InputData.h"

namespace RB
{
    class StateController
    {
    protected:
        State* currentState = nullptr;
        PositionalData* positionalData = nullptr;
        int id = 0;

    public:
        virtual void MakeTransition(int index) = 0;

        ~StateController()
        {
            delete currentState;
        }

        template<class T>
        State* CreateState()
        {
            delete currentState;

            if (std::is_base_of<State, T>::value)
            {
                currentState = new T();
                return currentState;
            }
        }

        void Update(InputData &_inputData)
        {
            currentState->UpdateState(_inputData, *positionalData);
        }

        void TargetPositionalData(PositionalData &_positionalData)
        {
            positionalData = &_positionalData;
        }
    };
}