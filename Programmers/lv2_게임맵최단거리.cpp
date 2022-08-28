#include <iostream>
#include<vector>
#include<queue>

using namespace std;

int lvl[100][100];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int solution(vector<vector<int> > maps)
{
    queue<pair<int, int>> q;

    int n = maps.size();
    int m = maps[0].size();

    int x, y;

    q.push({ 0, 0 });
    maps[0][0] = 0;

    while (!q.empty()) {

        pair<int, int> t = q.front();

        q.pop();

        x = t.first;
        y = t.second;

        if (x == m - 1 && y == n - 1)
            return lvl[y][x] + 1;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < m && 0 <= ny && ny < n && maps[ny][nx]) {
                q.push({ nx, ny });
                lvl[ny][nx] = lvl[y][x] + 1;
                maps[ny][nx] = 0;
            }
        }
    }

    return -1;
}

int main()
{
    vector<vector<int>> vec = {
        {1, 0, 1, 1, 1}, 
        {1, 0, 1, 0, 1}, 
        {1, 0, 1, 1, 1}, 
        {1, 1, 1, 0, 1}, 
        {0, 0, 0, 0, 1}
    };

    int n = solution(vec);

    //print
    printf("%d\n", n);

    return 0;
}
