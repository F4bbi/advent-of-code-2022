#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string part1(vector<vector<char> > ship) {
    fstream in("input.txt");
    string a, b, c, res;
    int quantity, from, to;
    while (in >> a >> quantity >> b >> from >> c >> to) {
        --from, --to;
        for(int i = 0; i < quantity; i++) {
            char toLoad = ship.at(from).at(ship.at(from).size() - 1);
            ship.at(to).push_back(toLoad);
            ship.at(from).pop_back();
        }
    }
    for(int i = 0; i < ship.size(); i++)
        res.push_back(ship.at(i).at(ship.at(i).size() - 1));

    in.close();
    return res;
}

string part2(vector<vector<char> > ship) {
    fstream in("input.txt");
    string a, b, c, res;
    int quantity, from, to;
    while (in >> a >> quantity >> b >> from >> c >> to) {
        --from, --to;
        for(int i = ship.at(from).size() - quantity; i < ship.at(from).size(); i++) {
            char toLoad = ship.at(from).at(i);
            ship.at(to).push_back(toLoad);
        }
        for(int i = 0; i < quantity; i++)
            ship.at(from).pop_back();
    }
    
    for(int i = 0; i < ship.size(); i++)
        res.push_back(ship.at(i).at(ship.at(i).size() - 1));

    in.close();
    return res;
}

int main() {
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
    cout << "Part 1 answer: " << part1(ship) << endl;
    cout << "Part 2 answer: " << part2(ship) << endl;
    return 0;
}