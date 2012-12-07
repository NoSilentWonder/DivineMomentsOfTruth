/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		GameOverState
	Brief		Definition of GameOverState class methods
*/

#include "GameOverState.hpp"
#include "MenuState.hpp"	
#include "GameWindow.hpp"

/*
	Name		GameOverState::GameOverState
	Syntax		GameOverState()
	Brief		GameOverState constructor initialises member variables
*/
GameOverState::GameOverState()
{
	
}

/*
	Name		GameOverState::~GameOverState
	Syntax		~GameOverState()
	Brief		GameOverState destructor
*/
GameOverState::~GameOverState()
{

}

/*
	Name		GameOverState::getNextState
	Syntax		GameOverState::getNextState(Condition condition)
	Param		Condition condition - Condition parameter used to determine the next state
	Return		State* - A pointer to the next state type object
	Brief		Creates a new object of the next state type
*/
State* GameOverState::getNextState(Condition condition)
{
	State* state = NULL;
    switch (condition) 
	{
		case CONDITION_GO_TO_MENU : 
			state = new MenuState;
			break;

		default : 
			state = NULL;
			break;
	}
	return state;
}

/*
	Name		GameOverState::initialise
	Syntax		GameOverState::initialise()
	Brief		Initialises the state
*/
void GameOverState::initialise()
{
}

/*
	@Name		GameOverState::deinitialise
	@Syntax		GameOverState::deinitialise()
	@Brief		Deinitialises the state
*/
void GameOverState::deinitialise()
{
	GameWindow::instance()->close();
}

/*
	Name		GameOverState::update
	Syntax		GameOverState::update()
	Brief		Updates the state
	Details		Time-critical logic updates are performed by this method
*/
void GameOverState::update()
{
	int YUFAIL = 0;
}

/*
	Name		GameOverState::draw
	Syntax		GameOverState::draw()
	Brief		Renders the state
*/
void GameOverState::draw()
{
		int YUFAIL = 0;
}
