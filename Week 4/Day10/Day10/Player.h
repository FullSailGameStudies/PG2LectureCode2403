#pragma once
#include <string>
#include <fstream>

class Player
{
public:

	Player(const std::string& tag, float armor, float food, float health)
		: gamerTag_(tag), armor_(armor), food_(food), health_(health)
	{
	}

	Player(const std::string& csvData, char delimiter)
	{
		DeserializeCSV(csvData, delimiter);
	}

	std::string GamerTag() const { return gamerTag_; }
	float Armor() const { return armor_; }
	float Food() const { return food_; }
	float Health() const { return health_; }

	void SerializeCSV(std::ostream& outFile, char delimiter);//where and what delimiter)
	void DeserializeCSV(const std::string& csvData, char delimiter);

private:
	std::string gamerTag_;
	float armor_, food_, health_;
};

