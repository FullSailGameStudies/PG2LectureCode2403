// Day08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Inheritance.h"
#include "Polymorphism.h"
#include "Car.h"
#include "FlyingCar.h"
#include "Pistol.h"
#include "Knife.h"
#include <vector>


int main()
{
	FlyingCar jetsons(2025, "Tesla", "X-Plane", 5000, 500);//created on the stack

	jetsons.refuel(50);

	/*
        ╔═══════════════╗
        ║  Inheritance  ║
        ╚═══════════════╝

								╔═════════╗     ╔══════════╗
				         class  ║SomeClass║  :  ║OtherClass║
								╚═════════╝     ╚══════════╝
									 │                │
									 └──┐             └──┐
								   ┌────▼────┐      ┌────▼────┐
								   │ Derived │      │  Base   │
								   │  Class  │      │  Class  │
								   └─────────┘      └─────────┘

			Access modes:
				public inheritance:
				protected inheritance:
				private inheritance: (default if not specified)
	


				CONSTRUCTORS: the derived constructor must call a base constructor
				public SomeClass(.....) : baseClass(....)


			Lecture Code: add a FlyingCar class that derives from Car
             
    */



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

            add a new class, Pistol, that derives from Weapon.
            Pistol should have fields with getters/setters for rounds and magCapacity.
            Add a constructor that calls the base constructor
	
	*/
	Pistol pewpew(400, 200, 10, 15);
	Pistol pistol(100, 10, 5, 10);

	Pistol newPistol = pewpew + pistol;

	Knife bowie(3, 10);

	std::vector<std::unique_ptr<Weapon>> dorasBackpack;
	//created a pistol and UPCASTED it to a Weapon
	dorasBackpack.push_back(std::make_unique<Pistol>(400, 200, 10, 15));
	dorasBackpack.push_back(std::make_unique<Knife>(3, 10));

	std::unique_ptr<Pistol> banger = std::make_unique<Pistol>(400, 200, 10, 15);
	std::unique_ptr<Weapon> wpn2 = std::move(banger);
	//banger->showMe();
	for (auto& weapon : dorasBackpack)
	{
		weapon->showMe();
	}

	//we LOSE the knife parts
	Weapon wpn = bowie;//cast?? copying the weapon parts of bowie to the new variable


	int num = 5;
	long bigNum = num;//casting? implicit. handled automatically by compiler
	num = bigNum;
	float fNum = (float)num;//casting? explicit



	/*
        ╔═════════════════════════════╗
        ║  COMPILE-TIME Polymorphism  ║
        ╚═════════════════════════════╝

		Method Overloading:
			- changing the number of parameters
			- changing the types of the parameters

		Lecture Code: Overload the refuel method in Car

	*/



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

			Add an OVERLOAD of the calcDamage method in the Weapon class.
			The overload should take an int parameter called modifier
			to increase the damage when calculating the damage.

	*/





	/*
        ╔═════════════════════════════╗
        ║  COMPILE-TIME Polymorphism  ║
        ╚═════════════════════════════╝

		Operator Overloading

		Lecture Code: overload the + operator in Account

	*/



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

		overload the + in the Pistol class to add 2 pistols
			- it sets the magCapacity to the max of the 2 pistols
			- adds the # of rounds from both pistols. should not exceed the magCapacity.
	*/






	/*
        ╔════════════════════════╗
        ║  RUNTIME Polymorphism  ║
        ╚════════════════════════╝

		╔═════════════╗
		║ OVERRIDING  ║ - changing the behavior of a base method
		╚═════════════╝

		1) add 'virtual' to the base method
		2) add a method to the derived class that has the same signature as the base.
			OPTIONALLY put 'override' on the derived method


		FULLY OVERRIDING:
			not calling the base method from the derived method

		EXTENDING:
			calling the base method from the derived method
			to call the base method...  baseClassName::method(...)



		Lecture Code: override the print method in the base/derived classes in the Polymorphism.h file

	*/



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

			Override Weapon's showMe method in the Pistol class.
			In Pistol's version, call the base version then print out the rounds and magCapacity



	*/




	/*
		╔════════════╗
		║ Unique_ptr ║
		╚════════════╝

		Using unique pointers w/ overridden methods


        ╔═══════════╗ 
        ║ UPCASTING ║ - casting a derived type variable to a base type variable
        ╚═══════════╝ 

        This is ALWAYS safe.

	
		To maintain the original object, we need a pointer though. If not, then we're just calling the copy constructor of the base class and lose all the info of the derived.

		Unique pointers owns and manages an object through a pointer.
		std::unique_ptr<derived> pDerived = std::make_unique<derived>("Gotham", 5);

		
		You can upcast by using the base type in the unique_ptr.
		std::unique_ptr<base> pBase = std::make_unique<derived>("Gotham", 5);
		  OR
		std::unique_ptr<base> pBase = std::move(pDerived); https://learn.microsoft.com/en-us/cpp/standard-library/utility-functions?view=msvc-170&redirectedfrom=MSDN&f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(std%253A%253Amove)%3Bk(move)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue#move



		Lecture Code: 
			use make_unique and unique_ptr to create a derived instance
			use std::move to upcast it to a base
	*/
	derived der1("Gotham", 1);
	base base1 = der1; //calls the assignment operator of base therefore you lose all the derived parts. base1 is JUST a base object.
	der1.print();
	std::cout << "\n";

	//base1.print();



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

		Create a vector that holds unique pointers of Weapon.
		Create instances of Weapon and Pistol using make_unique.
		Add them to the vector.

		Loop over the vector and call showMe on each weapon.

	*/

	int  elisha = 7;
	int* maurice = &elisha;
	int& Harry = elisha;
	std::cout << "\n\nPOINTERS! FUN?!\n";
	std::cout << elisha << "\n" << maurice << "\n" << Harry << "\n";
	Harry++;
	//maurice++;//increments the pointer!! not the int
	std::cout << elisha << "\n" << maurice << "\n" << Harry << "\n";

	std::cout << "Derefence the pointer with *\n";
	std::cout << *maurice << "\n";


	//live on the heap instead of the stack
	// use the "new" operator
	FlyingCar* jetsons2 = new FlyingCar(2025, "Tesla", "X-Plane", 10000, 150);
	jetsons2->refuel();
	//MUST clean up dynamic memory (anything that uses "new")
	delete jetsons2;
	jetsons2 = nullptr;
	if(jetsons2 != nullptr)
		jetsons2->refuel();

	{
		std::unique_ptr<FlyingCar> pFlyingCar =
			std::make_unique<FlyingCar>(2025, "Tesla", "X-Plane", 10000, 150);//the data needed for the ctor call

		pFlyingCar->refuel();
	}//the unique ptr goes out of scope and deletes the memory
}

