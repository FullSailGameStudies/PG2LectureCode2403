// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

//GOAL: trying to find the index of the item in the vector

/// <summary>
/// Search a vector for a number
/// </summary>
/// <param name="numbers">the vector to search</param>
/// <param name="searchTerm">the number to find</param>
/// <returns>-1 if not found. the index if found.</returns>
int LinearSearch(std::vector<int> numbers, int searchTerm)
{
    //what to return if the searchTerm is NOT found?
    //-1 b/c that's an invalid index
    //therefore, the calling code will know if it's not found

    int foundIndex = -1;
    for (int i = 0; i < numbers.size(); i++)
    {
        //was a match found?
        if (searchTerm == numbers[i])
        {
            foundIndex = i;
            break;
        }
    }
    return foundIndex;
}

void PrintGrades(const std::map<std::string, double>& course)
{
    std::cout << "\n\nGrades for PG2: 2403\n";
    for (auto& [name,grade] : course)
    {
        std::cout << std::setw(15) << std::left << name << "  " << std::setw(7) << std::right << grade << "\n";
    }
}

int main()
{
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE 1:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    //# of items: 7  N = 7. worst-case we have to look at all 7 items.
    //O(N) - Linear
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = 15;
    int index = LinearSearch(numbers, searchNumber);
    if (index == -1) //not found
    {
        std::cout << searchNumber << " was not found.\n";
    }



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a Dictionaruy:
        1) using the insert method.
        3) using [key] = value
    */
    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map



    std::map<std::string, float> menu;

    //to add a key-value pair to a map...
    //1) the insert method
    std::pair<std::string, float> keyValuePair = std::make_pair("Steak", 19.99F);
    std::cout << keyValuePair.first << " " << keyValuePair.second << "\n";

    //gives us an iterator into the map
    //AND a bool that tells us if it was inserted
    auto result = menu.insert(keyValuePair);//will not overwrite if the item is already in the map
    if (result.second)
    {
        //the item was inserted
    }

    //2) use the [key] = value
    menu["Baked Potato"] = 4.99F;
    menu["Baked Potato"] = 5.99F;//will overwrite the value

    menu["Cookies-n-Cream Ice Cream"] = 7.99F;

    for (auto& pair : menu)
    {

    }
    std::cout << "\n\nPG2 Cafe\n";
    //const prevents it from changing
    //& - reference prevents a copy
    for (const auto& [menuItem,menuPrice] : menu)
    {
        std::cout << std::setw(7) << menuPrice << " " << menuItem << "\n";
    }

    std::cout << "\n\nPG2 Cafe\n";
    for (auto iter = menu.begin(); iter != menu.end(); iter++)
    {
        std::cout << std::setw(7) << iter->second << " " << iter->first << "\n";
    }


    //float price = menu["Cheesy Fries"];//??
    //std::cout << "Cheesy Fries costs " << price << "\n";
    //DO NOT LOOP to find a key
    std::string itemToFind = "Cheesy Fries";
    auto foundItem = menu.find(itemToFind);
    //foundItem is an iterator that points to a key-value pair
    //foundItem->first on foundItem is the key
    //foundItem->second is the value

    if (foundItem == menu.end()) //NOT FOUND
    {
        std::cout << itemToFind << " is not on the menu. May I suggest that you go to McDonald's\n";
    }
    else //the item was found
    {
        std::cout << itemToFind << " costs " << foundItem->second << "\n";
    }

    //menu[itemToFind] = 9.99F;
    //menu[itemToFind] = 7.99F;//update the value

    itemToFind = "Steak";
    foundItem = menu.find(itemToFind);
    if (foundItem != menu.end())
    {
        float oldPrice = menu[itemToFind];
        foundItem->second += 4;
        float newPrice = menu[itemToFind];
        std::cout << itemToFind << " used to costs " << oldPrice << ".";
        std::cout << " Now it costs " << newPrice << "!! Thanks Putin.\n\n\n";
    }

    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }





    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an exisiting value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe


    /*
        Map CHALLENGE:

            1) Create a map that stores names (string) and grades. 
                Call the variable grades.
            2) Add students and grades to your map.
            3) Loop over your grades map and print each student name and grade.

            4) look for a specific student in the map.
                If the student is found, print out the student's grade
                else print out a message that the student was not found

            5) Pick any student and curve the grade (add 5) that is stored in the grades map
    */

    std::vector<std::string> students{
    "Maurice", "Ridchy", "Eric (J)", "Vincent", "Dominick", "Charles", "Samuel", "Rory", "Angel",
    "Eli'-sha", "Katherine", "Erick", "Aidan", "Linette", "Je'Kysaun", "William", "Dajai", "Reece",
    "Corbin", "Kyle", "Luc", "Thomas", "Cecil", "David", "Hector", "Joel", "Mackenzie",
    "Michael", "Nylah", "Tobey", "Xavier"
    };
    srand(time(NULL));
    std::map<std::string, double> pg2;
    for (auto& name : students)
    {
        pg2[name] = rand() % 10001 / 100.0F;
    }
    PrintGrades(pg2);

    std::string nameToFind = "Eli'-sha";
    auto foundStudent = pg2.find(nameToFind);
    if (foundStudent != pg2.end())
    {
        double grade = foundStudent->second;
        foundStudent->second = std::min(100.0, grade + 5);
        std::cout << foundStudent->first << " had a grade of " << grade << ".\n";
        std::cout << "Now the grade is " << foundStudent->second << ".\n";
        PrintGrades(pg2);
    }
    else
        std::cout << nameToFind << " was not found.\n";

}