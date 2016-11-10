/**
 * Insert delelte getrandom O(1)
 * Use hashmap<int,int> whose key is the val, and value is the index of array. vector<int> record the
 * a list of val.
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace insert_delete_getrandom {
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (cache.find(val) != cache.end()) {
            return false;
        } else {
            cache[val] = values.size();
            values.push_back(val);
            return true;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (cache.find(val) == cache.end()) {
            return false;
        } else {
            int index = cache[val];
            cache.erase(val);
            if (index < values.size() - 1) {
                values[index] = values.back();
                cache[values.back()] = index;
            }
            values.pop_back();
            return true;
        }
    }

    /** Get a random element from the set. */
    int getRandom() {
        int index = rand()%values.size();
        return values[index];
    }
private:
    unordered_map<int,int> cache;
    vector<int> values;
};
}


