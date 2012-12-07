/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		InstructionsState
	Brief		Declaration of InstructionsState class inherited from State
*/

#ifndef _INSTRUCTIONSSTATE_H
#define _INSTRUCTIONSSTATE_H

#include <Gosu\Audio.hpp>
#include <Gosu\Image.hpp>
#include "State.hpp"

/*
	Name		InstructionsState class
	Brief		The InstructionsState class contains the logic methods for 
				the instructions state of the Divine Moments of Truth game
*/
class InstructionsState : public State
{
public:
	InstructionsState();
	~InstructionsState();
    virtual State* getNextState(Condition condition);
	virtual void initialise();
	virtual void deinitialise();
	virtual void update();
	virtual void draw();
	enum GameEvent { INSTRUCT1, INSTRUCT2, INSTRUCT3 } currentEvent_;

private:
	Gosu::Image background1_;
	Gosu::Image background2_;
	Gosu::Image background3_;
	Gosu::Song music_;

	bool spacePressed_;
};

#endif // _INSTRUCTIONSSTATE_H