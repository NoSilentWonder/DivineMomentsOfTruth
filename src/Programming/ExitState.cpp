/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		ExitState
	Brief		Definition of ExitState class methods
*/

#include <Gosu\Directories.hpp>
#include <sstream>

#include "ExitState.hpp"
#include "MenuState.hpp"	
#include "GameWindow.hpp"
#include "ZOrder.hpp"


/*
	Name		ExitState::ExitState
	Syntax		ExitState()
	Brief		ExitState constructor initialises member variables
*/
ExitState::ExitState()
	: background_(GameWindow::instance()->graphics(), Gosu::sharedResourcePrefix() + L"assets/Credits.png"),
	  music_(Gosu::sharedResourcePrefix() + L"Music/Menu Music.ogg")
{
	
}

/*
	Name		ExitState::~ExitState
	Syntax		~ExitState()
	Brief		ExitState destructor
*/
ExitState::~ExitState()
{

}

/*
	Name		ExitState::getNextState
	Syntax		ExitState::getNextState(Condition condition)
	Param		Condition condition - Condition parameter used to determine the next state
	Return		State* - A pointer to the next state type object
	Brief		Creates a new object of the next state type
*/
State* ExitState::getNextState(Condition condition)
{
	State* state = NULL;
    switch (condition) 
	{
	case CONDITION_GO_TO_MENU:
		state = new MenuState;
		break;
	default : 
		state = NULL;
		break;
	}
	return state;
}

/*
	Name		ExitState::initialise
	Syntax		ExitState::initialise()
	Brief		Initialises the state
*/
void ExitState::initialise()
{
	music_.play(true);
}

/*
	@Name		ExitState::deinitialise
	@Syntax		ExitState::deinitialise()
	@Brief		Deinitialises the state
*/
void ExitState::deinitialise()
{
	music_.stop();
}

/*
	Name		ExitState::update
	Syntax		ExitState::update()
	Brief		Updates the state
	Details		Time-critical logic updates are performed by this method
*/
void ExitState::update()
{
	if (GameWindow::instance()->input().down(Gosu::kbSpace))
	{
		GameWindow::instance()->changeCondition(CONDITION_GO_TO_MENU);
	}
}

/*
	Name		ExitState::draw
	Syntax		ExitState::draw()
	Brief		Renders the state
*/
void ExitState::draw()
{
	background_.draw(0, 0, Z_BACKGROUND);
}
