#pragma once

template<class T>
struct State
{
	virtual void Enter(T*) = 0;
	virtual void Execute(T*) = 0;
	virtual void Exit(T*) = 0;
};