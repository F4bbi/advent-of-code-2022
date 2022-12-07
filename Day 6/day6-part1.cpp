#include <iostream>
#include <fstream>
#include <string>
#include <bit>

using namespace std;

// Time Complexity: O(4(n-3)) = O(N) 
int getIndex(string input) {
    int window = 4;
    for(int i = window; i < input.size(); i++) {
        uint32_t bitVector {0};
        int j;
        for(j = i - window; j < i; j++)
            bitVector |= (1 << (input.at(j) - 'a'));

        /* be sure to compile with C++20 or above to use popcount() */
        if(popcount(bitVector) == window)
            return j;
    }
    return -1;
}

int main()
{
    ifstream in("input.txt");
    string input;
    in >> input;
    cout << "Answer: " << getIndex(input) << endl;
    return 0;
}