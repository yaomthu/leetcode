/**
 * number of islands
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011


solution : 使用union-find算法来进行求解。
 */

#include <iostream>
#include <vector>
using namespace std;

namespace number_of_islands {
class Solution {
public:
    class UF {
      public:
        UF(int len, vector<vector<char> >& grid) : parents(len, 0) {
          int m = grid.size(), n = grid[0].size();
          count = 0;
          for (int i = 0; i < m; i++) {
              for (int j = 0 ; j < n; j++) {
                  if (grid[i][j] == '1')
                    count++;
                  parents[i*n + j] = i*n + j;
              }
          }
        }
        int find(int x) {
            while (x != parents[x]) {
                parents[x] = parents[parents[x]];
                x = parents[x];
            }
            return x;
        }
        void uni(int x, int y) {
            int rootx = find(x);
            int rooty = find(y);
            if (rootx == rooty)
                return;
            count--;
            parents[rootx] = rooty;
        }
        int count;
        vector<int> parents;
    };
    int numIslands(vector<vector<char> >& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        UF uf(m*n, grid);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    if (i-1 >= 0 && grid[i-1][j] == '1')
                        uf.uni(i*n+j, (i-1)*n+j);
                    if (j-1 >= 0 && grid[i][j-1] == '1')
                        uf.uni(i*n+j, i*n+j-1);
                }
            }
        }
        return uf.count;
    }
};
}
