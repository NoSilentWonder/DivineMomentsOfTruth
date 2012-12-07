/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		GameOverState
	Brief		Declaration of GameOverState class inherited from State
*/

#ifndef _GAMEOVERSTATE_H
#define _GAMEOVERSTATE_H

#include "State.hpp"

/*
	Name		GameOverState class
	Brief		The GameOverState class contains the logic methods for 
				the game over state of the Divine Moments of Truth game
*/
class GameOverState : public State
{
public:
	GameOverState();
	~GameOverState();
    virtual State* getNextState(Condition condition);
	virtual void initialise();
	virtual void deinitialise();
	virtual void update();
	virtual void draw();
private:
};

#endif // _GAMEOVERSTATE_H