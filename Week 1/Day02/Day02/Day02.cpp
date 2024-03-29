﻿// Day02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

enum Material
{
	Wood, Stone, Iron, Gold, Diamond
};
class Pickaxe
{
public:
	void ShowMe() const;
private:
	Material toolMaterial = Diamond;
};


void Pickaxe::ShowMe() const
{
	//toolMaterial = Material::Gold; //can't be changed b/c it is a field of the class
	std::string materialName;//this is just a local variable and can be changed
	switch (toolMaterial)
	{
	case Wood:
		materialName = "Wood";
		break;
	case Stone:
		materialName = "Stone";
		break;
	case Iron:
		materialName = "Iron";
		break;
	case Gold:
		materialName = "Gold";
		break;
	case Diamond:
		materialName = "Diamond";
		break;
	default:
		break;
	}
	std::cout << "I am a " << materialName << " pickaxe.\n";
}

bool postFix(std::string& hero)
{
	srand((unsigned int)time(NULL));
	int postFixNumber = rand() % 1000;
	hero = hero + "-" + std::to_string(postFixNumber);
	return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
	//scores.push_back(5); //not allowed because it is marked as const
	float sum = 0;
	for (auto score : scores)
		sum += score;

	return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
	std::cout << "----SCORES----\n";
	int index = 1;
	for (int score : scores)
		std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
	//size: says how many items are in the vector
	//capacity: says how big the internal array is
	std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

//index range of a vector: 0 to size()-1
//the capacity is always > or = size.


void PassByValue(int numbie)//the value gets COPIED from whoever calls it
{
	numbie += 1000;
	std::cout << numbie << "\n";
}
void PassByReference(int& numbie)//a new name is given to the variable in main
{
	numbie += 1000;
	std::cout << numbie << "\n";
}
void GetGrades(std::vector<float>& course)
{
	for (size_t i = 0; i < 10; i++)
	{
		course.push_back(rand() % 10001 / 100.0F);
	}
}

//pass by reference to prevent a copy of the vector
//const prevents any changes to the parameter
void PrintGrades(const std::vector<float>& course)
{
	//course[0] = 100;
	std::cout << "\nPG2 Grades for 2403\n";
	std::cout <<   "-------------------\n";
	for (auto& grade : course)
	{
		std::cout << grade << "\n";
	}
}
int main()
{
	int number = 5;
	PassByValue(number);
	std::cout << number << "\n";

	PassByReference(number);
	std::cout << number << "\n\n";

	int& numbie = number;//both variables point to the same memory location

	int* pNumber = &numbie;

	std::cout << &numbie << "\n" << &number << "\n";

	/*
		╔══════════════════════════════╗
		║Parameters: Pass by Reference.║
		╚══════════════════════════════╝
		Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

		NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
			This is because the parameter is actually just a new name for the other variable.
	*/
	std::string spider = "Spiderman";
	bool isEven = postFix(spider);
	std::string evenResult = (isEven) ? "TRUE" : "FALSE";
	std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


	/*
		CHALLENGE 1:

			Write a method to fill the vector of floats with grades.
			1) pass it in by reference
			2) add 10 grades to the vector

	*/
	std::vector<float> grades;
	std::cout << "\for loop\n";
	for (size_t i = 0; i < grades.size(); i++)
	{
		float grade = grades[i];//making a copy of the value in the vector
		std::cout << grade << "\n";
	}
	std::cout << "\nRange-based loop\n";
	for (float& grade : grades)
	{
		std::cout << grade << "\n";
	}

	PrintGrades(grades);



	/*
		╔══════════════════╗
		║ const parameters ║
		╚══════════════════╝
		const is short for constant. It prevents the variable from being changed in the method.

		This is the way you pass by reference and prevent the method from changing the variable.
	*/
	std::vector<int> highScores;
	highScores.reserve(20);
	printInfo(highScores);
	for (int i = 0; i < 20; ++i)
	{
		highScores.push_back(rand() % 5000);
		printInfo(highScores);
	}
	float avg = average(highScores);

	auto otherScores = highScores;
	print(highScores);
	//remove all scores < 2500
	for (auto iter = highScores.begin();iter != highScores.end(); )
	{
		if ((*iter) < 2500)
		{
			iter = highScores.erase(iter);
		}
		else
			iter++;
	}
	print(highScores);


	print(otherScores);
	for (size_t i = 0; i < otherScores.size(); i++)
	{
		if (otherScores[i] < 2500)
		{
			otherScores.erase(otherScores.begin() + i);
			i--;
		}
	}
	for (int i = otherScores.size() - 1; i >= 0; i--)
	{
		if (otherScores[i] < 2500)
			otherScores.erase(otherScores.begin() + i);
	}
	print(otherScores);



	/*
		CHALLENGE 2:

			Write a method to calculate the stats on a vector of grades
			1) create a method to calculate the min, max.
				pass the grades vector as a const reference. Use ref parameters for min and max.
			2) call the method in main and print out the min, max.

	*/





	/*
		╔═══════════╗
		║ vector<T> ║
		╚═══════════╝

		[  Removing from a vector  ]

		clear() - removes all elements from the vector
		erase(position) - removes the element at the position
		erase(starting position, ending position) - removes a range of elements. the end position is not erased.

	*/
	print(highScores);

	for (size_t i = 0; i < highScores.size();)
	{
		if (highScores[i] < 2500)
			highScores.erase(highScores.begin() + i);
		else
			++i;
	}


	/*
		INTERMEDIATE LEVEL...
		a way using std::remove_if and a lambda
	highScores.erase(
		std::remove_if(highScores.begin(),
			highScores.end(),
			[](int score) { return score < 2500; }),
		highScores.end());
	*/


	print(highScores);



	/*
		CHALLENGE 3:

			Using the vector of grades you created.
			Remove all the failing grades (grades < 59.5).
			Print the grades.
	*/





	/*
		╔═══════════╗
		║ vector<T> ║
		╚═══════════╝


		size(): # of items that have been ADDED
		capacity(): length of the internal array
		reserve(n): presizes the internal array
	*/
	std::vector<int> scores;
	scores.reserve(10); //makes the internal array to hold 10 items.

	printInfo(scores);
}