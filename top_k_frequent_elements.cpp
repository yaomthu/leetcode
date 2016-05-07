/**
 * Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */

/**
 * Solution:
 * 使用hash table记录每个数字已经该数字的出现次数，然后使用multiset模拟heap来对选出topk。
 * Notes:
 * 由于multiset的元素是node，需要自定义struct cmp。这里必须使用multiset而不是set的原因：我们使用freq作为大小比较，
 * 如果使用set，它将会把不用具有相同freq的不同node看成相同的元素。
 * Space complexity:
 * O(n)
 * Time complexity:
 * O(n + klogk)
 */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

struct node {
    int key;
    int freq;
    node(int key_, int freq_) : key(key_), freq(freq_) {}
};
struct cmp {
    bool operator() (const node& nodea, const node& nodeb) const {
        return nodea.freq < nodeb.freq;
    }
};
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    if(nums.empty())
        return ans;
    unordered_map<int,int> record;
    for(int i=0; i<nums.size(); i++) {
        record[nums[i]]++;
    }
    multiset<node, cmp> minheap;
    for(unordered_map<int,int>::iterator iter = record.begin(); iter != record.end(); iter++) {
        if(minheap.size() < k) {
            minheap.insert(node(iter->first, iter->second));
        } else {
            if(minheap.begin()->freq < iter->second) {
                minheap.erase(minheap.begin());
                minheap.insert(node(iter->first, iter->second));
            }
        }
    }
    for(set<node,cmp>::iterator iter = minheap.begin(); iter != minheap.end(); iter++) {
        ans.push_back(iter->key);
    }
    return ans;
}

int main() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  vector<int> ans = topKFrequent(nums, 2);
  for(int i=0; i<ans.size(); i++) {
    cout << ans[i] << " ";
  }
}

