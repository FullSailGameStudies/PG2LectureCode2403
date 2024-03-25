#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:
	int Rounds() const { return rounds_; }
	int MagCapacity() const { return magCapacity_; }

	void Rounds(int rounds) { rounds_ = rounds; }
	void MagCapacity(int magCap) { magCapacity_ = magCap; }

	//CTORS
	Pistol(int range, int damage, int rounds, int magCap)
		: Weapon(range, damage), rounds_(rounds), magCapacity_(magCap)
	{

	}

	Pistol operator+(const Pistol& otherPistol)
	{
		Pistol newPistol(range(), damage(), rounds_ + otherPistol.rounds_, magCapacity_);
		return newPistol;
	}

private:
	int rounds_, magCapacity_;
};

