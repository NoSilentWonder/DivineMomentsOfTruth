/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		Scenery
	Brief		Declaration of Scenery class
*/

#include <Gosu\Directories.hpp>
#include <math.h>
#include <Gosu\Math.hpp>
#include <sstream>

#include "Scenery.hpp"
#include "ZOrder.hpp"
#include "GameWindow.hpp"
#include "Constants.hpp"

/*
	Name		Scenery::Scenery
	Syntax		Scenery(Gosu::Graphics& graphics, const std::wstring& filename)
	Param		Gosu::Graphics& graphics - Handle to the graphics module
	Param		const std::wstring& filename
	Brief		Scenery constructor
*/
Scenery::Scenery(Gosu::Graphics& graphics, std::wstring& filename)
	: image_(graphics, filename), x_(0), y_(0), centreX_(CENTRE_X),
	  centreY_(CENTRE_Y), angle_(90), radius_(0), timer_(0), gone_(false),
	  reversing_(false)
{
}

/*
	Name		Scenery::Scenery
	Syntax		Scenery::update()
	Brief		Updates the scenery item's position and state
*/
void Scenery::update()
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
		if (radius_ > WORLD_RADIUS - 75)
		{
			radius_ -= 0.5;
		}
		else
			gone_ = true;
	}

	angle_--;
	if (angle_ < 0)
		angle_ = 359;
	positionScenery();
}

/*
	Name		Scenery::Scenery
	Syntax		Scenery::draw()
	Brief		Draws the scenery
*/
void Scenery::draw()
{
	image_.drawRot(x_, y_, Z_BETWEEN_MID_AND_BACKGROUND, angle_ + 180);
}

/*
	Name		Scenery::Scenery
	Syntax		Scenery::positionScenery()
	Brief		Positions the scenery on the world2 
*/
void Scenery::positionScenery()
{
	x_ = 0;
	y_ = radius_ + 30;
	double angle = Gosu::degreesToRadians(angle_);
	double tempX = (x_ * cos(angle)) - (y_ * sin(angle));
	y_ = (x_ * sin(angle)) + (y_ * cos(angle)) + centreX_;
	x_ = tempX + centreY_;
}