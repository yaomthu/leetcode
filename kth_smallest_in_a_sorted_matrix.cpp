/**
 * Kth Smallest Element in a Sorted Matrix  QuestionEditorial Solution  My Submissions
Total Accepted: 1542
Total Submissions: 3747
Difficulty: Medium
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.
Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.

Subscribe to see which companies asked this question
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

namespace kth_smallest_in_sorted_matrix {
class Solution {
public:
    struct Cmp {
        bool operator() (const pair<int,int>& elem1, const pair<int,int>& elem2) {
            return elem1.first >= elem2.first;
        }
    };
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        int n = matrix.size();
        Cmp cmp;
        vector<pair<int,int> > record;
        record.push_back(make_pair(matrix[0][0], 0));
        unordered_set<int> visited;
        visited.insert(0);
        while (k) {
            k--;
            auto cur = record.front();
            if (k == 0) {
                return cur.first;
            }
            pop_heap(record.begin(), record.end(), cmp);
            record.pop_back();
            int x = cur.second / n;
            int y = cur.second % n;
            if (x < n - 1 && visited.find((x+1)*n+y) == visited.end()) {
                record.push_back(make_pair(matrix[x+1][y], (x+1)*n+y));
                push_heap(record.begin(), record.end(), cmp);
                visited.insert((x+1)*n+y);
            }
            if (y < n - 1 && visited.find(x*n+y+1) == visited.end()) {
                record.push_back(make_pair(matrix[x][y+1], x*n+y+1));
                push_heap(record.begin(), record.end(), cmp);
                visited.insert(x*n+y+1);
            }
        }
        return 0;
    }
};

class Solution2 {
public:
    struct Cmp {
        bool operator() (const pair<int,int>& elem1, const pair<int,int>& elem2) {
            return elem1.first >= elem2.first;
        }
    };
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        int n = matrix.size();
        Cmp cmp;
        vector<pair<int,int> > record;
        for (int j = 0; j < n; j++) {
            record.push_back(make_pair(matrix[0][j], j));
        }
        make_heap(record.begin(), record.end(), cmp);
        while (k) {
            k--;
            auto cur = record.front();
            if (k == 0) {
                return cur.first;
            }
            pop_heap(record.begin(), record.end(), cmp);
            record.pop_back();
            int j = cur.second;
            if (j + n < n * n) {
                j += n;
                record.push_back(make_pair(matrix[j/n][j%n], j));
                push_heap(record.begin(), record.end(), cmp);
            }
        }
        return 0;
    }
};
}
