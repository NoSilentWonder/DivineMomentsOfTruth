/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		PickUp
	Brief		Declaration of PickUp class
*/

#ifndef _PICK_UP_HPP_
#define _PICK_UP_HPP_

#include <Gosu\Graphics.hpp>
#include <Gosu\Image.hpp>

class PickUp
{
public:
	PickUp(Gosu::Graphics& graphics, std::wstring& filename);
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
	void positionPickUp();

	Gosu::Image image_;
	double x_, y_;
	double centreX_, centreY_;
	double angle_;
	double radius_;
	int timer_;
	bool gone_;
	bool reversing_;
};

#endif // _PICK_UP_HPP_