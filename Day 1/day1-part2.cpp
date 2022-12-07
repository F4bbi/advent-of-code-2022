#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
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
    cout << "Answer:" << vector.at(0) + vector.at(1) + vector.at(2) << endl;
    return 0;
}