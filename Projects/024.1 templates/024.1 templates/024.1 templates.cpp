#include <iostream>

/*
void CreateState(char c)
{
	if (c == 'a')
	{

	}
	else if (c == 'b')
	{

	}
	else if (c == 'c')
	{

	}
}
*/

class State
{

};

class StateA : public State
{
public:
	StateA()
	{
		std::cout << "state A is constructed" << std::endl;
	}
};

class StateB : public State
{
public:
	StateB()
	{
		std::cout << "state B is constructed" << std::endl;
	}
};

class StateC : public State
{
public:
	StateC()
	{
		std::cout << "state C is constructed" << std::endl;
	}
};

template<class T>
void CreateState()
{
	bool condition = std::is_base_of<State, T>::value;

	if (condition == true)
	{
		T state;
	}
}

int main()
{
	CreateState<StateA>();
	CreateState<StateB>();
	CreateState<StateC>();
}