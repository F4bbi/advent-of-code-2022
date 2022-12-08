#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Time Complexity: O(N) 
int part1(string input, int windowSize) {
    // we will store a sentinel value of -1 to simulate 'null'/'None' in C++
    vector<int> char_indexes(26, -1);
    int left = 0, right = 0;
    
    for(; right < input.size(); right++) {
        int c = input.at(right) - 'a';
        int index = char_indexes.at(c);
        /* example of the second condition: abcbad
          'a' at position 0 is outside the window when it's
          found again in position 4 so without the second conditon
           the window would go back ù
        */
        if(index != -1 && (index >= left && index < right))
            left = index + 1;
        if(right - left + 1 == windowSize) return right + 1; //+1 because the task wants the index to start from 1
        char_indexes.at(c) = right;
    }
    return -1;
}

int main()
{
    ifstream in("input.txt");
    string input;
    in >> input;
    cout << "Part 1 answer: " << part1(input, 4) << endl;
    cout << "Part 2 answer: " << part1(input, 14) << endl;
    return 0;
}