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
    cout << "Answer:" << priorities << endl;
    return 0;
}