/*
	Copyright	Divine Moments of Truth 2011
	Created 	Jonathan Jones
				Elinor Townsend
	
	Name		Player
	Brief		Declaration of Player class
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <Gosu\Graphics.hpp>
#include <Gosu\Image.hpp>
#include <Gosu\Audio.hpp>
#include <Gosu\Color.hpp>

#include "Animation.h"

enum PlayerState
{
	PLAYER_STATE_DOWNER,
	PLYAER_STATE_MED_DOWN,
	PLAYER_STATE_NEUTRAL,
	PLAYER_STATE_MED_HIGH,
	PLAYER_STATE_HIGH
};

class Player
{
public:
	Player(Gosu::Graphics& graphics);
	void update();
	void draw();
	
	unsigned int getWidth();
	unsigned int getHeight();
	double getX() { return x_; };
	double getY() { return y_; };

	void gotPickUp();
	void jump();
private:
	void positionPlayer();
	void updatePowerCircle();
	void checkKeyPresses();
	void updateState();
	void applyAddiction();

private:
	double x_, y_;
	double angle_;
	double radius_;
	double jumpOffset_;

	Animation playerAnim_;
	//Gosu::Image playerImage_;

	bool zPressed_;
	bool hasJumped_;
	bool jumpingUp_;
	bool falling_;
	const double MAX_JUMP_HEIGHT_;
	const double JUMP_VELOCITY_;
	double addiction_;

	// Power circle variables 
	Gosu::Image powerCircle_;
	double powerCircleScaleFactor_;
	bool powerCircleIncreasing_, powerCircleDecreasing_;
	Gosu::Color powerCircleColour_;
	//Sample Jump;

	unsigned int playerState_;

	bool high_;

	double addictionMaximum_;
};

#endif 