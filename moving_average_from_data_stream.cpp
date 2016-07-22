/**
 * Moving average from data stream
 * Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
 */

#include <iostream>
#include <queue>
using namespace std;

namespace moving_average_from_data_stream {
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        sum = 0;
    }

    double next(int val) {
        sum += val;
        Q.push(val);
        if (Q.size() > size) {
            sum -= Q.front();
            Q.pop();
        }
        return (double)sum / Q.size();
    }
private:
    queue<int> Q;
    int size;
    int sum;
};
}
