#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");
    string a, b, c;
    int quantity, from, to;
    vector<vector<char> > ship
    {
        {'W', 'R', 'F'},
        {'T', 'H', 'M', 'C', 'D', 'V', 'W', 'P'},
        {'P', 'M', 'Z', 'N', 'L'},
        {'J', 'C', 'H', 'R'},
        {'C', 'P', 'G', 'H', 'Q', 'T', 'B'},
        {'G', 'C', 'W', 'L', 'F', 'Z'},
        {'W', 'V', 'L', 'Q', 'Z', 'J', 'G', 'C'},
        {'P', 'N', 'R', 'F', 'W', 'T', 'V', 'C'},
        {'J', 'W', 'H', 'G', 'R', 'S', 'V'}
    };
    while (in >> a >> quantity >> b >> from >> c >> to) {
        --from, --to;
        for(int i = 0; i < quantity; i++) {
            char toLoad = ship.at(from).at(ship.at(from).size() - 1);
            ship.at(to).push_back(toLoad);
            ship.at(from).pop_back();
        }
    }
    for(int i = 0; i < ship.size(); i++) {
        cout << ship.at(i).at(ship.at(i).size() - 1);
    }
    cout << endl;
    return 0;
}