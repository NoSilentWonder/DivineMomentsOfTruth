/*
	Copyright	Divine Moments of Truth 2011
	Created 	Elinor Townsend
	
	Name		PlayState
	Brief		Definition of PlayState class methods

	Notes		All the pick up stuff should be rewritten to for loops
				to reduce repetition
*/

#include <Gosu\Directories.hpp>
#include <sstream>

#include "PlayState.hpp"
#include "GameWindow.hpp"
#include "Enemy.hpp"
#include "Scenery.hpp"
#include "PickUp.hpp"
#include "FileNames.hpp"
#include "Constants.hpp"
#include "Physics.hpp"
#include "ZOrder.hpp"

#define REMOVE_ENTITY_TIME 450

/*
	Name		PlayState::PlayState
	Syntax		PlayState()
	Brief		PlayState constructor initialises member variables
*/
PlayState::PlayState()
	: player_(GameWindow::instance()->graphics()), world_(GameWindow::instance()->graphics()),
	  spawnTimer_(50), currentEvent_(PLAY), pPressed_(false), pickUp1_(0), pickUp2_(0),
	  pickUp3_(0), pickUp4_(0), pickUp5_(0), pickUp6_(0), pickUp7_(0), pickUp8_(0), xPressed_(false), 
	  skyBackground_(GameWindow::instance()->graphics(), Gosu::sharedResourcePrefix() + L"assets/Sky.png"),
	  pauseBackground_(GameWindow::instance()->graphics(), Gosu::sharedResourcePrefix() + L"assets/Pause.png"),
	  deathBackground_(GameWindow::instance()->graphics(), Gosu::sharedResourcePrefix() + L"assets/Score.png"),
	  filter_(GameWindow::instance()->graphics(), Gosu::sharedResourcePrefix() + L"assets/Filter.png"),
	  pauseSound_(Gosu::sharedResourcePrefix() + L"Sound Effects/Pause/Pause Noise.ogg"), dead_(false),
	  deathTimer_(75), pickupTimer_(25)
{
	
}

/*
	Name		PlayState::~PlayState
	Syntax		~PlayState()
	Brief		PlayState destructor
*/
PlayState::~PlayState()
{

}

/*
	Name		PlayState::getNextState
	Syntax		PlayState::getNextState(Condition condition)
	Param		Condition condition - Condition parameter used to determine the next state
	Return		State* - A pointer to the next state type object
	Brief		Creates a new object of the next state type
*/
State* PlayState::getNextState(Condition condition)
{
	State* state = NULL;
    switch (condition) 
	{
	case CONDITION_GO_TO_MENU:
		break;
	default : 
		state = NULL;
		break;
	}
	return state;
}

/*
	Name		PlayState::initialise
	Syntax		PlayState::initialise()
	Brief		Initialises the state
*/
void PlayState::initialise()
{
}

/*
	@Name		PlayState::deinitialise
	@Syntax		PlayState::deinitialise()
	@Brief		Deinitialises the state
*/
void PlayState::deinitialise()
{
	if (pickUp1_)
	{
		delete pickUp1_;
		pickUp1_ = 0;
	}
	if (pickUp2_)
	{
		delete pickUp2_;
		pickUp2_ = 0;
	}
	if (pickUp3_)
	{
		delete pickUp3_;
		pickUp3_ = 0;
	}
	if (pickUp4_)
	{
		delete pickUp4_;
		pickUp4_ = 0;
	}
	if (pickUp5_)
	{
		delete pickUp5_;
		pickUp5_ = 0;
	}
	if (pickUp6_)
	{
		delete pickUp6_;
		pickUp6_ = 0;
	}
	if (pickUp7_)
	{
		delete pickUp6_;
		pickUp7_ = 0;
	}
	if (pickUp8_)
	{
		delete pickUp6_;
		pickUp8_ = 0;
	}

	enemies_.clear();
	scenery_.clear();

	spawnTimer_ = 60;
	pickupTimer_ = 45;
	dead_ = false;
	deathTimer_ = 75;

}

/*
	Name		PlayState::update
	Syntax		PlayState::update()
	Brief		Updates the state
	Details		Time-critical logic updates are performed by this method
*/
void PlayState::update()
{
	// Iterators
	std::list<Enemy>::iterator itEnemy;
	std::list<Scenery>::iterator itScenery;

	switch (currentEvent_)
	{
	case PLAY:
		// Generate any new entities
		spawnEntities();

		// Update all entities in the scene
		updateEntities();

		// Remove entities after set time 
		removeEntities();

		// Check for game pausing
		if (GameWindow::instance()->input().down(Gosu::kbP))
		{
			if (!pPressed_)
			{
				pPressed_ = true;
				currentEvent_ = PAUSE;
				pauseSound_.play();
				player_.paused();
			}
		}
		else
		{
			pPressed_ = false;
		}

		// Collision detection
		for (itEnemy = enemies_.begin(); itEnemy != enemies_.end(); ++itEnemy)
		{
			if (Physics::collision(player_, *itEnemy))
			{
				player_.reduceScore();
				player_.playRandomHurtNoise();
			}
		}

		if (player_.getGameOver())
		{
			if (!dead_)
			{	
				// Call death anim
				dead_ = true;
			}
		}

		// Check for player grabbing for pick ups
		if (GameWindow::instance()->input().down(Gosu::kbX))
		{
			if (!xPressed_)
			{
				xPressed_ = true;

				// Check for successful grab (collision with pick up)
				if (pickUp1_)
				{
					if (Physics::collision(player_, *pickUp1_))
					{
						// Call player response to pick up
						player_.gotPickUp();
						delete pickUp1_;
						pickUp1_ = 0;
					}
				}
				if (pickUp2_)
				{
					if (Physics::collision(player_, *pickUp2_))
					{
						// Call player response to pick up
						player_.gotPickUp();
						delete pickUp2_;
						pickUp2_ = 0;
					}
				}
				if (pickUp3_)
				{
					if (Physics::collision(player_, *pickUp3_))
					{
						// Call player response to pick up
						player_.gotPickUp();
						delete pickUp3_;
						pickUp3_ = 0;
					}
				}
				if (pickUp4_)
				{
					if (Physics::collision(player_, *pickUp4_))
					{
						// Call player response to pick up
						player_.gotPickUp();
						delete pickUp4_;
						pickUp4_ = 0;
					}
				}
				if (pickUp5_)
				{
					if (Physics::collision(player_, *pickUp5_))
					{
						// Call player response to pick up
						player_.gotPickUp();
						delete pickUp5_;
						pickUp5_ = 0;
					}
				}
				if (pickUp6_)
				{
					if (Physics::collision(player_, *pickUp6_))
					{
						// Call player response to pick up
						player_.gotPickUp();
						delete pickUp6_;
						pickUp6_ = 0;
					}
				}
				if (pickUp7_)
				{
					if (Physics::collision(player_, *pickUp7_))
					{
						// Call player response to pick up
						player_.gotPickUp();
						delete pickUp7_;
						pickUp7_ = 0;
					}
				}
				if (pickUp8_)
				{
					if (Physics::collision(player_, *pickUp8_))
					{
						// Call player response to pick up
						player_.gotPickUp();
						delete pickUp8_;
						pickUp8_ = 0;
					}
				}
			}
		}
		else
		{
			xPressed_ = false;
		}

		// If dead
		if (dead_)
		{
			if (deathTimer_ > 0)
				deathTimer_--;
			else
			{
				currentEvent_ = DEATH;
			}

		}	
		break;

	case PAUSE:
		// Check for game pausing
		if (GameWindow::instance()->input().down(Gosu::kbP))
		{
			if (!pPressed_)
			{
				pPressed_ = true;
				currentEvent_ = PLAY;
				player_.unpaused();
			}
		}
		else
		{
			pPressed_ = false;
		}
		break;

	case DEATH:
		// Check for game pausing
		if (GameWindow::instance()->input().down(Gosu::kbSpace))
		{
			deinitialise();
			player_.reset();
			currentEvent_ = PLAY;
		}
		break;

	default:
		break;
	}

	ui_.update(player_.getScore());
}

/*
	Name		PlayState::draw
	Syntax		PlayState::draw()
	Brief		Renders the state
*/
void PlayState::draw()
{
	// Iterators
	std::list<Enemy>::iterator itEnemy;
	std::list<Scenery>::iterator itScenery;

	switch (currentEvent_)
	{
	case PLAY:
		// Draw all the entities
		player_.draw();
		world_.draw();
		ui_.draw();
		
		for (itEnemy = enemies_.begin(); itEnemy != enemies_.end(); ++itEnemy)
		{
			itEnemy->draw();
		}
		
		for (itScenery = scenery_.begin(); itScenery != scenery_.end(); ++itScenery)
		{
			itScenery->draw();
		}

		if (pickUp1_)
			pickUp1_->draw();
		if (pickUp2_)
			pickUp2_->draw();
		if (pickUp3_)
			pickUp3_->draw();
		if (pickUp4_)
			pickUp4_->draw();
		if (pickUp5_)
			pickUp5_->draw();
		if (pickUp6_)
			pickUp6_->draw();
		if (pickUp7_)
			pickUp7_->draw();
		if (pickUp8_)
			pickUp8_->draw();

		skyBackground_.draw(0, 0, Z_BACKGROUND);
//		filter_.drawRot(CENTRE_X, CENTRE_Y, Z_FILTER, 0, 0.5, 0.5, 1, 1, Gosu::Color::WHITE, Gosu::amAdd);
		break;

	case PAUSE:
		pauseBackground_.draw(0, 0, Z_BACKGROUND);
		break;

	case DEATH:
		deathBackground_.draw(0, 0, Z_BACKGROUND);
		ui_.drawBigScore();
		break;

	default:
		break;
	}
}

/*
	Name		PlayState::spawnEntities
	Syntax		PlayState::spawnEntities()
	Brief		Spawns new entities in the scene
*/
void PlayState::spawnEntities()
{
	spawnTimer_ += rand() % 3;
	pickupTimer_ += rand() % 3;
	if (spawnTimer_ > 75)
	{
		int type = rand() % 100;
		// Create enemy
		if (type > 65)
		{
			enemies_.push_back(Enemy(GameWindow::instance()->graphics(), 
								getRandomObstacleFile()));
		}
		// Create scenery object
		else
		{
			scenery_.push_back(Scenery(GameWindow::instance()->graphics(), getRandomSceneryFile()));
		}
		spawnTimer_ = 0;
	}
	if (pickupTimer_ > 85)
	{
		// Create pick up
		if (!pickUp1_)
		{
			pickUp1_ = new PickUp(GameWindow::instance()->graphics(), getRandomPickUpFile());
		}
		else if (!pickUp2_)
		{
			pickUp2_ = new PickUp(GameWindow::instance()->graphics(), getRandomPickUpFile());
		}
		else if (!pickUp3_)
		{
			pickUp3_ = new PickUp(GameWindow::instance()->graphics(), getRandomPickUpFile());
		}
		else if (!pickUp4_)
		{
			pickUp4_ = new PickUp(GameWindow::instance()->graphics(), getRandomPickUpFile());
		}
		else if (!pickUp5_)
		{
			pickUp5_ = new PickUp(GameWindow::instance()->graphics(), getRandomPickUpFile());
		}
		else if (!pickUp6_)
		{
			pickUp6_ = new PickUp(GameWindow::instance()->graphics(), getRandomPickUpFile());
		}
		else if (!pickUp7_)
		{
			pickUp7_ = new PickUp(GameWindow::instance()->graphics(), getRandomPickUpFile());
		}
		else if (!pickUp8_)
		{
			pickUp8_ = new PickUp(GameWindow::instance()->graphics(), getRandomPickUpFile());
		}
		pickupTimer_ = 0;
	}
}

/*
	Name		PlayState::updateEntities
	Syntax		PlayState::updateEntities()
	Brief		Updates all the entities in the scene
*/
void PlayState::updateEntities()
{
	// Iterators
	std::list<Enemy>::iterator itEnemy;
	std::list<Scenery>::iterator itScenery;

	player_.update();
	world_.update();
		
	for (itEnemy = enemies_.begin(); itEnemy != enemies_.end(); ++itEnemy)
	{
		itEnemy->update();
	}
		
	for (itScenery = scenery_.begin(); itScenery != scenery_.end(); ++itScenery)
	{
		itScenery->update();
	}

	if (pickUp1_)
		pickUp1_->update();
	if (pickUp2_)
		pickUp2_->update();
	if (pickUp3_)
		pickUp3_->update();
	if (pickUp4_)
		pickUp4_->update();
	if (pickUp5_)
		pickUp5_->update();
	if (pickUp6_)
		pickUp6_->update();
	if (pickUp7_)
		pickUp7_->update();
	if (pickUp8_)
		pickUp8_->update();
}

	
/*
	Name		PlayState::removeEntities
	Syntax		PlayState::removeEntities()
	Brief		Remove old entities from the scene
*/
void PlayState::removeEntities()
{
	if (enemies_.size() > 0)
	{	
		if (enemies_.front().isGone())
		{
			enemies_.pop_front();
		}
		else if (enemies_.front().getTimer() > REMOVE_ENTITY_TIME)
		{
			enemies_.front().reverse();
		}
	}
	if (scenery_.size() > 0)
	{	
		if (scenery_.front().isGone())
		{
			scenery_.pop_front();
		}
		else if (scenery_.front().getTimer() > REMOVE_ENTITY_TIME)
		{
			scenery_.front().reverse();
		}
	}

	if (pickUp1_)
	{
		if (pickUp1_->isGone())
		{
			delete pickUp1_;
			pickUp1_ = 0;
		}
		else if (pickUp1_->getTimer() > REMOVE_ENTITY_TIME)
		{
			pickUp1_->reverse();
		}
	}
	if (pickUp2_)
	{
		if (pickUp2_->isGone())
		{
			delete pickUp2_;
			pickUp2_ = 0;
		}
		else if (pickUp2_->getTimer() > REMOVE_ENTITY_TIME)
		{
			pickUp2_->reverse();
		}
	}
	if (pickUp3_)
	{
		if (pickUp3_->isGone())
		{
			delete pickUp3_;
			pickUp3_ = 0;
		}
		else if (pickUp3_->getTimer() > REMOVE_ENTITY_TIME)
		{
			pickUp3_->reverse();
		}
	}
	if (pickUp4_)
	{
		if (pickUp4_->isGone())
		{
			delete pickUp4_;
			pickUp4_ = 0;
		}
		else if (pickUp4_->getTimer() > REMOVE_ENTITY_TIME)
		{
			pickUp4_->reverse();
		}
	}
	if (pickUp5_)
	{
		if (pickUp5_->getTimer() > REMOVE_ENTITY_TIME)
		{
			delete pickUp5_;
			pickUp5_ = 0;
		}
	}
	if (pickUp6_)
	{
		if (pickUp6_->isGone())
		{
			delete pickUp6_;
			pickUp6_ = 0;
		}
		else if (pickUp6_->getTimer() > REMOVE_ENTITY_TIME)
		{
			pickUp6_->reverse();
		}
	}
	if (pickUp7_)
	{
		if (pickUp7_->isGone())
		{
			delete pickUp7_;
			pickUp7_ = 0;
		}
		else if (pickUp7_->getTimer() > REMOVE_ENTITY_TIME)
		{
			pickUp7_->reverse();
		}
	}
	if (pickUp8_)
	{
		if (pickUp8_->isGone())
		{
			delete pickUp8_;
			pickUp8_ = 0;
		}
		else if (pickUp8_->getTimer() > REMOVE_ENTITY_TIME)
		{
			pickUp8_->reverse();
		}
	}
}