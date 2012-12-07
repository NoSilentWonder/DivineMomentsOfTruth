/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
				Jonathan Jones
	
	Name		Enemy
	Brief		Declaration of Enemy class
*/

#include "FileNames.hpp"

std::wstring& pickUpFile1 = Gosu::sharedResourcePrefix() + L"assets/items/item1.png";
std::wstring& pickUpFile2 = Gosu::sharedResourcePrefix() + L"assets/items/item2.png";
std::wstring& pickUpFile3 = Gosu::sharedResourcePrefix() + L"assets/items/item3.png";

std::wstring& obstacleFile1 = Gosu::sharedResourcePrefix() + L"assets/obstacles/ob1.png";
std::wstring& obstacleFile2 = Gosu::sharedResourcePrefix() + L"assets/obstacles/ob2.png";
std::wstring& obstacleFile3 = Gosu::sharedResourcePrefix() + L"assets/obstacles/ob3.png";
std::wstring& obstacleFile4 = Gosu::sharedResourcePrefix() + L"assets/obstacles/ob4.png";
std::wstring& obstacleFile5 = Gosu::sharedResourcePrefix() + L"assets/obstacles/ob5.png";
std::wstring& obstacleFile6 = Gosu::sharedResourcePrefix() + L"assets/obstacles/ob6.png";

std::wstring& sceneryFile1 = Gosu::sharedResourcePrefix() + L"assets/scenery/sc1.png";
std::wstring& sceneryFile2 = Gosu::sharedResourcePrefix() + L"assets/scenery/sc2.png";
std::wstring& sceneryFile3 = Gosu::sharedResourcePrefix() + L"assets/scenery/sc3.png";
std::wstring& sceneryFile4 = Gosu::sharedResourcePrefix() + L"assets/scenery/sc4.png";

/*
	Name		getRandomPickUpFile
	Syntax		getRandomPickUpFile()
	Brief		Returns a string filename for one of the pick up images
*/
std::wstring& getRandomPickUpFile()
{
	int type = rand() % 3;
	if (type == 0)
		return pickUpFile1;
	else if (type == 1)
		return pickUpFile2;
	else
		return pickUpFile3;
}

/*
	Name		getRandomObstacleFile
	Syntax		getRandomObstacleFile()
	Brief		Returns a string filename for one of the obstacle images
*/
std::wstring& getRandomObstacleFile()
{
	int type = rand() % 6;
	if (type == 0)
		return obstacleFile1;
	else if (type == 1)
		return obstacleFile2;
	else if (type == 2)
		return obstacleFile3;
	else if (type == 3)
		return obstacleFile4;
	else if (type == 4)
		return obstacleFile5;
	else 
		return obstacleFile6;
}

/*
	Name		getRandomSceneryFile
	Syntax		getRandomSceneryFile()
	Brief		Returns a string filename for one of the scenery images
*/
std::wstring& getRandomSceneryFile()
{
	int type = rand() % 3;
	if (type == 0)
		return sceneryFile1;
	else if (type == 1)
		return sceneryFile2;
	else if (type == 2)
		return sceneryFile3;
	else
		return sceneryFile4;
}