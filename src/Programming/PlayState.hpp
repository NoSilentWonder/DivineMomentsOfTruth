/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		PlayState
	Brief		Declaration of PlayState class inherited from State
*/

#ifndef _PLAYSTATE_H
#define _PLAYSTATE_H

#include <Gosu/Audio.hpp>
#include <list>
#include "State.hpp"
#include "Player.hpp"
#include "World.hpp"
#include "UI.hpp"

class Enemy;
class Scenery;
class PickUp;

/*
	Name		PlayState class
	Brief		The PlayState class contains the logic methods for 
				the play state of the Divine Moments of Truth game
*/
class PlayState : public State
{
public:
	PlayState();
	~PlayState();
    virtual State* getNextState(Condition condition);
	virtual void initialise();
	virtual void deinitialise();
	virtual void update();
	virtual void draw();

private:
	void spawnEntities();
	void updateEntities();
	void removeEntities();

	enum GameEvent { PLAY, PAUSE, DEATH } currentEvent_;
	Player player_;
	World world_;
	UI ui_;

	Gosu::Image skyBackground_;
	Gosu::Image pauseBackground_;
	Gosu::Image deathBackground_;
	Gosu::Image filter_;

	std::list<Enemy> enemies_;
	std::list<Scenery> scenery_;
	PickUp* pickUp1_;
	PickUp* pickUp2_;
	PickUp* pickUp3_;
	PickUp* pickUp4_;
	PickUp* pickUp5_;
	PickUp* pickUp6_;
	PickUp* pickUp7_;
	PickUp* pickUp8_;

	Gosu::Sample pauseSound_;

	int spawnTimer_;
	int pickupTimer_;
	int deathTimer_;

	bool pPressed_;
	bool xPressed_;
	bool dead_;
};

#endif // _PLAYSTATE_H