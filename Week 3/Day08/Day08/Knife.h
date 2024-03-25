#pragma once
#include "Weapon.h"
class Knife :
    public Weapon
{
public:
	Knife(int range, int damage) : Weapon(range, damage)
	{

	}
};

