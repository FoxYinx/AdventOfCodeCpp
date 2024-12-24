#ifndef DOOR_H
#define DOOR_H
#include <array>

using namespace std;

class door {
    array<array<char, 3>, 4> pad = {{{'7', '8', '9'}, {'4', '5', '6'}, {'1', '2', '3'}, {'#', '0', 'A'}}};
public:
    int currentX = 2;
    int currentY = 3;
};



#endif //DOOR_H
