/**
 * H index
 * Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

Show Hint
 *
 *solution: 使用record数组，record[i]记录得分为 i 的篇数，record[n]记录得分大于等于n的篇数。从后往前遍历record
 *solution: 数组直到找到答案。
 *time complexity: O(n)
 *space complexity: O(n)
 *
 */

#include <iostream>
#include <vector>
using namespace std;

namespace h_index {
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int n = citations.size();
        vector<int> record(n+1, 0);
        for (int i=0; i<n; i++) {
            if (citations[i] >= n)
                record[n]++;
            else
                record[citations[i]]++;
        }
        int sum = 0;
        int index = n;
        while (index >= 0 && sum + record[index] < index) {
            sum += record[index];
            index--;
        }
        return index;
    }
};
}

int main_h_index() {
  int data[] = {1,2,3,4,5};
  vector<int> citations(data, data+5);
  cout << (new h_index::Solution())->hIndex(citations);
}
