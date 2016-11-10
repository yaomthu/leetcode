/**
 * Number of islands
 * A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]

Challenge:

Can you do it in time complexity O(k log mn), where k is the length of the positions?


union find time complexity is O(n + mlogn) where m is the number of union-find operations, and n is the
number of elements.
 */
#include <iostream>
#include <vector>
using namespace std;

namespace number_of_islands_ii {
class Solution {
public:
    class UF {
        public:
            UF(int n): parents(n, 0), size(n, 1) {
                count = 0;
                for (int i = 0; i < n; i++)
                    parents[i] = i;
            }
            int find(int x) {
                while (x != parents[x]) {
                    parents[x] = parents[parents[x]];
                    x = parents[x];
                }
                return x;
            }
            void unioning(int x, int y) {
                int rootx = find(x);
                int rooty = find(y);
                if (rootx == rooty)
                    return;
                count++;
                if (size[rootx] < size[rooty]) {
                    parents[rootx] = rooty;
                    size[rooty] += size[rootx];
                } else {
                    parents[rooty] = rootx;
                    size[rootx] += size[rooty];
                }
            }
            int getCount() {
                return count;
            }
        private:
            int count;
            vector<int> parents;
            vector<int> size;
    };

    vector<int> numIslands2(int m, int n, vector<pair<int, int> >& positions) {
        vector<int> ans;
        vector<vector<bool> > graph(m, vector<bool>(n, false));
        UF uf(m*n);
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        for (int i = 0; i < positions.size(); i++) {
            graph[positions[i].first][positions[i].second] = true;
            for (int j = 0; j < 4; j++) {
                int nextx = positions[i].first + dx[j];
                int nexty = positions[i].second + dy[j];
                if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && graph[nextx][nexty] == true) {
                    uf.unioning(positions[i].first * n + positions[i].second, nextx * n + nexty);
                }
            }
            ans.push_back(i + 1 - uf.getCount());
        }
        return ans;
    }
};
}

