/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		MenuState
	Brief		Declaration of MenuState class inherited from State
*/

#ifndef _MENUSTATE_H
#define _MENUSTATE_H

#include <Gosu\Audio.hpp>
#include <Gosu\Image.hpp>
#include <iostream>
#include "State.hpp"

/*
	Name		MenuState class
	Brief		The MenuState class contains the logic methods for 
				the menu state of the Divine Moments of Truth game
*/
class MenuState : public State
{
public:
	MenuState();
	~MenuState();
    virtual State* getNextState(Condition condition);
	virtual void initialise();
	virtual void deinitialise();
	virtual void update();
	virtual void draw();

private:
	Gosu::Image background_;
	Gosu::Image cursor_;
	Gosu::Song music_;
	double x_, y_;
};

#endif // _MENUSTATE_H