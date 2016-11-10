/**
 * Design phone dictionary
 * Design a Phone Directory which supports the following operations:

get: Provide a number which is not assigned to anyone.
check: Check if a number is available or not.
release: Recycle or release a number.
Example:

// Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
PhoneDirectory directory = new PhoneDirectory(3);

// It can return any available phone number. Here we assume it returns 0.
directory.get();

// Assume it returns 1.
directory.get();

// The number 2 is available, so return true.
directory.check(2);

// It returns 2, the only number that is left.
directory.get();

// The number 2 is no longer available, so return false.
directory.check(2);

// Release number 2 back to the pool.
directory.release(2);

// Number 2 is available again, return true.
directory.check(2);
solution : vector<bool> state stores the state of all number, queue<int> stores the recycle number. Be careful
of function release(number), when the number is not used, don't push it to queue.
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace design_phone_dictionay {
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for (int i = 0 ; i < maxNumbers; i++) {
            state.push_back(true);
        }
        index = 0;
        this->maxNumbers = maxNumbers;
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        int ans;
        if (index < maxNumbers) {
            state[index] = false;
            ans = index++;
            return ans;
        } else if (recycle.empty()) {
            return -1;
        } else {
            int number = recycle.front();
            recycle.pop();
            state[number] = false;
            return number;
        }
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        return state[number];
    }

    /** Recycle or release a number. */
    void release(int number) {
        if (state[number] == false) {
            state[number] = true;
            recycle.push(number);
        }
    }
private:
    vector<bool> state;
    queue<int> recycle;
    int index;
    int maxNumbers;
};
}
