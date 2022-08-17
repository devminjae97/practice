#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool map[500][500][4];

vector<int> solution(vector<string> grid) {
    vector<int> answer;

    int len_column = grid.size();
    int len_row = grid[0].length();
    int x, y, dir, nodes;

    for (x = 0; x < len_row; x++) {
        for (y = 0; y < len_column; y++) {
            for (dir = 0; dir < 4; dir++) {
                nodes = 0;

                while (!map[y][x][dir]) {
                    //save
                    map[y][x][dir] = true;
                    nodes++;

                    //calculate
                    switch (dir) {
                    case 0: y = (y + len_column - 1) % len_column; break;
                    case 1: x = (x + len_row - 1) % len_row; break;
                    case 2: y = (y + 1) % len_column; break;
                    case 3: x = (x + 1) % len_row; break;
                    }

                    switch (grid[y][x]) {
                    case'S': break;
                    case'L': dir = (dir + 1) % 4; break;
                    case'R': dir = (dir + 3) % 4; break;
                    }
                }

                if (nodes != 0)
                    answer.push_back(nodes);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}


int main() {

    vector<string> q = { "SL", "LR" };

    vector<int> nodes = solution(q);

    // print
    for (int i = 0; i != nodes.size(); i++) {
        cout << nodes[i] << " ";
    }

    return 0;
}
