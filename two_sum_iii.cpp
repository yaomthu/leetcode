/**
 * Two sum iii
 * Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
 */

#include <iostream>
#include <unordered_map>
using namespace std;

namespace two_sum_iii {
class TwoSum {
public:

    // Add the number to an internal data structure.
  void add(int number) {
      record[number]++;
  }

    // Find if there exists any pair of numbers which sum is equal to the value.
  bool find(int value) {
      for (auto iter = record.begin(); iter != record.end(); iter++) {
          int rest = value - iter->first;
          if (rest == iter->first) {
              if (iter->second > 1)
                  return true;
          } else {
              if (record.count(rest))
                  return true;
          }
      }
      return false;
  }
private:
    unordered_map<int, int> record;
};
}
