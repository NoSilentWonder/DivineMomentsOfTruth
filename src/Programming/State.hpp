/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		State
	Brief		Declaration of abstract base state class
*/

#ifndef STATE_H
#define STATE_H

#include "Condition.hpp"

/*
	Name		State class
	Brief		The State class is an abstract base class used as
				the inheritance base for the different states in the game
				such as title, menu, gameplay etc.
*/
class State
{
public:
	// Pure virtual function
    virtual State* getNextState(Condition condition) = 0;
	virtual void initialise() = 0;
	virtual void deinitialise() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

protected:
};

#endif // STATE_H