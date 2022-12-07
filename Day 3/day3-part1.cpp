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

int main()
{
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
    cout << "Answer:" << priorities << endl;
    return 0;
}