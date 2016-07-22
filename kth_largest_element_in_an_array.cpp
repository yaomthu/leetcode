/**
 * Kth largest element in a array
 *Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

solution:使用multiset<int,less<int>> 来模拟小根堆。
time complexity: O(nlogk)
space complexity:O(k)

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

namespace kth_largest_element_in_an_array {
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() < k)
            return 0;
        multiset<int, less<int> > window;
        for (auto num : nums) {
            if (window.size() < k)
                window.insert(num);
            else {
                if (*window.begin() < num) {
                    window.erase(window.begin());
                    window.insert(num);
                }
            }
        }
        return *window.begin();
    }
};

class Solution_heap {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() < k)
            return 0;
        Heap heap(k);
        for (auto num : nums) {
            heap.push(num);
        }
        return heap.top();
    }
    class Heap {
      public:
        Heap(int k): size(k) {}
        void push(int num) {
          cout << "push " << num << endl;
            if (nums.size() < size) {
                nums.push_back(num);
                heapifyDownToUp();
            } else {
                if (nums[0] < num) {
                    nums[0] = num;
                    heapifyUpToDown();
                }
            }

            for (auto num : nums)
              cout << num << " ";
            cout << endl;
        }
        int top() {
           return nums[0];
        }
        void heapifyDownToUp() {
            int p = nums.size()-1;
            while (p > 0) {
                if (nums[p] < nums[p/2]) {
                    swap(nums[p], nums[p/2]);
                    p /= 2;
                }
                else
                    break;
            }
        }
        void heapifyUpToDown() {
            int p = 0;
            while (p < nums.size()) {
                int q = 2*p+1;
                if (q < nums.size()) {
                    if (q+1 < nums.size() && nums[q] > nums[q+1])
                        q++;
                    if (nums[p] > nums[q])
                        swap(nums[p], nums[q]);
                }
                p = q;
            }
        }
      private:
        vector<int> nums;
        int size;
    };
};
}

int main_kth_largest_element_in_an_array() {
  int data[] = {-1,2,0};
  vector<int> nums(data, data+3);
  cout << (new kth_largest_element_in_an_array::Solution_heap())->findKthLargest(nums, 1);
}
