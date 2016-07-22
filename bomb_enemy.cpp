/**
 * Bomb Enemy
 * Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note that you can only put the bomb at an empty cell.

Example:
For the given grid

0 E 0 0
E 0 W E
0 E 0 0

return 3. (Placing a bomb at (1,1) kills 3 enemies)

solution1： 计算每个point的四个方向的E数。
time complexity: O(mn)
space complexity: O(mn)

solution2: 使用rowhits记录某一行从头开始有多少个E，colhits[j]记录第j列从头开始有多少个E。但需要更新rowhits
和colhits[j]
time complexity: O(mn)
space complexity: O(n)
 */

#include <iostream>
#include <vector>
using namespace std;

namespace bomb_enemy {
class Solution {
public:
    int maxKilledEnemies(vector<vector<char> >& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > matrix(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            int curSum = 0;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'W')
                    curSum = 0;
                else if (grid[i][j] == 'E')
                    curSum++;
                matrix[i][j] += curSum;
            }
        }
        for (int i = 0; i < m; i++) {
            int curSum = 0;
            for (int j = n-1; j >= 0; j--) {
                if (grid[i][j] == 'W')
                    curSum = 0;
                else if (grid[i][j] == 'E')
                    curSum++;
                matrix[i][j] += curSum;
            }
        }
        for (int j = 0; j < n; j++) {
            int curSum = 0;
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 'W')
                    curSum = 0;
                else if (grid[i][j] == 'E')
                    curSum++;
                matrix[i][j] += curSum;
            }
        }
        for (int j = 0; j < n; j++) {
            int curSum = 0;
            for (int i = m-1; i >= 0; i--) {
                if (grid[i][j] == 'W')
                    curSum = 0;
                else if (grid[i][j] == 'E')
                    curSum++;
                matrix[i][j] += curSum;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0' && matrix[i][j] > ans)
                    ans = matrix[i][j];
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    int maxKilledEnemies(vector<vector<char> >& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int rowhits = 0;
        vector<int> colhits(n, 0);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!j || grid[i][j-1] == 'W') {
                    rowhits = 0;
                    for (int k = j; k < n && grid[i][k] != 'W'; k++)
                        rowhits += grid[i][k] == 'E'? 1 : 0;
                }
                if (!i || grid[i-1][j] == 'W') {
                    colhits[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; k++)
                       colhits[j] += grid[k][j] == 'E'? 1 : 0;
                }
                if (grid[i][j] == '0' && ans < rowhits + colhits[j])
                    ans = rowhits + colhits[j];

            }
        }
        return ans;
    }
};
}
