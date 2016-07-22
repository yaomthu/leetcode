/**
 * sparse matrix multiplication
 * Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
Show Company Tags
Show Tags

solution: 不能用最原始方法进行计算，否则在有很多0的情况下会超时。三层循环的设置非常巧妙的减少了0的操作。

solution2: 使用unordered_map<int, unordered_map<int,int>>来表示一个稀疏矩阵。matrixA以行为key，
matrixB以列为key
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace sparse_matrix_multiplication {
class Solution {
public:
    vector<vector<int> > multiply(vector<vector<int> >& A, vector<vector<int> >& B) {
        int mA = A.size(), nA = A[0].size(), nB = B[0].size();
        vector<vector<int> > C(mA, vector<int>(nB, 0));
        for (int i = 0; i < mA; i++) {
            for (int k = 0; k < nA; k++) {
                if (A[i][k] != 0) {
                    for (int j = 0; j < nB; j++) {
                        if (B[k][j] != 0)
                            C[i][j] += A[i][k]*B[k][j];
                    }
                }
            }
        }
        return C;
    }
};

class Solution2 {
public:
    vector<vector<int> > multiply(vector<vector<int> >& A, vector<vector<int> >& B) {
        int mA = A.size(), nA = A[0].size(), mB = B.size(), nB = B[0].size();
        vector<vector<int> > C(mA, vector<int>(nB, 0));
        unordered_map<int, unordered_map<int,int> > matrixA;
        unordered_map<int, unordered_map<int,int> > matrixB;
        for (int i = 0; i < mA; i++) {
            for (int j = 0; j < nA; j++) {
                if (A[i][j] != 0) {
                    if (matrixA.find(i) == matrixA.end())
                        matrixA[i] = unordered_map<int,int>();
                    matrixA[i][j] = A[i][j];
                }
            }
        }
        for (int i = 0; i < mB; i++) {
            for (int j = 0; j < nB; j++) {
                if (B[i][j] != 0) {
                    if (matrixB.find(j) == matrixB.end())
                        matrixB[j] = unordered_map<int,int>();
                    matrixB[j][i] = B[i][j];
                }
            }
        }
        for (auto rowA = matrixA.begin(); rowA != matrixA.end(); rowA++) {
            for (auto colB = matrixB.begin(); colB != matrixB.end(); colB++) {
                int i = rowA->first;
                int j = colB->first;
                C[i][j] += calculate(rowA->second, colB->second);
            }
        }
        return C;
    }
    int calculate(unordered_map<int,int>& rowA, unordered_map<int,int>& colB) {
        int res = 0;
        for (auto aiter = rowA.begin(); aiter != rowA.end(); aiter++) {
            if (colB.find(aiter->first) != colB.end())
                res += aiter->second * colB[aiter->first];
        }
        return res;
    }
};
}
