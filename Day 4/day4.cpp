#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

int part1() {
    ifstream in("input.txt");
    string pairs, firstStr, secondStr;
    int res = 0;
    
    while(in >> pairs) {
        firstStr = pairs.substr(0, pairs.find(','));
        secondStr = pairs.substr(pairs.find(',') + 1);
        pair<int, int> first (stoi(firstStr.substr(0, firstStr.find('-'))), stoi(firstStr.substr(firstStr.find('-') + 1)));
        pair<int, int> second (stoi(secondStr.substr(0, secondStr.find('-'))), stoi(secondStr.substr(secondStr.find('-') + 1)));
        
        /*
                        Case 1         Case 2
        First pair:     -------   OR    ----  
        Second pair:     ----         -------
        */
        
        if((first.first <= second.first && first.second >= second.second) || (second.first <= first.first && second.second >= first.second))
            ++res;
    }
    in.close();
    return res;
}

int part2() {
    ifstream in("input.txt");
    string pairs, firstStr, secondStr;
    int res = 0;
    
    while(in >> pairs) {
        firstStr = pairs.substr(0, pairs.find(','));
        secondStr = pairs.substr(pairs.find(',') + 1);
        pair<int, int> first (stoi(firstStr.substr(0, firstStr.find('-'))), stoi(firstStr.substr(firstStr.find('-') + 1)));
        pair<int, int> second (stoi(secondStr.substr(0, secondStr.find('-'))), stoi(secondStr.substr(secondStr.find('-') + 1)));
        
        /*
                        Case 1             Case 2
        First pair:     -------     OR         -----  
        Second pair:        -----         -------
        */

        if((first.first <= second.first && first.second >= second.first) || (second.first <= first.first && second.second >= first.first))
            ++res;
    }
    in.close();
    return res;    
}

int main()
{
    cout << "Part 1 answer: " << part1() << endl;
    cout << "Part 2 answer: " << part2() << endl;
    return 0;
}