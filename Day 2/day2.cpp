#include <iostream>
#include <fstream>

using namespace std;

int part1() {
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
    in.close();
    return score;
}

int part2() {
    ifstream in("input.txt");
    char opponent, result;
    int score = 0;
    while(in >> opponent >> result) {
        opponent -= 'A', result -= 'X';
        // Lose = 0, Draw = 3, Win = 6
        score += result * 3;
        score += ((opponent + (result + 2) % 3) % 3) + 1;
    }
    in.close();
    return score;
}

int main() {
    cout << "Part 1 answer: " << part1() << endl;
    cout << "Part 2 answer: " << part2() << endl;
}