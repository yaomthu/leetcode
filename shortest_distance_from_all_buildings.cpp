/**
 * Shortest distance from all buildings
 * You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.
 solution: 从各个building出发，基于queue进行bfs搜索到达所有空区域的最短路径。当从一个building出发开始bfs时，
 这有个很好的思路可以避免空区域被多次访问，即每次空区域访问过后就减去1.

 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace shortest_distance_from_all_buildings {
class Solution {
public:
    int shortestDistance(vector<vector<int> >& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        auto total = grid;
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        int minDist;
        int walk = 0;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] == 1) {
                    minDist = -1;
                    auto dist = grid;
                    queue<pair<int,int> > Q;
                    Q.push(make_pair(x, y));
                    while (Q.size()) {
                        auto cur = Q.front();
                        Q.pop();
                        for (int i = 0; i < 4; i++) {
                            int nextx = cur.first + dx[i];
                            int nexty = cur.second + dy[i];
                            if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && grid[nextx][nexty] == walk) {
                                grid[nextx][nexty]--;
                                dist[nextx][nexty] = dist[cur.first][cur.second] + 1;
                                // -1 是因为dist[building.x][building.y] = 1，而不是0
                                total[nextx][nexty] += dist[nextx][nexty] - 1;
                                if (minDist < 0 || minDist > total[nextx][nexty])
                                    minDist = total[nextx][nexty];
                                Q.push(make_pair(nextx, nexty));
                            }
                        }
                    }
                    walk--;
                }
            }
        }
        return minDist;
    }
};
}
