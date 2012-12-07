/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
		
	Name		GameWindow
	Brief		Declaration of GameWindow Class which creates the game window
				and manages the game loop
	Details		Inherited from Gosu::Window
*/

#ifndef _GAME_WINDOW_H_
#define _GAME_WINDOW_H_

#include <Gosu/Window.hpp>

class State;
enum Condition;

/*
	Name		GameWindow class
	Brief		The GameWindow creates the game window
*/
class GameWindow : public Gosu::Window
{
public:
    GameWindow();
	~GameWindow();

	static GameWindow* instance();

	void initialise();
	void deinitialise();
	Condition getCondition() const { return condition_; };
	void setCondition(Condition condition);					// Sets the condition_ variable
	void changeCondition(Condition condition);				// Changes the condition_ variable and calls changeState

	void update();
	void draw();
private:	
	void changeState();

	State* currentState_;
	Condition condition_;

	static GameWindow* instance_;
};

#endif // _GAME_WINDOW_H_