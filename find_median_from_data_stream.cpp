/**
 * Find median from data stream
 * Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3)
findMedian() -> 2
Credits:
Special thanks to @Louis1992 for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

solution: 使用两个堆，一个大根堆存较小的数，一个小根堆存较大的数。两个堆所存元素个数差别最多不超过1个。
time complexity: addNum O(klogk), findMedian O(1)
space complexity: O(n)
 */

#include <iostream>
#include <set>
using namespace std;

namespace find_median_from_data_stream {
class MedianFinder {
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (bigHeap.empty() || num <= *bigHeap.begin())
            bigHeap.insert(num);
        else
            smallHeap.insert(num);
        if (bigHeap.size() > smallHeap.size() && bigHeap.size()-smallHeap.size() > 1) {
            smallHeap.insert(*bigHeap.begin());
            bigHeap.erase(bigHeap.begin());
        } else if (smallHeap.size() > bigHeap.size() && smallHeap.size()-bigHeap.size() > 1) {
            bigHeap.insert(*smallHeap.begin());
            smallHeap.erase(smallHeap.begin());
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (bigHeap.size() == smallHeap.size())
            return ((double)*bigHeap.begin() + (double)*smallHeap.begin())/2;
        else
            return bigHeap.size() > smallHeap.size()? *bigHeap.begin() : *smallHeap.begin();
    }
private:
    multiset<int, greater<int> > bigHeap;
    multiset<int, less<int> > smallHeap;
};
}

int main_find_median_from_data_stream() {
  using namespace find_median_from_data_stream;
  MedianFinder solution;
  solution.addNum(-1);
  cout << solution.findMedian() << endl;
  solution.addNum(-2);
  cout << solution.findMedian() << endl;
  solution.addNum(-3);
  cout << solution.findMedian() << endl;
  solution.addNum(-5);
  cout << solution.findMedian() << endl;
}
