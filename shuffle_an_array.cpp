/**
 * Shuffle an array
 *
 * Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();

solution: use a vecotr<int> pos to store the rest positions. pick a random index in [0, pos.size()-1],
put the num to pos[index], then assign pos.back() to pos[index], pos.pop_back().
time complexity: O(n)
space complexity: O(n)
 */

#include <iostream>
#include <vector>
using namespace std;

namespace shuffle_an_array {
class Solution {
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = nums.size();
        vector<int> res(n, 0);
        vector<int> pos(n, 0);
        for (int i = 0; i < n; i++) {
            pos[i] = i;
        }
        for (int i = 0; i < n; i++) {
            int index = rand()%pos.size();
            res[pos[index]] = nums[i];
            pos[index] = pos.back();
            pos.pop_back();
        }
        return res;
    }
private:
    vector<int> nums;
};
}
