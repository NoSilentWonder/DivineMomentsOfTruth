/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		InstructionsState
	Brief		Definition of InstructionsState class methods
*/

#include <Gosu\Directories.hpp>
#include <sstream>

#include "InstructionsState.hpp"
#include "MenuState.hpp"	
#include "GameWindow.hpp"
#include "ZOrder.hpp"


/*
	Name		InstructionsState::InstructionsState
	Syntax		InstructionsState()
	Brief		InstructionsState constructor initialises member variables
*/
InstructionsState::InstructionsState()
	: background1_(GameWindow::instance()->graphics(), Gosu::sharedResourcePrefix() + L"assets/Instructions1.png"),
	  background2_(GameWindow::instance()->graphics(), Gosu::sharedResourcePrefix() + L"assets/Instructions2.png"),
	  background3_(GameWindow::instance()->graphics(), Gosu::sharedResourcePrefix() + L"assets/Instructions3.png"),
	  music_(Gosu::sharedResourcePrefix() + L"Music/Menu Music.ogg"), currentEvent_(INSTRUCT1),
	  spacePressed_(false)
{
	
}

/*
	Name		InstructionsState::~InstructionsState
	Syntax		~InstructionsState()
	Brief		InstructionsState destructor
*/
InstructionsState::~InstructionsState()
{

}

/*
	Name		InstructionsState::getNextState
	Syntax		InstructionsState::getNextState(Condition condition)
	Param		Condition condition - Condition parameter used to determine the next state
	Return		State* - A pointer to the next state type object
	Brief		Creates a new object of the next state type
*/
State* InstructionsState::getNextState(Condition condition)
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
	Name		InstructionsState::initialise
	Syntax		InstructionsState::initialise()
	Brief		Initialises the state
*/
void InstructionsState::initialise()
{
	music_.play(true);
}

/*
	@Name		InstructionsState::deinitialise
	@Syntax		InstructionsState::deinitialise()
	@Brief		Deinitialises the state
*/
void InstructionsState::deinitialise()
{
	music_.stop();
}

/*
	Name		InstructionsState::update
	Syntax		InstructionsState::update()
	Brief		Updates the state
	Details		Time-critical logic updates are performed by this method
*/
void InstructionsState::update()
{
	switch (currentEvent_)
	{
	case INSTRUCT1:
		if (GameWindow::instance()->input().down(Gosu::kbSpace))
		{
			if (!spacePressed_)
			{
				spacePressed_ = true;
				currentEvent_ = INSTRUCT2;
			}
		}
		else
		{
			spacePressed_ = false;
		}
		break;
	case INSTRUCT2:
		if (GameWindow::instance()->input().down(Gosu::kbSpace))
		{
			if (!spacePressed_)
			{
				spacePressed_ = true;
				currentEvent_ = INSTRUCT3;
			}
		}
		else
		{
			spacePressed_ = false;
		}
		break;
	case INSTRUCT3:
		
		if (GameWindow::instance()->input().down(Gosu::kbSpace))
		{
			if (!spacePressed_)
			{
				spacePressed_ = true;
				GameWindow::instance()->changeCondition(CONDITION_GO_TO_MENU);
			}
		}
		else
		{
			spacePressed_ = false;
		}
		break;
	default:
		break;
	}
}

/*
	Name		InstructionsState::draw
	Syntax		InstructionsState::draw()
	Brief		Renders the state
*/
void InstructionsState::draw()
{
	switch (currentEvent_)
	{
	case INSTRUCT1:
		background1_.draw(0, 0, Z_BACKGROUND);
		break;
	case INSTRUCT2:
		background2_.draw(0, 0, Z_BACKGROUND);
		break;
	case INSTRUCT3:
		background3_.draw(0, 0, Z_BACKGROUND);
		break;
	}
}
