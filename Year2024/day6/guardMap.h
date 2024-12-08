#ifndef ADVENTOFCODE_GARDMAP_H
#define ADVENTOFCODE_GARDMAP_H

#define SIZE 130

class GuardMap {
public:
    enum Direction {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

    static constexpr int size = SIZE;

    char map[size][size]{};
    bool hasBeenThere[size][size]{};
    Direction direction;
    int gardX;
    int gardY;

    GuardMap();

    [[nodiscard]] bool willBeOutside() const;

    bool move();

    int allCases();

    void reset(int x, int y);
};


#endif //ADVENTOFCODE_GARDMAP_H
