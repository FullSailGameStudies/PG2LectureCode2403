#pragma once
#include <vector>
#include <string>
class Robots
{
public:
	//[return type] [method name]([parameters] )

	//a method DECLARATION ends with ; and NO { }
	void MowingBot();
	void CleaningBot(std::string roomToClean);
	std::string ChefBot(std::string recipe, std::vector<std::string> ingredients);
};

