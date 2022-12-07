#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("input.txt");
    char opponent, result;
    int score = 0;
    while(in >> opponent >> result) {
        opponent -= 'A', result -= 'X';
        // Lose = 0, Draw = 3, Win = 6
        score += result * 3;
        score += ((opponent + (result + 2) % 3) % 3) + 1;
    }
    cout << "Answer:" << score << endl;
    return 0;
}