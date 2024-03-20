#pragma once
#include "Car.h"

//Specializations (what makes the derived class "special" or different from the base)
class FlyingCar : public Car
{

public:
	//CONSTRUCTORS
	//FlyingCar()//no params: default constructor
	//	: maxAltitude_(1000), maxAirspeed_(100)
	//{	}

	FlyingCar(int year, std::string make, std::string model,
		      float maxAltitude, float maxAirspeed)
		: Car(year,make,model),//call the base constructor
		  maxAltitude_(maxAltitude), maxAirspeed_(maxAirspeed)
	{
		std::cout << "\tFlyingCar Ctor\n";


	}

	void CalcFlightPlan(float distance)
	{
		if (distance > FuelLevel())
		{

		}
	}

public:
	//EVERYTHING that is in Car is now in FlyingCar

	float GetMaxAltitude() const { return maxAltitude_; }
	float MaxAirspeed() const { return maxAirspeed_; }

	void SetMaxAltitude(float altitude) { maxAltitude_ = altitude; }
	void MaxAirspeed(float airSpeed) { maxAirspeed_ = airSpeed; }

private:
	float maxAltitude_, maxAirspeed_;
};

