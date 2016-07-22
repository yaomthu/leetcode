/**
 * best meeting point
 * A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

For example, given three people living at (0,0), (0,4), and (2,2):

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.
 Solution: 先考虑一维问题，一维问题其实是电梯停在哪一层问题。接着考虑二维问题，我们可以分别考虑最终点的行和列。
从而将二维问题降为一维问题。
time complexity: O(mn)
space complexity: O(m + n)

 */
#include <iostream>
#include <vector>
using namespace std;

namespace best_meeting_point {
class Solution {
public:
    int minTotalDistance(vector<vector<int> >& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }

        return minDist(row) + minDist(col);
    }
    int minDist(vector<int>& nums) {
        int dis = 0;
        int lower = 0, upper = 0;
        for (int i = 0; i < nums.size(); i++) {
            dis += (i + 1) * nums[i];
            upper += nums[i];
        }
        int ans = dis;
        for (int i = 0; i < nums.size(); i++) {
            dis += lower - upper;
            lower += nums[i];
            upper -= nums[i];
            if (dis < ans)
                ans = dis;
        }
        return ans;
    }
};
}

int main_best_meeting_point() {
  vector<vector<int> > grid;
  int data1[] = {1,0,0,0,1};
  int data2[] = {0,0,0,0,0};
  int data3[] = {0,0,1,0,0};
  grid.push_back(vector<int>(data1, data1+5));
  grid.push_back(vector<int>(data2, data2+5));
  grid.push_back(vector<int>(data3, data3+5));
  best_meeting_point::Solution solution;
  cout << solution.minTotalDistance(grid);
}
