/**
 * Android unlock patterns
 * Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

Rules for a valid pattern:
Each pattern must connect at least m keys and at most n keys.
All the keys must be distinct.
If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
The order of keys used matters.

Explanation:
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
Invalid move: 4 - 1 - 3 - 6
Line 1 - 3 passes through key 2 which had not been selected in the pattern.

Invalid move: 4 - 1 - 9 - 2
Line 1 - 9 passes through key 5 which had not been selected in the pattern.

Valid move: 2 - 4 - 1 - 3 - 6
Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern

Valid move: 6 - 5 - 4 - 1 - 9 - 2
Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.

Example:
Given m = 1, n = 1, return 9.

solution: 注意，本题题意描述不清，1与2，4，5，6，8都是相邻的。
使用skip[i][j] 二维数组来记录数字i和数字j之间会越过哪个数字。
 */

#include <iostream>
#include <vector>
using namespace std;

namespace android_unlock_patterns {
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        if (n <= 0 || m > 9)
            return 0;
        vector<vector<int> > skip(10, vector<int>(10, 0));
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[9][7] = skip[7][9] = 8;
        skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = 5;
        int res = 0;
        for (int num = m; num <= n; num++) {
            vector<bool> visited(10, false);
            res += dfs(skip, visited, 1, num-1) * 4;
            res += dfs(skip, visited, 2, num-1) * 4;
            res += dfs(skip, visited, 5, num-1);
        }
        return res;
    }
    int dfs(vector<vector<int> >& skip, vector<bool>& visited, int cur, int remain) {
        if (remain == 0)
            return 1;
        visited[cur] = true;
        int res = 0;
        for (int next = 1; next <= 9; next++) {
            if (visited[next] == true)
                continue;
            if (skip[cur][next] == 0 || (skip[cur][next] != 0 && visited[skip[cur][next]] == true)) {
                res += dfs(skip, visited, next, remain-1);
            }
        }
        visited[cur] = false;
        return res;
    }
};
}
