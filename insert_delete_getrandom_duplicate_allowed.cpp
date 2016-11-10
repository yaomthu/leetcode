/**
 * Insert Delete GetRandom O(1) - Duplicates allowed
 * Design a data structure that supports all following operations in average O(1) time.

Note: Duplicate elements are allowed.
insert(val): Inserts an item val to the collection.
remove(val): Removes an item val from the collection if present.
getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
Example:

// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();
Subscribe to see which companies asked this question
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

namespace insert_delete_getrandom_duplicate_allow {
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res;
        if (cache.find(val) != cache.end()) {
            res = false;
        } else {
            res = true;
        }
        cache[val].push_back(nums.size());
        nums.push_back(make_pair(val, cache[val].size()-1));
        return res;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (cache.find(val) != cache.end()) {
            int index = cache[val].back();
            cache[val].pop_back();
            if (cache[val].empty()) {
                cache.erase(val);
            }
            if (index < nums.size()-1) {
                nums[index] = nums.back();
                cache[nums[index].first][nums[index].second] = index;
            }
            nums.pop_back();
            return true;
        } else {
            return false;
        }
    }

    /** Get a random element from the collection. */
    int getRandom() {
        int index = rand()%nums.size();
        return nums[index].first;
    }
private:
    unordered_map<int, vector<int> > cache;
    vector<pair<int,int> > nums;
};
}
