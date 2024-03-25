// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Player.h"



/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
    2) read/write to the file
    3) close the file



*/
int main()
{
    std::cout << "Hello PG2!\n";

    Player heroBrine("HeroBrine", 20, 20, 20);


    //1. OPEN the file
    //      - set the path and filename
    //      - open it in the correct mode (output mode - use the ofstream class)
    //  *** - check if the file is open before continuing
    std::string path = "C:\\temp\\2403\\";//this whole path needs to exist before writing the file
    std::string fileName = "player.csv";
    std::string fullPath = fileName;// path + fileName;

    char delimiter = '#';
    {
        std::ofstream outputFile(fullPath);
        if (outputFile.is_open())
        {
            //2. WRITE to the file
            //  << - insertion operator. inserting information into the stream
            heroBrine.SerializeCSV(outputFile, delimiter);
            //outputFile << 
            //    heroBrine.GamerTag() << delimiter <<
            //    heroBrine.Armor() << delimiter <<
            //    heroBrine.Food() << delimiter <<
            //    heroBrine.Health();

            //3. CLOSE the file
            outputFile.close();
        }
        else {
            std::cout << fullPath << " could not be opened.\n";
        }
    }

    std::cout << "PLAYER STATS\n";
    heroBrine.SerializeCSV(std::cout, '\n');

    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used
            to separate the data when reading the file back in.


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */


    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */

    //1. OPEN the file. use ifstream for reading
    //  - check if it's open 
    std::ifstream input(fullPath);
    if (input.is_open())
    {
        //2. READ the file
        std::string line;
        std::getline(input, line);//read the 1 line into the line variable

        //PARSE the string for the player values
        //getline works on streams.
        //convert the string to a stream.
        std::stringstream lineStream(line);
        std::string tag;
        std::getline(lineStream, tag, delimiter); 
        
        std::string data;
        std::getline(lineStream, data, delimiter);
        float armor = std::stof(data);

        std::getline(lineStream, data, delimiter);
        float food = std::stof(data);

        std::getline(lineStream, data, delimiter);
        float health = std::stof(data);

        std::cout << "\n\nReady Player 2\n";
        Player player2(tag, armor, food, health);
        player2.SerializeCSV(std::cout, '\n');


        //std::cout << "\n" << line << "\n";

        //3. CLOSE the file
        input.close();
    }
    else {
        std::cout << fullPath << " could not be opened.\n";
    }


    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */





    /*

        CHALLENGE:

        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data.
        There are multiple delimiters.
        Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        Then, separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';
}