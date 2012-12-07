/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		Physics
	Brief		Declaration of Physics namespace used for collision detection
*/

#ifndef _PHYSICS_HPP_
#define _PHYSICS_HPP_

class Player;
class Enemy;
class PickUp;

// 2D physics engine functions contained in a namespace physics
// functions to detect various collisions 
namespace Physics 
{
	// Collision detection algorithms that use the visitor pattern 
	// to simulate double dispatch with collision functions
	bool collision(Player &player, Enemy &enemy);
	bool collision(Player &player, PickUp &pickUp);
}

#endif // _PHYSICS_HPP_