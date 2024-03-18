#pragma once //prevents the header from being included multiple times
#include <string>

//CHALLENGE #1: add a gamerTag to the class (field, getter/setter, ctor)

class Player
{
	//the INTERFACE of your class
	//describes the object: the data and what it can do

	// CONSTRUCTORS (ctor)
public:
	//IFF I do NOT write a constructor, the compiler will give me a default ctor
	//IF I create a ctor, then the compiler's ctor is NOT created
	//ctor is a special method to initialize your fields

	// MUST be named the same as the class (EX: Player )
	// CANNOT have a return type (not even void)
	// most of the time will be public but they can be private/protected
	// can overload as many as you want
	//Player();
	Player(std::string gamerTag, float health, float foodLevel, float armorLevel);


public://EVERYONE can see it

	void PlayerHUD(float healthLevel);

	//getters (accessors)
	float GetHealth() const { return health_; } //make it inline
	float FoodLevel() const { return foodLevel_; }
	float ArmorLevel() const { return armorLevel_; }
	std::string GamerTag() const { return gamerTag_; }

	// vector's getsize() method

	//setters (mutators)
	void SetHealth(float health) {
		//PROTECT the data
		if (health >= 0 && health <= 20)
			health_ = health;//do NOT use this->
	}
	void FoodLevel(float foodLevel) {
		//PROTECT the data
		if (foodLevel >= 0 && foodLevel <= 20)
			foodLevel_ = foodLevel;
	}
	void ArmorLevel(float armorLevel) {
		//PROTECT the data
		if (armorLevel >= 0 && armorLevel <= 20)
			armorLevel_ = armorLevel;
	}
	void GamerTag(std::string gamerTag) {
		if (gamerTag.size() > 0 && gamerTag.size() < 10)
			gamerTag_ = gamerTag;
	}

	void PlayerHUD();



private: //ONLY this class can see it
	//naming conventions:
	//m_fHealth   m_health  _health  health_
	float health_;
	float foodLevel_, armorLevel_;
	std::string gamerTag_;

protected://THIS class and all my descendent classes (children, grand-children, etc) can see it

};

