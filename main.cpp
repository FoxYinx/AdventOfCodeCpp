#include <fstream>
#include <functional>
#include <iostream>
#include <map>

using namespace std;

// Function declarations
int year2019_day1_puzzle1();
int year2019_day1_puzzle2();
int year2019_day2_puzzle1();
int year2019_day2_puzzle2();
int year2019_day5_puzzle1();
int year2019_day5_puzzle2();
int year2019_day7_puzzle1();
int year2019_day7_puzzle2();
int year2022_day1_puzzle1();
int year2022_day1_puzzle2();
int year2022_day2_puzzle1();
int year2022_day2_puzzle2();
int year2022_day3_puzzle1();
int year2022_day3_puzzle2();
int year2022_day4_puzzle1();
int year2022_day4_puzzle2();
int year2024_day1_puzzle1();
int year2024_day1_puzzle2();
int year2024_day2_puzzle1();
int year2024_day2_puzzle2();
int year2024_day3_puzzle1();
int year2024_day3_puzzle2();
int year2024_day4_puzzle1();
int year2024_day4_puzzle2();
int year2024_day5_puzzle1();
int year2024_day5_puzzle2();
int year2024_day6_puzzle1();
int year2024_day6_puzzle2();
int year2024_day7_puzzle1();
int year2024_day7_puzzle2();
int year2024_day8_puzzle1();
int year2024_day8_puzzle2();
int year2024_day9_puzzle1();
int year2024_day9_puzzle2();
int year2024_day10_puzzle1();
int year2024_day10_puzzle2();
int year2024_day11_puzzle1();
int year2024_day11_puzzle2();
int year2024_day12_puzzle1();
int year2024_day12_puzzle2();
int year2024_day13_puzzle1();
int year2024_day13_puzzle2();
int year2024_day14_puzzle1();
int year2024_day14_puzzle2();
int year2024_day15_puzzle1();
int year2024_day15_puzzle2();
int year2024_day16_puzzle1();
int year2024_day16_puzzle2();
int year2024_day17_puzzle1();
int year2024_day17_puzzle2();
int year2024_day18_puzzle1();
int year2024_day18_puzzle2();
int year2024_day19_puzzle1();
int year2024_day19_puzzle2();
int year2024_day20_puzzle1();
int year2024_day20_puzzle2();
int year2024_day21_puzzle1();
int year2024_day21_puzzle2();
int year2024_day22_puzzle1();
int year2024_day22_puzzle2();
int year2024_day23_puzzle1();
int year2024_day23_puzzle2();
int year2024_day24_puzzle1();
int year2024_day24_puzzle2();

// Function registry
map<string, function<int()> > functions = {
    {"2019-1-1", year2019_day1_puzzle1},
    {"2019-1-2", year2019_day1_puzzle2},
    {"2019-2-1", year2019_day2_puzzle1},
    {"2019-2-2", year2019_day2_puzzle2},
    {"2019-5-1", year2019_day5_puzzle1},
    {"2019-5-2", year2019_day5_puzzle2},
    {"2019-7-1", year2019_day7_puzzle1},
    {"2019-7-2", year2019_day7_puzzle2},
    {"2022-1-1", year2022_day1_puzzle1},
    {"2022-1-2", year2022_day1_puzzle2},
    {"2022-2-1", year2022_day2_puzzle1},
    {"2022-2-2", year2022_day2_puzzle2},
    {"2022-3-1", year2022_day3_puzzle1},
    {"2022-3-2", year2022_day3_puzzle2},
    {"2022-4-1", year2022_day4_puzzle1},
    {"2022-4-2", year2022_day4_puzzle2},
    {"2024-1-1", year2024_day1_puzzle1},
    {"2024-1-2", year2024_day1_puzzle2},
    {"2024-2-1", year2024_day2_puzzle1},
    {"2024-2-2", year2024_day2_puzzle2},
    {"2024-3-1", year2024_day3_puzzle1},
    {"2024-3-2", year2024_day3_puzzle2},
    {"2024-4-1", year2024_day4_puzzle1},
    {"2024-4-2", year2024_day4_puzzle2},
    {"2024-5-1", year2024_day5_puzzle1},
    {"2024-5-2", year2024_day5_puzzle2},
    {"2024-6-1", year2024_day6_puzzle1},
    {"2024-6-2", year2024_day6_puzzle2},
    {"2024-7-1", year2024_day7_puzzle1},
    {"2024-7-2", year2024_day7_puzzle2},
    {"2024-8-1", year2024_day8_puzzle1},
    {"2024-8-2", year2024_day8_puzzle2},
    {"2024-9-1", year2024_day9_puzzle1},
    {"2024-9-2", year2024_day9_puzzle2},
    {"2024-10-1", year2024_day10_puzzle1},
    {"2024-10-2", year2024_day10_puzzle2},
    {"2024-11-1", year2024_day11_puzzle1},
    {"2024-11-2", year2024_day11_puzzle2},
    {"2024-12-1", year2024_day12_puzzle1},
    {"2024-12-2", year2024_day12_puzzle2},
    {"2024-13-1", year2024_day13_puzzle1},
    {"2024-13-2", year2024_day13_puzzle2},
    {"2024-14-1", year2024_day14_puzzle1},
    {"2024-14-2", year2024_day14_puzzle2},
    {"2024-15-1", year2024_day15_puzzle1},
    {"2024-15-2", year2024_day15_puzzle2},
    {"2024-16-1", year2024_day16_puzzle1},
    {"2024-16-2", year2024_day16_puzzle2},
    {"2024-17-1", year2024_day17_puzzle1},
    {"2024-17-2", year2024_day17_puzzle2},
    {"2024-18-1", year2024_day18_puzzle1},
    {"2024-18-2", year2024_day18_puzzle2},
    {"2024-19-1", year2024_day19_puzzle1},
    {"2024-19-2", year2024_day19_puzzle2},
    {"2024-20-1", year2024_day20_puzzle1},
    {"2024-20-2", year2024_day20_puzzle2},
    {"2024-21-1", year2024_day21_puzzle1},
    {"2024-21-2", year2024_day21_puzzle2},
    {"2024-22-1", year2024_day22_puzzle1},
    {"2024-22-2", year2024_day22_puzzle2},
    {"2024-23-1", year2024_day23_puzzle1},
    {"2024-23-2", year2024_day23_puzzle2},
    {"2024-24-1", year2024_day24_puzzle1},
    {"2024-24-2", year2024_day24_puzzle2},
};

int main() {
    int year, day, puzzle;
    cout << "Enter which year: ";
    cin >> year;
    cout << "Enter which day: ";
    cin >> day;
    cout << "Enter which puzzle (1 or 2): ";
    cin >> puzzle;
    if (const string key = to_string(year) + "-" + to_string(day) + "-" + to_string(puzzle); functions.contains(key)) {
        std::cout << "Running Year " << year << " Day " << day << " Part " << puzzle << "...\n";
        return functions[key](); // Call the corresponding function
    }
    std::cout << "Invalid day or part. Please check your input.\n";
    return 1;
}
