/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
				Jonathan Jones
	
	Name		Enemy
	Brief		Declaration of Enemy class
*/

#ifndef ENEMY_HPP_
#define ENEMY_HPP_

#include <Gosu\Graphics.hpp>
#include <Gosu\Image.hpp>

class Enemy
{
public:
	Enemy(Gosu::Graphics& graphics, std::wstring& filename);
	void update();
	void draw();
	double getRadius() { return radius_; };
	int getTimer() { return timer_; };
	Gosu::Image* getImage() { return &image_; };
	double getX() { return x_; };
	double getY() { return y_; };
	void reverse() { reversing_ = true; };
	bool isGone() { return gone_; };

private:
	void positionEnemy();

	Gosu::Image image_;
	double x_, y_;
	double centreX_, centreY_;
	double angle_;
	double radius_;
	int timer_;
	bool gone_;
	bool reversing_;
};

#endif 