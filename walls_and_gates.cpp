/**
 * Walls and Gates
 * You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace walls_and_gates {
class Solution {
public:
    void wallsAndGates(vector<vector<int> >& rooms) {
        if (rooms.empty() || rooms[0].empty())
            return;
        int m = rooms.size(), n = rooms[0].size();
        int dx[] = {0, 0, 1, -1};
        int dy[] = {-1, 1, 0, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                queue<pair<int,int> > Q;
                if (rooms[i][j] == 0) {
                    Q.push(make_pair(i, j));
                    while (Q.size()) {
                        auto cur = Q.front();
                        Q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nextx = cur.first + dx[k];
                            int nexty = cur.second + dy[k];
                            if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && rooms[nextx][nexty] != -1 && rooms[nextx][nexty] > rooms[cur.first][cur.second] + 1) {
                                rooms[nextx][nexty] = rooms[cur.first][cur.second] + 1;
                                Q.push(make_pair(nextx, nexty));
                            }
                        }
                    }
                }
            }
        }
    }
};
}
