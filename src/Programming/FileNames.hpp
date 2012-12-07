/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
				Jonathan Jones
	
	Name		Enemy
	Brief		Declaration of Enemy class
*/

#ifndef _FILENAMES_HPP_
#define _FILENAMES_HPP_

#include <Gosu\Directories.hpp>
#include <sstream>

std::wstring& getRandomPickUpFile();
std::wstring& getRandomObstacleFile();
std::wstring& getRandomSceneryFile();

#endif