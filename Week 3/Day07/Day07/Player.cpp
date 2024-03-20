#include "Player.h"
#include <iostream>

//the actual CODE for your class

//Player::Player()  //default ctor. NO parameters
//{
//	//initialize the fields
//	health_ = foodLevel_ = 20;
//	armorLevel_ = 0;
//}

int Player::numberOfPlayers_ = 0;

//preferred to use the member initialization list
Player::Player(std::string gamerTag, float health, float foodLevel, float armorLevel) :
	gamerTag_(gamerTag),
	health_(health),
	foodLevel_(foodLevel),
	armorLevel_(armorLevel)
{
	//ctor code
	numberOfPlayers_++;
}

void Player::PlayerHUD(float healthLevel)
{
	float health = health_;
	health = 1000;
	health_ = 1000;
}

//non-static methods have a hidden parameter called "this"
//non-static methods can access non-static AND static members
//Player this
void Player::PlayerHUD()//Player* this)
{
	//can access all the non-static and static data
	std::cout << gamerTag_ << ": Health (" << health_ << ") Armor (" << armorLevel_ << ") Food (" << foodLevel_ << ")\n";
}

//static methods DO NOT have a hidden parameter called "this"
//static methods can ONLY access static members
void Player::GameHUD()
{
	//std::cout << this->gamerTag_ << ": Health (" << health_ << ") Armor (" << armorLevel_ << ") Food (" << foodLevel_ << ")\n";

	std::cout << "Number of players: " << numberOfPlayers_ << "\n";
}
