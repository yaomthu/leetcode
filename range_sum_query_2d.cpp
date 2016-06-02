/*
 *Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.

solution: 使用dp[i][j]二维数组存放(0,0), (0,j), (i,0), (i,j)所围矩阵内的和。
time complexity: O(1)
space complexity: O(n^2)
 */

#include <iostream>
#include <vector>
using namespace std;
namespace range_sum_query_2d {
class NumMatrix {
public:
    NumMatrix(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            dp = NULL;
        else {
            dp = new int*[matrix.size()];
            for (int i=0; i<matrix.size(); i++)
                dp[i] = new int[matrix[0].size()];
            for (int i=0; i<matrix.size(); i++) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    if (i == 0 && j == 0)
                        dp[i][j] = matrix[i][j];
                    else if (i == 0)
                        dp[i][j] = dp[i][j-1] + matrix[i][j];
                    else if (j == 0)
                        dp[i][j] = dp[i-1][j] + matrix[i][j];
                    else
                        dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i][j];
                }
            }
            for (int i=0; i<matrix.size(); i++) {
              for (int j=0; j<matrix[0].size(); j++) {
                cout << dp[i][j] << " ";
              }
              cout << endl;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0)
            return dp[row2][col2];
        else if (row1 == 0)
            return dp[row2][col2] - dp[row2][col1-1];
        else if (col1 == 0)
            return dp[row2][col2] - dp[row1-1][col2];
        else
            return dp[row2][col2] - dp[row1-1][col2] - dp[row2][col1-1] + dp[row1-1][col1-1];
    }
private:
    int **dp;
};
}
int main_range_sum_query_2d() {
  int data1[] = {3, 0, 1, 4, 2};
  int data2[] = {5, 6, 3, 2, 1};
  int data3[] = {1, 2, 0, 1, 5};
  int data4[] = {4, 1, 0, 1, 7};
  int data5[] = {1, 0, 3, 0, 5};
  vector<vector<int> > nums;
  nums.push_back(vector<int>(data1, data1+5));
  nums.push_back(vector<int>(data2, data2+5));
  nums.push_back(vector<int>(data3, data3+5));
  nums.push_back(vector<int>(data4, data4+5));
  nums.push_back(vector<int>(data5, data5+5));
  range_sum_query_2d::NumMatrix numMatrix(nums);
  cout << numMatrix.sumRegion(2,1,4,3);
}
