/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		main
	Brief		Divine Moments of Truth game entry point
*/

#include "GameWindow.hpp"

/*
	Name		main
	Syntax		main()
	Return		int - May be used for debugging
	Brief		Standard program entry point
*/
int main()
{
    GameWindow* game;

	game = GameWindow::instance();	
	game->initialise();
	
	game->show();
	
	game->deinitialise();
	delete game;

    // Return
    return 0;
}