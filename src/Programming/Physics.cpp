/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		Physics
	Brief		Declaration of Physics namespace used for collision detection
*/

#include "Physics.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "PickUp.hpp"

/*
	Name		Physics::collision
	Syntax		Physics::collision(Player &player, Enemy &enemy)
	Param		Player &player - The player
	Param		Enemy &enemy - Enemy to check for collision with
	Brief		Checks for a collision between the player and an enemy
*/
bool Physics::collision(Player &player, Enemy &enemy)
{
	Gosu::Image* enemyImage = enemy.getImage();
	
	if((pow((double)(enemy.getX() - player.getX()), 2) + pow((double)(enemy.getY() - player.getY()), 2)) 
	< pow((double)((player.getWidth()*0.5 - 10) + (enemyImage->width()*0.5 - 5)), 2))
		return true;
	else
	{
		return false;
	}
}

/*
	Name		Physics::collision
	Syntax		Physics::collision(Player &player, PickUp &pickUp)
	Param		Player &player - The player
	Param		PickUp &pickUp - PickUp to check for collision with
	Brief		Checks for a collision between the player and a pick up
*/
bool Physics::collision(Player &player, PickUp &pickUp)
{
	Gosu::Image* pickUpImage = pickUp.getImage();
	
	if((pow((double)(pickUp.getX() - player.getX()), 2) + pow((double)(pickUp.getY() - player.getY()), 2)) 
	< pow((double)(player.getWidth()*0.5 + pickUpImage->width()*0.5), 2))
		return true;
	else
	{
		return false;
	}
}