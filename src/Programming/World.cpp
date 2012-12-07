// World.cpp

#include <Gosu\Directories.hpp>

#include "World.hpp"
#include "Constants.hpp"
#include "ZOrder.hpp"

World::World(Gosu::Graphics& graphics):
image_(graphics, Gosu::sharedResourcePrefix() + L"assets/World.png"),
x_(CENTRE_X),
y_(CENTRE_Y),
angle_(0)
{
}


void World::update()
{
	angle_--;
}

void World::draw()
{
	image_.drawRot(	x_,
					y_,					 
					Z_MIDGROUND,		
					angle_);					
}