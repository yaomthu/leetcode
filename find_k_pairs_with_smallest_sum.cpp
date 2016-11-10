/**
 * Find k pairs with smallest sums
 * You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
Credits:
Special thanks to @elmirap and @StefanPochmann for adding this problem and creating all test cases.
 */

#include <iostream>
#include <vector>
using namespace std;

namespace find_k_pairs_with_smallest_sums {
class Solution {
public:
    struct Cmp {
        bool operator() (const pair<int,int>& a, const pair<int,int>& b) {
            return a.first > b.first;
        }
    };

    vector<pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<pair<int,int> > ans;
        if (m == 0 || n == 0) {
            return ans;
        }
        vector<pair<int,int> > heap(n, make_pair(0,0));
        for (int j = 0; j< n; j++) {
            heap[j].first = nums1[0] + nums2[j];
            heap[j].second = j;
        }
        Cmp cmp;
        make_heap(heap.begin(), heap.end(), cmp);
        while (heap.size() && k > 0) {
            auto top = heap[0];
            k--;
            int i = top.second/n;
            int j = top.second%n;
            ans.push_back(make_pair(nums1[i], nums2[j]));
            pop_heap(heap.begin(), heap.end(), cmp);
            heap.pop_back();
            i++;
            if (i < m) {
                heap.push_back(make_pair(nums1[i] + nums2[j], i*n+j));
                push_heap(heap.begin(), heap.end(), cmp);
            }
        }
        return ans;
    }
};
}
