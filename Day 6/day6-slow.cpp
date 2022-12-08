#include <iostream>
#include <fstream>
#include <string>
#include <bit>

using namespace std;

// Time Complexity: O(4(n-3)) = O(N) 
int part1(string input, int windowSize) {
    for(int i = windowSize; i < input.size(); i++) {
        uint32_t bitVector {0};
        int j;
        for(j = i - windowSize; j < i; j++)
            bitVector |= (1 << (input.at(j) - 'a'));

        /* be sure to compile with C++20 or above to use popcount() */
        if(popcount(bitVector) == windowSize)
            return j;
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