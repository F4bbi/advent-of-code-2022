#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int getPriority(char c) {
    if(c >= 'a' && c <= 'z')
        return c - 'a' + 1;
    else
        return c - 'A' + 27;
}

int part1() {
    ifstream in("input.txt");
    string rucksack, firstComp, secondComp;
    char commonChar;
    int priorities = 0;

    while(in >> rucksack) {
        unordered_map<char, int> map;
        firstComp = rucksack.substr(0, rucksack.size()/2);
        secondComp = rucksack.substr(rucksack.size()/2);
        for(char c : firstComp) 
            map.insert({c, getPriority(c)});
        for(char c : secondComp) {
            if(map.find(c) != map.end()) {
                commonChar = c;
                break;
            }
        }
        priorities += getPriority(commonChar);
    }
    return priorities;
}

int part2() {
    ifstream in("input.txt");
    string first, second, third;
    char commonChar;
    int priorities = 0;

    while(in >> first >> second >> third) {
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        for(char c : first) 
            map1.insert({c, getPriority(c)});
        for(char c : second) {
            if(map1.find(c) != map1.end()) {
                map2.insert({c, getPriority(c)});
            }
        }
        for(char c : third) {
            if(map2.find(c) != map2.end()) {
                commonChar = c;
                break;
            }
        }
        priorities += getPriority(commonChar);
    }
    return priorities;
}

int main()
{
    cout << "Part 1 answer: " << part1() << endl;
    cout << "Part 2 answer: " << part2() << endl;
    return 0;
}