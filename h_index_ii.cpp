/**
 * H-index ii
 * Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

Show Hint

solution:
  使用二分查找，每次判断 ans = max(min(citations.size()-mid, citations[mid]), ans).
  time complexity: O(logn)
  space complexity: O(1)
 *
 */

#include <iostream>
#include <vector>
using namespace std;

namespace h_index_ii {
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int ans = 0;
        long long left = 0, right = citations.size()-1;
        while (left <= right) {
            long long mid = (left+right)/2;
            int small = citations.size()-mid < citations[mid]? citations.size()-mid : citations[mid];
            if (ans < small)
                ans = small;
            if (citations.size()-mid >= citations[mid])
                left = mid+1;
            else
                right = mid-1;
        }
        return ans;
    }
};
}

int main_h_index_ii() {
  int data[] = {1,2,3,4,5};
  vector<int> citations(data, data+5);
  cout << (new h_index_ii::Solution())->hIndex(citations);
}


