#pragma once
#include <iostream>
#include <string>

/*

	COMPILE-TIME Polymorphism

	Method Overloading:
		- changing the number of parameters
		- changing the types of the parameters

*/
class Calculator
{
public:
	int add(int n1, int n2);
	int add(int n1, int n2, int n3);
	float add(float f1, float f2);
	double add(double d1, double d2);
};


/*

	COMPILE-TIME Polymorphism

	Operator Overloading

*/
class Account
{
private:
	double mBalance;

public:
};




/*

	RUNTIME Polymorphism

	method overriding

*/
class base
{
private:
	int mNum;
public:
	base(int num) : mNum(num)
	{}
	//step 1. mark the base method as "virtual"
	virtual void print()
	{
		std::cout << "Hello base " << mNum << "\n";
	}
};

class derived : public base
{
private:
	std::string mStr;
public:
	derived(std::string str, int num) : base(num), mStr(str)
	{ }
	//step 2. override the method. create another method with the same "signature"
	//step 3. (optional) add the override keyword
	void print() override
	{
		//DECIDE: 
		//  do I want the base method code to run or not?
		//
		std::cout << "I'm a derived: " << mStr << "\t";
		base::print();//call the base method to "EXTEND" the base
		//std::cout << "Hello base " << mNum << "\n";

		//if not, then simply don't call the base method (FULL override)
	}
};
