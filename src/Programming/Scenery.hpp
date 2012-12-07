/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		Scenery
	Brief		Declaration of Scenery class
*/

#ifndef _SCENERY_HPP_
#define _SCENERY_HPP_

#include <Gosu\Graphics.hpp>
#include <Gosu\Image.hpp>

class Scenery
{
public:
	Scenery(Gosu::Graphics& graphics, std::wstring& filename);
	void update();
	void draw();
	double getRadius() { return radius_; };
	int getTimer() { return timer_; };
	void reverse() { reversing_ = true; };
	bool isGone() { return gone_; };

private:
	void positionScenery();
	Gosu::Image image_;
	double x_, y_;
	double centreX_, centreY_;
	double angle_;
	double radius_;
	int timer_;
	bool gone_;
	bool reversing_;
};

#endif // _SCENERY_HPP_