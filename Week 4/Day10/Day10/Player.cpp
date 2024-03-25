#include "Player.h"
#include <sstream>


void Player::SerializeCSV(std::ostream& outFile, char delimiter)
{
    outFile << 
        GamerTag() << delimiter <<
        Armor() << delimiter <<
        Food() << delimiter <<
        Health();
}

void Player::DeserializeCSV(const std::string& csvData, char delimiter)
{
    std::stringstream lineStream(csvData);
    std::getline(lineStream, gamerTag_, delimiter);

    std::string data;
    std::getline(lineStream, data, delimiter);
    armor_ = std::stof(data);

    std::getline(lineStream, data, delimiter);
    food_ = std::stof(data);

    std::getline(lineStream, data, delimiter);
    health_ = std::stof(data);
}
