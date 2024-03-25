#pragma once
#include <string>
class Player
{
public:

	Player(const std::string& tag, float armor, float food, float health)
		: gamerTag_(tag), armor_(armor), food_(food), health_(health)
	{

	}

	std::string GamerTag() const { return gamerTag_; }
	float Armor() const { return armor_; }
	float Food() const { return food_; }
	float Health() const { return health_; }

private:
	std::string gamerTag_;
	float armor_, food_, health_;
};

