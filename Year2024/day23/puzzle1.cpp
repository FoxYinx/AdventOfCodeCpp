#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <vector>

using namespace std;

bool contains(const vector<string>& vec, const string &value);
bool contains(const vector<int>& vec, int value);

int year2024_day23_puzzle1() {
    ifstream f("ressources/Year2024/day23.txt");

    if (!f.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }
    cout << "File successfully opened!" << endl;

    string s;
    const regex regexp(R"((\w+)-(\w+))");
    smatch sm;
    map<string, vector<string>> links = {};
    while (getline(f, s)) {
        while (regex_search(s, sm, regexp)) {
            links[sm[1]].push_back(sm[2]);
            links[sm[2]].push_back(sm[1]);
            s = sm.suffix();
        }
    }
    vector<string> tuples = {};

    for (const auto &[key, value] : links) {
        for (int i = 0; i < value.size() - 1; i++) {
            for (int j = i + 1; j < value.size(); j++) {
                if (value[i] > key && value[j] > key && contains(links[value[i]], value[j])) {
                    tuples.push_back(key + "," + value[i] + "," + value[j]);
                }
            }
        }
    }

    const regex regexp2(R"((^t|,t))");
    int possibilities = 0;
    for (const string& computers : tuples) {
        if (regex_search(computers, sm, regexp2)) possibilities++;
    }

    cout << possibilities << endl;
    return 0;
}

bool contains(const vector<string>& vec, const string &value) {
    return ranges::find(vec, value) != vec.end();
}