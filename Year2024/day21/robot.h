#ifndef ROBOT_H
#define ROBOT_H
#include <array>

using namespace std;

class robot {
    array<array<char, 3>, 2> pad = {{{'#', '^', 'A'}, {'<', 'v', '>'}}};
public:
    int currentX = 2;
    int currentY = 0;
};



#endif //ROBOT_H
