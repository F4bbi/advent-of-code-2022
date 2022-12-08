#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int part1() {
    ifstream in("input.txt");
    int maxCalories = 0, calories = 0;
    string input;
    while(!in.eof()) {
        while(getline(in, input) && input != "") {
            calories = calories + stoi(input);
        }
        maxCalories = max(maxCalories, calories);
        calories = 0;
    }
    in.close();
    return maxCalories;
}

int part2() {
    ifstream in("input.txt");
    vector<int> vector;
    int calories = 0;
    string input;
    while(!in.eof()) {
        while(getline(in, input) && input != "") {
            calories = calories + stoi(input);
        }
        vector.push_back(calories);
        calories = 0;
    }
    sort(vector.begin(), vector.end(), greater <>());
    in.close();
    return vector.at(0) + vector.at(1) + vector.at(2);
}

int main()
{
    cout << "Part 1 answer: " << part1() << endl;
    cout << "Part 2 answer: " << part2() << endl;
    return 0;
}