/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend

	Name		GameWindow
	Brief		The method definitions for the GameWindow class
*/

#include <Gosu/AutoLink.hpp>
#include "GameWindow.hpp"
#include "MenuState.hpp"
#include "PlayState.hpp"
#include "Constants.hpp"

GameWindow* GameWindow::instance_ = 0;

/*
	Name		GameWindow::instance
	Syntax		GameWindow::instance()
	Return		GameWindow*- Returns pointer to the single instance of GameWindow
	Brief		Create a single instance of GameWindow
*/
GameWindow* GameWindow::instance()
{
  if (!instance_)
      instance_ = new GameWindow();

  return instance_;
}

/*
	Name		GameWindow::GameWindow
	Syntax		GameWindow()
	Brief		GameWindow constructor initialises member variables
*/
GameWindow::GameWindow()
	: Window(SCREEN_WIDTH, SCREEN_HEIGHT, false, 20),
	  currentState_(0), 
	  condition_(CONDITION_GO_TO_MENU)
{
	setCaption(L"Divine Moments of Truth");
}

/*
	Name		GameWindow::~GameWindow
	Syntax		~GameWindow()
	Brief		GameWindow destructor
*/
GameWindow::~GameWindow()
{
}

/*
	Name		GameWindow::initialise
	Syntax		GameWindow::initialise()
	Brief		Initialises the modules used by the GameWindow
*/
void GameWindow::initialise()
{
	// Set initial state for the GameWindow
	currentState_ = new MenuState;
	currentState_->initialise();
}

/*
	Name		GameWindow::deinitialise
	Syntax		GameWindow::deinitialise()
	Brief		Releases any resources used by the GameWindow
*/
void GameWindow::deinitialise()
{
	if (currentState_)
	{
		currentState_->deinitialise();
		delete currentState_;
		currentState_ = NULL;
	}	
}

/*
	Name		GameWindow::setCondition
	Syntax		GameWindow::setCondition(Condition condition)
	Param		int condition - Condition to set 
	Brief		Sets the condition
*/
void GameWindow::setCondition(Condition condition)
{
	condition_ = condition;
}

/*
	Name		GameWindow::changeCondition
	Syntax		GameWindow::changeCondition(Condition condition)
	Param		Condition condition - Condition parameter used to determine the next state
	Brief		Changes the condition and requests a change of states if different
*/
void GameWindow::changeCondition(Condition condition)
{
	if (condition_ != condition)
	{
		condition_ = condition;
		changeState();
	}
}

/*
	Name		GameWindow::update
	Syntax		GameWindow::update()
	Brief		Updates the current state - time critial
*/
void GameWindow::update()
{
	currentState_->update();
}

/*
	Name		GameWindow::draw
	Syntax		GameWindow::draw()
	Brief		Renders the current state
*/
void GameWindow::draw()
{
	currentState_->draw();
}

/*
	Name		GameWindow::changeState
	Syntax		GameWindow::changeState()
	Brief		Changes the current state
*/
void GameWindow::changeState()
{
	if (currentState_)
	{
		State* state = currentState_->getNextState(condition_);

		if (state)
		{
			currentState_->deinitialise();
			delete currentState_;

			currentState_ = state;
			currentState_->initialise();
		}
	}
}
