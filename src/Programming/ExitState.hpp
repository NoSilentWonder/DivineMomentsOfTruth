/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		ExitState
	Brief		Declaration of ExitState class inherited from State
*/

#ifndef _EXITSTATE_H
#define _EXITSTATE_H

#include <Gosu\Audio.hpp>
#include <Gosu\Image.hpp>
#include "State.hpp"

/*
	Name		ExitState class
	Brief		The ExitState class contains the logic methods for 
				the exit state of the Divine Moments of Truth game
*/
class ExitState : public State
{
public:
	ExitState();
	~ExitState();
    virtual State* getNextState(Condition condition);
	virtual void initialise();
	virtual void deinitialise();
	virtual void update();
	virtual void draw();

private:
	Gosu::Image background_;
	Gosu::Song music_;
};

#endif // _EXITSTATE_H