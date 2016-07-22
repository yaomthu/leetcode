/**
 * Range Sum Query 2D mutale
 * Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

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
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10
Note:
The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.

solution:
使用四叉树，树的每个节点记录矩阵的左上角点，右下角点和这个该矩形所包含元素的和，同时记录四个子节点信息，分别为矩形的
左上角，右上角，左下角和右下角节点。
sumRange方法实现：先实现子方法overlap用于判断两个矩形是否有重叠。sumRange方法的实现：先使用overlap判断目标矩阵与节点
表示的矩阵是否重叠，若未重叠直接返回。再判断目标矩阵是否完全覆盖节点表示的矩阵，若完全覆盖则直接返回节点的sum。最后针对
节点的四个子节点再进行dfs。
update方法实现：先计算出目标元素的diff，然后dfs遍历所有包含该元素的节点进行更新sum的操作。

time complexity:
建树复杂度为：O(mn)
sumRange复杂度为：O(log(mn))
update复杂度为：O(log(mn))

space complexity: O(mn)
 */
#include <iostream>
#include <vector>
using namespace std;

namespace range_sum_query_2d_mutable {
struct TreeNode {
  int sum;
  pair<int, int> leftCorner;
  pair<int, int> rightCorner;
  // childs[0]: leftUp, childs[1]: rightUp, childs[2]: leftDown, childs[3]: rightDown
  TreeNode* childs[4];
  TreeNode(int sum_, pair<int,int> leftCorner_, pair<int,int> rightCorner_) : sum(sum_),
      leftCorner(leftCorner_), rightCorner(rightCorner_) {
    for (int i = 0; i < 4; i++)
      childs[i] = NULL;
  }
};
class NumMatrix {
public:
    NumMatrix(vector<vector<int> > &matrix) {
      this->matrix = matrix;
      if (matrix.empty() || matrix[0].empty())
         root = NULL;
      else {
         root = dfs(matrix, make_pair(0, 0), make_pair(matrix.size()-1, matrix[0].size()-1));
      }
    }

    TreeNode* dfs(vector<vector<int> >& matrix, pair<int, int> leftCorner, pair<int, int> rightCorner) {
      if (leftCorner.first > rightCorner.first || leftCorner.second > rightCorner.second)
        return NULL;
      if (leftCorner == rightCorner)
        return new TreeNode(matrix[leftCorner.first][leftCorner.second], leftCorner, rightCorner);
      int midX = (leftCorner.first + rightCorner.first)/2;
      int midY = (leftCorner.second + rightCorner.second)/2;
      TreeNode* root = new TreeNode(0, leftCorner, rightCorner);
      root->childs[0] = dfs(matrix, leftCorner, make_pair(midX, midY));
      root->childs[1] = dfs(matrix, make_pair(leftCorner.first, midY+1), make_pair(midX, rightCorner.second));
      root->childs[2] = dfs(matrix, make_pair(midX+1, leftCorner.second), make_pair(rightCorner.first, midY));
      root->childs[3] = dfs(matrix, make_pair(midX+1, midY+1), rightCorner);
      for (int i = 0; i < 4; i++)
        if (root->childs[i])
          root->sum += root->childs[i]->sum;
      return root;
    }

    void update(int row, int col, int val) {
      int diff = val - matrix[row][col];
      update(root, row, col, diff);
      matrix[row][col] = val;
    }

    void update(TreeNode* root, int row, int col, int diff) {
      if (root->leftCorner.first <= row && root->rightCorner.first >= row &&
          root->leftCorner.second <= col && root->rightCorner.second >= col) {
        root->sum += diff;
        for (int i=0; i<4; i++)
          if (root->childs[i])
            update(root->childs[i], row, col, diff);
      }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
      if (row1 > row2 || col1 > col2)
        return 0;
      return sumDfs(root, row1, col1, row2, col2);
    }

    int sumDfs(TreeNode* root, int row1, int col1, int row2, int col2) {
      if (overlap(root->rightCorner.first, root->leftCorner.second, root->leftCorner.first, root->rightCorner.second,
                  row2, col1, row1, col2) == false)
        return 0;
      if (row1 <= root->leftCorner.first && row2 >= root->rightCorner.first &&
          col1 <= root->leftCorner.second && col2 >= root->rightCorner.second)
        return root->sum;
      int sum = 0;
      for (int i=0; i<4; i++)
        if (root->childs[i])
          sum += sumDfs(root->childs[i], row1, col1, row2, col2);
      return sum;
    }

    bool overlap(int A, int B, int C, int D, int E, int F, int G, int H) {
      int A1 = A < E? A : E;
      int B1 = B > F? B : F;
      int C1 = C > G? C : G;
      int D1 = D < H? D : H;
      return A1>=C1 && B1<=D1;
    }
private:
    TreeNode* root;
    vector<vector<int> > matrix;
};

class NumMatrix2 {
public:
    NumMatrix2(vector<vector<int> > &matrix) {
      this->matrix = matrix;
      if (matrix.empty() || matrix[0].empty())
         root = NULL;
      else {
         root = dfs(matrix, make_pair(0, 0), make_pair(matrix.size()-1, matrix[0].size()-1));
      }
    }

    TreeNode* dfs(vector<vector<int> >& matrix, pair<int, int> leftCorner, pair<int, int> rightCorner) {
      if (leftCorner.first > rightCorner.first || leftCorner.second > rightCorner.second)
          return NULL;
      if (leftCorner == rightCorner)
          return new TreeNode(matrix[leftCorner.first][leftCorner.second], leftCorner, rightCorner);
      int midX = (leftCorner.first + rightCorner.first)/2;
      int midY = (leftCorner.second + rightCorner.second)/2;
      TreeNode* root = new TreeNode(0, leftCorner, rightCorner);
      root->childs[0] = dfs(matrix, leftCorner, make_pair(midX, midY));
      root->childs[1] = dfs(matrix, make_pair(leftCorner.first, midY+1), make_pair(midX, rightCorner.second));
      root->childs[2] = dfs(matrix, make_pair(midX+1, leftCorner.second), make_pair(rightCorner.first, midY));
      root->childs[3] = dfs(matrix, make_pair(midX+1, midY+1), rightCorner);
      for (int i = 0; i < 4; i++)
        if (root->childs[i])
          root->sum += root->childs[i]->sum;
      return root;
    }

    void update(int row, int col, int val) {
      int diff = val - matrix[row][col];
      update(root, row, col, diff);
      matrix[row][col] = val;
    }

    void update(TreeNode* root, int row, int col, int diff) {
      if (root->leftCorner.first <= row && root->rightCorner.first >= row &&
          root->leftCorner.second <= col && root->rightCorner.second >= col) {
        root->sum += diff;
        for (int i=0; i<4; i++)
          if (root->childs[i])
            update(root->childs[i], row, col, diff);
      }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
      if (row1 > row2 || col1 > col2)
        return 0;
      return sumDfs(root, row1, col1, row2, col2);
    }

    int sumDfs(TreeNode* root, int row1, int col1, int row2, int col2) {
      if (!overlap(root->leftCorner.first, root->leftCorner.second, root->rightCorner.first, root->rightCorner.second, row1, col1, row2, col2))
        return 0;
      if (row1 <= root->leftCorner.first && col1 <= root->leftCorner.second && row2 >= root->rightCorner.first && col2 >= root->rightCorner.second)
          return root->sum;
      int sum = 0;
      for (int i = 0; i < 4; i++)
        if (root->childs[i])
          sum += sumDfs(root->childs[i], row1, col1, row2, col2);
      return sum;
    }

    bool overlap(int A, int B, int C, int D, int E, int F, int G, int H) {
      int A1 = A > E? A : E;
      int B1 = B > F? B : F;
      int C1 = C < G? C : G;
      int D1 = D < H? D : H;
      return A1<=C1 && B1<=D1;
    }
private:
    TreeNode* root;
    vector<vector<int> > matrix;
};
}

int main_range_sum_query_2d_mutable() {
    int data1[] = {2, 4};
    int data2[] = {-3, 5};
    vector<vector<int> > nums;
    nums.push_back(vector<int>(data1, data1+2));
    nums.push_back(vector<int>(data2, data2+2));
    //range_sum_query_2d_mutable::NumMatrix numMatrix(nums);
    range_sum_query_2d_mutable::NumMatrix2 numMatrix2(nums);
    //cout << numMatrix.sumRegion(2,1,4,3) << endl;
    //numMatrix.update(3,2,2);
    //cout << numMatrix.sumRegion(2,1,4,3) << endl;
    numMatrix2.update(0,1,3);
    cout << numMatrix2.sumRegion(0,0,1,1) << endl;
    numMatrix2.update(1,1,-3);
    cout << numMatrix2.sumRegion(0,0,1,1) << endl;
    numMatrix2.update(0,1,1);
    cout << numMatrix2.sumRegion(0,0,1,1) << endl;
}
