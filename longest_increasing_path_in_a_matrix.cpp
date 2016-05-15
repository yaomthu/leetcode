/**
 * Longest Increasing Path in a Matrix
 * Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

solution: 从矩阵的每个元素(i,j)出发dfs寻找最长递增序列，同时使用farest[i][j]矩阵记录从(i,j)开始的最长递增序列长度。
time complexity: O(m*n)
space complexity: O(m*n)
 */

#include <iostream>
#include <vector>
using namespace std;

namespace longest_increasing_path_in_a_matrix {
class Solution {
public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > farest(m, vector<int>(n, 0));
        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                dfs(matrix, farest, i, j);
                if (farest[i][j] > ans)
                    ans = farest[i][j];
            }
        }
        return ans;
    }
    int dfs(vector<vector<int> >& matrix, vector<vector<int> >& farest, int x, int y) {
        if (farest[x][y] > 0)
            return farest[x][y];
        int m = matrix.size(), n = matrix[0].size();
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        int max_neighour = 0;
        for (int i=0; i<4; i++) {
            int nextx = x+dx[i];
            int nexty = y+dy[i];
            if (nextx>=0 && nextx<m && nexty>=0 && nexty<n && matrix[nextx][nexty] > matrix[x][y] && dfs(matrix, farest, nextx, nexty) > max_neighour)
                max_neighour = dfs(matrix, farest, nextx, nexty);
        }
        farest[x][y] = max_neighour+1;
        return farest[x][y];
    }
};
}

