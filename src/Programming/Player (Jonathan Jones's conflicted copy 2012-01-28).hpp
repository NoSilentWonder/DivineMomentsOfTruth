/*
	Copyright	Divine Moment of Truth 2011
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

class Player
{
public:
	Player(Gosu::Graphics& graphics);
	void update();
	void draw();
	
	unsigned int getWidth();
	unsigned int getHeight();
private:
	void positionPlayer();
	void updatePowerCircle();
	void checkKeyPresses();

private:
	double x_, y_;
	double angle_;
	double radius_;
	double jumpOffset_;

	Animation playerAnim_;
	Gosu::Image playerImage_;

	bool zPressed_;
	bool hasJumped_;
	bool jumpingUp_;
	bool falling_;
	const double MAX_JUMP_HEIGHT_;
	const double JUMP_VELOCITY_;
	double addiction_;

	// Power circle variables 
	Gosu::Image powerCircle;
	double powerCircleScaleFactor;
	bool powerCircleIncreasing, powerCircleDecreasing;
	Gosu::Color powerCircleColour;
	//Sample Jump;
};

#endif 