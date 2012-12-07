/*
	Copyright	Divine Moments of Truth 2011
	Created 	Jonathan Jones
				Elinor Townsend
	
	Name		Player
	Brief		Declaration of Player class
*/

#include <Gosu\Directories.hpp>
#include <math.h>
#include <Gosu\Math.hpp>
#include <Gosu\Timing.hpp>
#include <sstream>
#include <Gosu\Input.hpp>

#include "Player.hpp"
#include "ZOrder.hpp"
#include "GameWindow.hpp"
#include "Constants.hpp"

/*
	Name		Player::Player
	Syntax		Player(Gosu::Graphics& graphics)
	Param		Gosu::Graphics& graphics - Handle to the graphics module
	Brief		Player constructor
*/
Player::Player(Gosu::Graphics& graphics):
x_(0),
y_(0),
angle_(180),
radius_(WORLD_RADIUS),
jumpOffset_(0),
zPressed_(false),
hasJumped_(false),
jumpingUp_(false),
falling_(false),
MAX_JUMP_HEIGHT_(70),
JUMP_VELOCITY_(4.0),
addiction_(0.1),
powerCircle_(graphics, Gosu::sharedResourcePrefix() + L"assets/Circle.png"),
powerCircleScaleFactor_(1),
powerCircleIncreasing_(false), 
powerCircleDecreasing_(true),
playerState_(PLAYER_STATE_MED_HIGH),
addictionMaximum_(0)
//Jump(Gosu::sharedResourcePrefix() + L"media/N Music.wav")
{
	std::wstring filename = Gosu::sharedResourcePrefix() + L"assets/Charlie sheet2.png";
	Gosu::imagesFromTiledBitmap(graphics, filename, 50, 50, false, playerAnim_);
 
	// Set alpha 
	powerCircleColour_.setAlpha(255);

	// Set red value
	double red = Gosu::random(40,255);
	powerCircleColour_.setRed(static_cast<Gosu::Color::Channel> (red));

	// Set green value
	double green = Gosu::random(40,255);
	powerCircleColour_.setGreen(static_cast<Gosu::Color::Channel> (green));

	// blue value
	double blue = Gosu::random(40,255);
	powerCircleColour_.setBlue(static_cast<Gosu::Color::Channel> (blue));
}

/*
	Name		Player::Player
	Syntax		Player::update()
	Brief		Updates the player's position and state
*/
void Player::update()
{
	checkKeyPresses();
	
	applyAddiction();

	updateState();

	jump();

	positionPlayer();

	updatePowerCircle();
}

/*
	Name		Player::Player
	Syntax		Player::draw()
	Brief		Draws the player
*/
void Player::draw()
{
	
	// Animate star								speed of animation		   size of animation
	Gosu::Image& playerImage_ = *playerAnim_.at( ( Gosu::milliseconds() / 50) % ( playerAnim_.size() ) );

	// Draw from top left 
	playerImage_.drawRot(x_,	// X position from top left
				  y_,	// Y position from top right 
				  Z_FOREGROUND,
			      angle_ + 180);

	powerCircle_.drawRot(CENTRE_X, 
						CENTRE_Y, 
						Z_BETWEEN_MID_AND_FORGROUND, 
						0, 
						0.5, 
						0.5, 
						powerCircleScaleFactor_,
						powerCircleScaleFactor_,
						powerCircleColour_,
						Gosu::amAdd);
}

/*
	Name		Player::Player
	Syntax		Player::positionPlayer()
	Brief		Positions the player on the world
*/
void Player::positionPlayer()
{
	// Position player along a circle
	// Set initial position without circle transformation
	x_ = 0;
	y_ = radius_ + jumpOffset_;

	// Calculate circle coords
	double angle = Gosu::degreesToRadians(angle_);
	double tempX = (x_ * cos(angle)) - (y_ * sin(angle));

	// Set circle coords
	y_ = (x_ * sin(angle)) + (y_ * cos(angle)) + CENTRE_Y;
	x_ = tempX + CENTRE_X;
}

void Player::checkKeyPresses()
{
	// If up has been pressed
	//if( GameWindow::instance()->input().down(Gosu::kbZ) && (hasJumped_ == false))
	if( GameWindow::instance()->input().down(Gosu::kbZ) )
	{
		// If z is not being pressed
		if(zPressed_ == false)
		{	
			// Set var to Z being pressed 
			zPressed_ = true;

			// If not currently jumping
			if( hasJumped_ == false)
			{
				// Set player to jumping
				hasJumped_ = true;

				// Set player to jumping upwards
				jumpingUp_ = true;
			}
		}
	}
	else
	{
		// Else Z is not being pressed
		zPressed_ = false;
	}
}

void Player::updatePowerCircle()
{
	// Adjust power circle size
	// Set parameters to make smaller
	if( powerCircleScaleFactor_ >= 1.0 )
	{
		powerCircleDecreasing_ = true;
		powerCircleIncreasing_ = false;
	}

	// Set parameters to make circle bigger 
	if ( powerCircleScaleFactor_ <= 0.4)
	{
		powerCircleDecreasing_ = false;
		powerCircleIncreasing_ = true;
	}

	// Change dimensions of circle
	if( powerCircleIncreasing_ )
	{
		// Update circle scale factor
		powerCircleScaleFactor_ += 0.01;
	}

	if( powerCircleDecreasing_ )
	{
		// Update circle scale factor
		powerCircleScaleFactor_ -= 0.01;
	} 
}

unsigned int Player::getWidth()
{
	return 50;
}

unsigned int Player::getHeight()
{
	return 50;
}

void Player::updateState()
{
	if( (angle_ >= 198) && (angle_ < 270) )
	{
		playerState_ = PLAYER_STATE_HIGH;
		powerCircleColour_ = Gosu::Color::RED;
		//powerCircleColour_.setRed()
	}
	
	if( (angle_ >= 126) && (angle_ < 198) )
	{
		playerState_ = PLAYER_STATE_MED_HIGH;
		//powerCircleColour_ = Gosu::Color::ORANGE;
	}

	if( (angle_ >= 54) && (angle_ < 126) )
	{
		playerState_ = PLAYER_STATE_NEUTRAL;
		powerCircleColour_ = Gosu::Color::GREEN;
	}

	if( (angle_ >= 0) && (angle_ < 54) )
	{
		playerState_ = PLYAER_STATE_MED_DOWN;
		powerCircleColour_ = Gosu::Color::BLUE;
	}

	if( (angle_ >= 342) && (angle_ < 0) )
	{
		playerState_ = PLYAER_STATE_MED_DOWN;
		powerCircleColour_ = Gosu::Color::BLUE;
	}

	if( (angle_ >= 270) && (angle_ < 342) )
	{
		playerState_ = PLAYER_STATE_DOWNER;
		//powerCircleColour_ = Gosu::Color::PURPLE;
	}

}

void Player::gotPickUp()
{
	high_ = true;
}

void Player::applyAddiction()
{
	if(high_ == true)
	{
		addiction_ -= 0.5;
		addictionMaximum_ += 1;
	}

	if(addiction_ < -10)
	{
		high_ = false;
	}

	if ( (high_ == false) && !(addiction_ == addictionMaximum_))
	{
		addiction_ += 0.5;
	}

	angle_ -= addiction_;
	//addiction_--;
}

void Player::jump()
{
	// If the player has jumper and they are not falling and they haven't reached their peak the move upwards
	if( hasJumped_ && ( falling_ == false) &&  (jumpOffset_ < MAX_JUMP_HEIGHT_))
	{
		jumpOffset_ += JUMP_VELOCITY_;
	}

	// Check to see if the player has reached his peak
	if( jumpOffset_ >= MAX_JUMP_HEIGHT_ )
	{
		// Set the player to falling
		falling_ = true;
	}

	// If the player has jumped and is falling
	if( hasJumped_ && (falling_ == true) )
	{
		// Move player towards world
		jumpOffset_ -= JUMP_VELOCITY_;
	}

	// If the offset is less than zero
	if( jumpOffset_ <= 0)
	{
		// Set to zero
		jumpOffset_ = 0;
		hasJumped_ = false;
		falling_ = false;
	}
}