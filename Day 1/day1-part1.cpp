#include <iostream>
#include <fstream>

using namespace std;


int main()
{
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
    cout << "Answer:" << maxCalories << endl;
    return 0;
}