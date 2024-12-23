#include <fstream>
#include <iostream>
#include <map>
#include <ranges>
#include <regex>
#include <vector>
#include "utils.h"

using namespace std;

void bronKerbosch(const vector<string>& R, vector<string> P, vector<string> X, vector<string>& biggest, const map<string, vector<string>>& links);

int year2024_day23_puzzle2() {
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

    vector<string> R;
    vector keys(ranges::begin(links | views::keys), ranges::end(links | views::keys));
    vector<string> X;
    vector<string> biggest;

    bronKerbosch(R, keys, X, biggest, links);

    for (size_t i = 0; i < biggest.size(); i++) {
        cout << biggest[i];
        if (i != biggest.size() - 1) {
            cout << ",";
        }
    }
    return 0;
}

void bronKerbosch(const vector<string>& R, vector<string> P, vector<string> X, vector<string>& biggest, const map<string, vector<string>>& links) {
    if (P.empty() && X.empty()) {
        if (R.size() > biggest.size()) biggest = R;
    } else {
        const string u = !P.empty() ? P.front() : X.front();
        vector<string> P_without_neighbors;
        for (const string& v : P) {
            if (ranges::find(links.at(u), v) == links.at(u).end()) {
                P_without_neighbors.push_back(v);
            }
        }
        for (const string& v : P_without_neighbors) {
            vector<string> Rv = R;
            Rv.push_back(v);
            vector<string> PnV;
            for (const string& v2 : P) {
                if (contains(links.at(v), v2)) PnV.push_back(v2);
            }
            vector<string> XnV;
            for (const string& v2 : X) {
                if (contains(links.at(v), v2)) XnV.push_back(v2);
            }
            bronKerbosch(Rv, PnV, XnV, biggest, links);
            erase(P, v);
            X.push_back(v);
        }
    }
}