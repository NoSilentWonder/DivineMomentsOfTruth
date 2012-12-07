/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		PickUp
	Brief		Declaration of PickUp class
*/

#include <Gosu\Directories.hpp>
#include <math.h>
#include <Gosu\Math.hpp>
#include <sstream>

#include "PickUp.hpp"
#include "ZOrder.hpp"
#include "GameWindow.hpp"
#include "Constants.hpp"

/*
	Name		PickUp::PickUp
	Syntax		PickUp(Gosu::Graphics& graphics, const std::wstring& filename)
	Param		Gosu::Graphics& graphics - Handle to the graphics module
	Param		const std::wstring& filename
	Brief		PickUp constructor
*/
PickUp::PickUp(Gosu::Graphics& graphics, std::wstring& filename)
	: image_(graphics, filename), x_(0), y_(0), centreX_(CENTRE_X),
	  centreY_(CENTRE_Y), angle_(90), radius_(0), timer_(0), gone_(false),
	  reversing_(false)
{
}

/*
	Name		PickUp::PickUp
	Syntax		PickUp::update()
	Brief		Updates the pick up's position and state
*/
void PickUp::update()
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
	positionPickUp();
}

/*
	Name		PickUp::PickUp
	Syntax		PickUp::draw()
	Brief		Draws the pick up
*/
void PickUp::draw()
{
	image_.drawRot(x_, y_, Z_BETWEEN_MID_AND_BACKGROUND, angle_ + 180);
}

/*
	Name		PickUp::PickUp
	Syntax		PickUp::positionPickUp()
	Brief		Positions the pick up on the world
*/
void PickUp::positionPickUp()
{
	x_ = 0;
	y_ = radius_;
	double angle = Gosu::degreesToRadians(angle_);
	double tempX = (x_ * cos(angle)) - (y_ * sin(angle));
	y_ = (x_ * sin(angle)) + (y_ * cos(angle)) + centreX_;
	x_ = tempX + centreY_;
}