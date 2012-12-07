// World.hpp

#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <Gosu\Graphics.hpp>
#include <Gosu\Image.hpp>

class World
{
public:
	World(Gosu::Graphics& graphics);
	void update();
	void draw();
private:
	Gosu::Image image_;
	double x_, y_;
	double angle_;
};

#endif