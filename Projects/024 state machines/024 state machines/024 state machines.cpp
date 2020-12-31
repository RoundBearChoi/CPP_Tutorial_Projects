#include <iostream>

class State
{
public:
    virtual void UpdateState() = 0;

    virtual ~State()
    {

    }
};

class StateA : public State
{
public:
    void UpdateState() override
    {
        std::cout << "updating state A" << std::endl;
    }

    StateA()
    {
        std::cout << "state A is created" << std::endl;
    }

    ~StateA() override
    {
        std::cout << "state A is destructed" << std::endl;
    }
};

class StateB : public State
{
public:
    void UpdateState() override
    {
        std::cout << "updating state B" << std::endl;
    }

    StateB()
    {
        std::cout << "state B is created" << std::endl;
    }

    ~StateB() override
    {
        std::cout << "state B is destructed" << std::endl;
    }
};

class StateC : public State
{
public:
    void UpdateState() override
    {
        std::cout << "updating state C" << std::endl;
    }

    StateC()
    {
        std::cout << "state C is created" << std::endl;
    }

    ~StateC() override
    {
        std::cout << "state C is destructed" << std::endl;
    }
};

class StateController
{
private:
    State* currentState = nullptr;

public:
    void Init()
    {
        currentState = new StateA();
    }

    void Update()
    {
        currentState->UpdateState();
    }

    void TransitionTo(char c)
    {
        delete currentState;

        if (c == 'a')
        {
            currentState = new StateA();
        }
        else if (c == 'b')
        {
            currentState = new StateB();
        }
        else
        {
            currentState = new StateC();
        }
    }

    ~StateController()
    {
        delete currentState;
    }
};

int main()
{
    StateController stateController;
    stateController.Init();

    std::string str = "n";

    while (str[0] != 'q')
    {
        stateController.Update();

        std::cin >> str;
        std::cout << std::endl;

        if (str[0] == 'a' || str[0] == 'b' || str[0] == 'c')
        {
            stateController.TransitionTo(str[0]);
        }
    }
}