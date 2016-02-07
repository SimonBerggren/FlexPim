#pragma once
#include "State.h"

template<class T>
class StateMachine
{
	T* owner;
	State<T>* currState;
	State<T>* prevState;
	State<T>* globalState;

public:

	StateMachine(T* owner) : owner(owner), currState(nullptr), prevState(nullptr), globalState(nullptr) { }
	virtual ~StateMachine() {}
	void Update()
	{
		if (currState)
			currState->Execute(owner);

		if (globalState)
			globalState->Execute(owner);
	}

	void ChangeState(State<T>* newState)
	{
		prevState = currState;

		currState->Exit(owner);

		currState = newState;

		currState->Enter();
	}

	void GoToPrevState()
	{
		ChangeState(prevState);
	}

	bool IsInState(class State)
	{
		return dynamic_cast<State*>(currState);
	}

	State<T>* CurrentState() const { return currState; }
	State<T>* PrevState() const { return prevState; }
	State<T>* GlobalState() const { return globalState; }
};