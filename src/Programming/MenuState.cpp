/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		MenuState
	Brief		Definition of MenuState class methods
*/

#include <Gosu\Directories.hpp>
#include <sstream>

#include "MenuState.hpp"
#include "PlayState.hpp"
#include "InstructionsState.hpp"
#include "ExitState.hpp"
#include "GameWindow.hpp"
#include "ZOrder.hpp"
#include "Constants.hpp"

/*
	Name		MenuState::MenuState
	Syntax		MenuState()
	Brief		MenuState constructor initialises member variables
*/
MenuState::MenuState()
	: background_(GameWindow::instance()->graphics(), Gosu::sharedResourcePrefix() + L"assets/Menu.png"),
	  cursor_(GameWindow::instance()->graphics(), Gosu::sharedResourcePrefix() + L"assets/Cursor.png"),
	  music_(Gosu::sharedResourcePrefix() + L"Music/Menu Music.ogg")
{

}

/*
	Name		MenuState::~MenuState
	Syntax		~MenuState()
	Brief		MenuState destructor
*/
MenuState::~MenuState()
{

}

/*
	Name		MenuState::getNextState
	Syntax		MenuState::getNextState(Condition condition)
	Param		Condition condition - Condition parameter used to determine the next state
	Return		State* - A pointer to the next state type object
	Brief		Creates a new object of the next state type
*/
State* MenuState::getNextState(Condition condition)
{
	State* state = NULL;
    switch (condition) 
	{
		case CONDITION_GO_TO_PLAY : 
			state = new PlayState;
			break;

		case CONDITION_GO_TO_INSTRUCTIONS : 
			state = new InstructionsState;
			break;

		case CONDITION_GO_TO_EXIT : 
			state = new ExitState;
			break;

		default : 
			state = NULL;
			break;
	}
	return state;
}

/*
	Name		MenuState::initialise
	Syntax		MenuState::initialise()
	Brief		Initialises the state
*/
void MenuState::initialise()
{
	music_.play(true);
}

/*
	@Name		MenuState::deinitialise
	@Syntax		MenuState::deinitialise()
	@Brief		Deinitialises the state
*/
void MenuState::deinitialise()
{
	music_.stop();
}

/*
	Name		MenuState::update
	Syntax		MenuState::update()
	Brief		Updates the state
	Details		Time-critical logic updates are performed by this method
*/
void MenuState::update()
{
	x_ = GameWindow::instance()->input().mouseX();
	y_ = GameWindow::instance()->input().mouseY();

	// Handle mouse clicking on menu options for changing state
	// Using mouse position rather than buttons
	if (GameWindow::instance()->input().down(Gosu::msLeft))
	{
		if (GameWindow::instance()->input().mouseX() < 405 && 
			GameWindow::instance()->input().mouseY() > 330 &&
			GameWindow::instance()->input().mouseY() < 410)
			GameWindow::instance()->changeCondition(CONDITION_GO_TO_PLAY);
		else if (GameWindow::instance()->input().mouseX() < 405 && 
			GameWindow::instance()->input().mouseY() > 409 &&
			GameWindow::instance()->input().mouseY() < 490)
			GameWindow::instance()->changeCondition(CONDITION_GO_TO_INSTRUCTIONS);
		else if (GameWindow::instance()->input().mouseX() < 405 && 
			GameWindow::instance()->input().mouseY() > 489 &&
			GameWindow::instance()->input().mouseY() < 570)
			GameWindow::instance()->changeCondition(CONDITION_GO_TO_EXIT);
	}
}

/*
	Name		MenuState::draw
	Syntax		MenuState::draw()
	Brief		Renders the state
*/
void MenuState::draw()
{
	background_.draw(0, 0, Z_BACKGROUND);
	cursor_.draw(x_, y_, Z_UI);
}
