/**
 * Burst Ballons
 * Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

solution: 动态规划，dp[i][j] 表示从第i个球到第j个球之间的最优方案，最优表达式为：
dp[i][j] = dp[i][index-1] + nums[i-1]*nums[index]*nums[j+1] + dp[index+1][j].
动态规划的过程是按len = j-i+1 的长度从小到大开始计算，同时记得给nums数组开头增加1，结尾也增加1
time complexity: O(n^3)
space complexity: O(n^2)

 */

#include <iostream>
#include <vector>
using namespace std;
namespace burst_ballons {
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int> > dp(n+2, vector<int>(n+2, 0));
        for (int len = 1; len <= n; len++) {
            for (int start = 1; start + len <= n+1; start++) {
                int end = start+len-1;
                for (int index = start; index <= end; index++) {
                    int score = dp[start][index-1] + nums[start-1]*nums[index]*nums[end+1] + dp[index+1][end];
                    if (score > dp[start][end])
                        dp[start][end] = score;
                }
            }
        }
        return dp[1][n];
    }
};
}

int main_burst_ballons() {
  int data[] = {3,1,5,8};
  vector<int> nums(data, data+4);
  cout << (new burst_ballons::Solution())->maxCoins(nums);
}
