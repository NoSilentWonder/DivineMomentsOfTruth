/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		Enemy
	Brief		Declaration of Enemy class
*/

#include <Gosu\Directories.hpp>
#include <math.h>
#include <Gosu\Math.hpp>
#include <sstream>

#include "Enemy.hpp"
#include "ZOrder.hpp"
#include "GameWindow.hpp"
#include "Constants.hpp"

/*
	Name		Enemy::Enemy
	Syntax		Enemy(Gosu::Graphics& graphics, const std::wstring& filename)
	Param		Gosu::Graphics& graphics - Handle to the graphics module
	Param		const std::wstring& filename
	Brief		Enemy constructor
*/
Enemy::Enemy(Gosu::Graphics& graphics, std::wstring& filename)
	: image_(graphics, filename), x_(0), y_(0), centreX_(CENTRE_X),
	  centreY_(CENTRE_Y), angle_(90), radius_(0), timer_(0), gone_(false),
	  reversing_(false)
{
}

/*
	Name		Enemy::Enemy
	Syntax		Enemy::update()
	Brief		Updates the enemy's position and state
*/
void Enemy::update()
{
	if (!reversing_)
	{
		if (radius_ < WORLD_RADIUS)
		{
			radius_ += 0.75;
		}
		else
		{
			timer_++;
		}
	}
	else
	{
		if (radius_ > WORLD_RADIUS - 50)
		{
			radius_ -= 0.5;
		}
		else
			gone_ = true;
	}

	angle_--;
	if (angle_ < 0)
		angle_ = 359;
	positionEnemy();
}

/*
	Name		Enemy::Enemy
	Syntax		Enemy::draw()
	Brief		Draws the enemy
*/
void Enemy::draw()
{
	image_.drawRot(x_, y_, Z_BETWEEN_MID_AND_BACKGROUND, angle_ + 180);
}

/*
	Name		Enemy::Enemy
	Syntax		Enemy::positionEnemy()
	Brief		Positions the enemy on the world
*/
void Enemy::positionEnemy()
{
	x_ = 0;
	y_ = radius_ + 5;
	double angle = Gosu::degreesToRadians(angle_);
	double tempX = (x_ * cos(angle)) - (y_ * sin(angle));
	y_ = (x_ * sin(angle)) + (y_ * cos(angle)) + centreX_;
	x_ = tempX + centreY_;
}