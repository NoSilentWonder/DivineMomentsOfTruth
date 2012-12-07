/*
	Copyright	Divine Moment of Truth 2011
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
JUMP_VELOCITY_(5.0),
addiction_(0.05),
powerCircle_(graphics, Gosu::sharedResourcePrefix() + L"assets/Middle.png"),
powerCircleScaleFactor_(1),
powerCircleIncreasing_(false), 
powerCircleDecreasing_(true),
playerState_(PLAYER_STATE_MED_HIGH),
addictionMaximum_(0.05),
jump1_(Gosu::sharedResourcePrefix() + L"Sound Effects/Jump/JUMP 1.wav"),
jump2_(Gosu::sharedResourcePrefix() + L"Sound Effects/Jump/JUMP 2.wav"),
jump3_(Gosu::sharedResourcePrefix() + L"Sound Effects/Jump/JUMP 3.wav"),
footSteps_(Gosu::sharedResourcePrefix() + L"Sound Effects/Foot Steps/FootSteps2.ogg"),
footStepsPlaying_(false),
gameOver_(false),
multiplyer_(1.0),
score_(0.0),
pickupBool_(false),
burstAnimatationTimer(0),
//grungeMusic_(Gosu::sharedResourcePrefix() + L"Music/G Music2.ogg"),
//neutralMusic_(Gosu::sharedResourcePrefix() + L"Music/N Music.ogg"),
mentalMusic_(Gosu::sharedResourcePrefix() + L"Music/M MUSIC2.ogg"),
hurt1_(Gosu::sharedResourcePrefix() + L"Sound Effects/Pain/PAIN 1.ogg"),
hurt2_(Gosu::sharedResourcePrefix() + L"Sound Effects/Pain/PAIN 2.ogg"),
hurt3_(Gosu::sharedResourcePrefix() + L"Sound Effects/Pain/PAIN 3.ogg"),
playingPainClip(false),
painTimer(0)
{
	std::wstring filename = Gosu::sharedResourcePrefix() + L"assets/Charlie sheet2.png";
	Gosu::imagesFromTiledBitmap(graphics, filename, 50, 50, false, playerAnim_);

	std::wstring filename2 = Gosu::sharedResourcePrefix() + L"assets/Burst.png";
	Gosu::imagesFromTiledBitmap(graphics, filename2, 75, 75, false, burst_);
 
	std::wstring filename3 = Gosu::sharedResourcePrefix() + L"assets/Death.png";
	Gosu::imagesFromTiledBitmap(graphics, filename3, 100, 100, false, deathAnimation_);

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

	//mentalMusic_.play(true);
	//neutralMusic_.play(true);
	//grungeMusic_.play(true);

	//mentalMusic_.changeVolume(0.0);
	//neutralMusic_.changeVolume(0.0);
	//grungeMusic_.changeVolume(0.0);
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

	if( angle_ > 265)
	{
		angle_ = 265;
	}
	if(angle_ <= -90)
	{
		angle_ = -90;
		gameOver_ = true;
		mentalMusic_.stop();
		//neutralMusic_.stop();
		//grungeMusic_.stop();
		footSteps_.stop();
	}

	positionPlayer();

	updatePowerCircle();

	setPowerCircleColour();

	updateMultipler();

	if( footStepsPlaying_ == false)
	{
		footSteps_.play(true);
		footStepsPlaying_ = true;
	}

	if( pickupBool_ == true)
	{
		burstAnimatationTimer++;
	}

	if(burstAnimatationTimer > 100)
	{
		pickupBool_ = false;
		burstAnimatationTimer = 0;
	}

	setScore();

	if(gameOver_ == false)
	{
		//if(angle_ >= 150 && angle_ < 270)
		//{
			mentalMusic_.play(true);
			//neutralMusic_.stop();
			//grungeMusic_.stop();
		//}
		//if(angle_ >= 30 && angle_ < 150)
		//{
			//mentalMusic_.stop();
			//neutralMusic_.play(true);
			//grungeMusic_.stop();
		//}
		//if(angle_ >= -90 && angle_ < 30)
		//{
			//mentalMusic_.stop();
			//neutralMusic_.stop();
			//grungeMusic_.play(true);
		//}
	}

	if(playingPainClip == true)
	{
		painTimer++;
	}

	if(painTimer > 150)
	{
		playingPainClip = false;
		painTimer = 0;
	}
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
	Gosu::Image& burstImage_ = *burst_.at( ( Gosu::milliseconds() / 50) % ( burst_.size() ) );

	if(gameOver_ == false)
	{
		// Draw from top left 
		playerImage_.drawRot(x_,	// X position from top left
							y_,	// Y position from top right 
							Z_FOREGROUND,
							angle_ + 180);
	}

	powerCircle_.drawRot(CENTRE_X, 
						CENTRE_Y, 
						Z_BETWEEN_MID_AND_FORGROUND, 
						0, 
						0.5, 
						0.5, 
						powerCircleScaleFactor_,
						powerCircleScaleFactor_,
						powerCircleColour_,
						Gosu::amDefault);

	if( pickupBool_ == true)
	{
		burstImage_.drawRot(x_,	// X position from top left
							y_,	// Y position from top right 
							Z_FOREGROUND,
							angle_ + 180);
	}

	if( gameOver_ == true) 
	{
		Gosu::Image& deathImage_ = *deathAnimation_.at( ( Gosu::milliseconds() / 100) % ( deathAnimation_.size() ) );

		deathImage_.drawRot(x_,	// X position from top left
							y_,	// Y position from top right 
							Z_FOREGROUND,
							angle_ + 180);
	}
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

				playRandomJumpSound();
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
	}
	
	if( (angle_ >= 126) && (angle_ < 198) )
	{
		playerState_ = PLAYER_STATE_MED_HIGH;
	}

	if( (angle_ >= 54) && (angle_ < 126) )
	{
		playerState_ = PLAYER_STATE_NEUTRAL;
	}

	if( (angle_ >= -18) && (angle_ < 54) )
	{
		playerState_ = PLYAER_STATE_MED_DOWN;
	}

	if( (angle_ >= -90) && (angle_ < -18) )
	{
		playerState_ = PLAYER_STATE_DOWNER;
	}

}

void Player::gotPickUp()
{
	high_ = true;
	pickupBool_ = true;

	if( addictionMaximum_ < 0.5)
	{
		addictionMaximum_ += 0.05;
	}
}

void Player::applyAddiction()
{
	if(high_ == true)
	{
		addiction_ -= 0.05;	
	}

	if(addiction_ < -2)
	{
		high_ = false;
	}

	if ( (high_ == false) && (addiction_ < addictionMaximum_))
	{
		addiction_ += 0.1;
	}

	if(addiction_ > addictionMaximum_)
	{
		addiction_ = addictionMaximum_;
	}

	if( hasJumped_ == false)
	{
		angle_ -= addiction_;
	}

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

void Player::playRandomJumpSound()
{
	int temp = rand() % 3;

	switch(temp)
	{
	case 0:
		jump1_.play(0.5);
		break;
	case 1:
		jump2_.play(0.5);
		break;
	case 2:
		jump3_.play(0.5);
		break;
	default:
		break;
	};
}

double Player::getScore()
{
	return score_;
}

bool Player::getGameOver()
{
	return gameOver_;
}

void Player::setPowerCircleColour()
{
	powerCircleColour_.setRed(static_cast<Gosu::Color::Channel> ( ((angle_ + 90.0)/360.0)*255.0 ) );
	powerCircleColour_.setGreen(static_cast<Gosu::Color::Channel> ( ((angle_ + 90.0)/360.0)*255.0 ) );
	powerCircleColour_.setBlue(static_cast<Gosu::Color::Channel> ( ((angle_ + 90.0)/360.0)*255.0 ) );
}

void Player::updateMultipler()
{
	switch(playerState_)
	{
	case PLAYER_STATE_DOWNER:
		multiplyer_ = 1;
		break;
	case PLYAER_STATE_MED_DOWN:
		multiplyer_ = 2;
		break;
	case PLAYER_STATE_NEUTRAL:
		multiplyer_ = 3;
		break;
	case PLAYER_STATE_MED_HIGH:
		multiplyer_ = 4;
		break;
	case PLAYER_STATE_HIGH:
		multiplyer_ = 5;
		break;
	};
}

void Player::setScore()
{
	score_ = (score_ + multiplyer_) + 1;
}

void Player::reset()
{
	x_ = 0;
	y_ = 0;
	angle_ = 180;
	jumpOffset_ = 0;
	zPressed_ = false;
	hasJumped_ = false;
	jumpingUp_ = false;
	falling_ = false;
	addiction_ = 0.05;
	powerCircleScaleFactor_ = 1;
	powerCircleIncreasing_ = false; 
	powerCircleDecreasing_ = true;
	playerState_ = PLAYER_STATE_MED_HIGH;
	addictionMaximum_ = 0.05;
	footStepsPlaying_ = false;
	gameOver_ = false;
	multiplyer_ = 1.0;
	score_ = 0.0;
}

void Player::reduceScore()
{
	score_ -= 20;
	angle_-= 0.5;
}

void Player::paused()
{
	footStepsPlaying_ = false;
	if(gameOver_ == false)
	{
		//if(angle_ >= 150 && angle_ < 270)
		//{
			mentalMusic_.pause();
		//}
		//if(angle_ >= 30 && angle_ < 150)
		//{
			//neutralMusic_.pause();
		//}
		//if(angle_ >= -90 && angle_ < 30)
		//{
			//grungeMusic_.pause();
		//}
	}
}

void Player::unpaused()
{
	footStepsPlaying_ = true;
	if(gameOver_ == false)
	{
		//if(angle_ >= 150 && angle_ < 270)
		//{
			mentalMusic_.play(true);
		//}
		//if(angle_ >= 30 && angle_ < 150)
		//{
			//neutralMusic_.play(true);
		//}
		//if(angle_ >= -90 && angle_ < 30)
		//{
			//grungeMusic_.play(true);
		//}
	}
}

void Player::playRandomHurtNoise()
{
	if(playingPainClip == false)
	{
		playingPainClip = true;
		int temp = rand() % 3;

		switch(temp)
		{
		case 0:
			hurt1_.play(0.5);
			break;
		case 1:
			hurt2_.play(0.5);
			break;
		case 2:
			hurt3_.play(0.5);
			break;
		default:
			break;
		};
	}
}