#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <limits.h>

using namespace std;

vector<vector<int> > getForest(fstream &input) {
    string line;
    vector<vector<int> > forest;
    int i = 0;
    while(getline(input, line)) {
        vector<int> tmp;
        for(char c : line)
            tmp.push_back(c - '0');
        forest.push_back(tmp);
        ++i;
    }
    return forest;
}

bool insideForest(int i, int j, int row, int col) {
    return (i > 0 && i < row-1 && j > 0 && j < col-1);
}

int check(int i, int j, vector<vector<int> > forest, pair<int, int> direction, int col, int row, bool part2 = false) {
    int target = forest.at(i).at(j);
    int seen = 0;
    while(insideForest(i, j, row, col)) {
        i += direction.first;
        j += direction.second;
        ++seen;
        int test = forest.at(i).at(j);
        if(forest.at(i).at(j) >= target)
            return part2 ? seen : false;
    }
    return part2 ? seen : true;
}

int part1(vector<vector<int> > forest) {
    int col = forest.size(), row = forest.at(0).size();
    int res = 2*col + 2*row - 4;
    for(int i = 1; i < col - 1; i++) {
        for(int j = 1; j < row - 1; j++) {
            if (
                check(i, j, forest, {1, 0}, col, row) || 
                check(i, j, forest, {-1, 0}, col, row) || 
                check(i, j, forest, {0, 1}, col, row) ||
                check(i, j, forest, {0, -1}, col, row)
            )
                ++res;
        }
    }
    return res;
}

int part2(vector<vector<int> > forest) {
    int col = forest.size(), row = forest.at(0).size();
    int res = 0, tmpRes;
    for(int i = 1; i < col - 1; i++) {
        for(int j = 1; j < row - 1; j++) {
            int tmpRes = check(i, j, forest, {1, 0}, col, row, true) *  
                         check(i, j, forest, {-1, 0}, col, row, true) * 
                         check(i, j, forest, {0, 1}, col, row, true) *
                         check(i, j, forest, {0, -1}, col, row, true);
            res = max(res, tmpRes);
        }
    }
    return res;
}


int main()
{
    fstream in("input.txt");
    vector<vector<int> > forest = getForest(in);
    cout << "Part 1 answer: " << part1(forest) << endl;
    cout << "Part 2 answer: " << part2(forest) << endl;
}