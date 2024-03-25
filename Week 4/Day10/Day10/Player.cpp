#include "Player.h"

void Player::SerializeCSV(std::ostream& outFile, char delimiter)
{
    outFile << 
        GamerTag() << delimiter <<
        Armor() << delimiter <<
        Food() << delimiter <<
        Health();
}
