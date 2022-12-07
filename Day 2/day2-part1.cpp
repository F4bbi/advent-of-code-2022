#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("input.txt");
    char opponent, me;
    int score = 0;
    while(in >> opponent >> me) {
        opponent -= 'A', me -= 'X';
        int result = (me - '0') - (opponent - '0');
        // Draw: 0 (e.g rock - rock = 0)
        // Win: 1 (e.g rock - scissor = 0 - 2 = -2 + 3 = 1)
        // Lose: 2 (e.g scissor - rock = 2 - 0 = 2)
        switch ((3 + result) % 3) {
            case 0:
                score += 3;
                break;
            case 1:
                score += 6;
                break;
            default:
                break;
        }
        score = score + me + 1;
    }
    cout << "Answer:" << score << endl;
    return 0;
}