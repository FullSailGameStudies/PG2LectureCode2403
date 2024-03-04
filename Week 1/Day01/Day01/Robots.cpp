#include "Robots.h"
#include <iostream>

//method DEFINITIONS (the code for the methods)
void Robots::MowingBot()
{
	std::cout << "Mowing the lawn...";
	std::cout << "DONE! Charging now.\n";
}

void Robots::CleaningBot(std::string roomToClean)
{
	std::cout << "Cleaning the " << roomToClean << "...\n";
	std::cout << "DONE! Charging now.\n";
}

std::string Robots::ChefBot(std::string recipe, std::vector<std::string> ingredients)
{
	std::cout << "Cooking " << recipe << " with ";
	for (int i = 0; i < ingredients.size(); i++)
	{
		//ternary operator
		//(condition) ? (true block) : (false block)
		//shorthand for if-else
		std::cout << ingredients[i] << ((i < ingredients.size() - 1) ? ", " : "\n");
	}
	std::cout << "DONE! Charging now.\n";
	return recipe;
}
