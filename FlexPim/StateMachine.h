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
		if (globalState)
			globalState->Execute(owner);

		if (currState)
			currState->Execute(owner);
	}

	void ChangeState(State<T>* newState)
	{
		if (prevState)
			prevState = currState;

		if (currState)
			currState->Exit(owner);

		currState = newState;

		currState->Enter(owner);
	}

	void ChangeGlobalState(State<T>* newState)
	{
		if (globalState)
			globalState->Exit(owner);

		globalState = newState;

		globalState->Enter(owner);
	}

	void GoToPrevState()
	{
		ChangeState(prevState);
	}

	template <class T>
	bool IsInState()
	{
		return dynamic_cast<T*>(currState);
	}

	template <class T>
	bool IsInGlobalState()
	{
		return dynamic_cast<T*>(globalState);
	}

	State<T>* CurrentState() const { return currState; }
	State<T>* PrevState() const { return prevState; }
	State<T>* GlobalState() const { return globalState; }
};