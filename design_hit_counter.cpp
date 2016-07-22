/**
 * Design hit counter
 * Design a hit counter which counts the number of hits received in the past 5 minutes.

Each function accepts a timestamp parameter (in seconds granularity) and you may assume that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

Example:
HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301);

Follow up:
What if the number of hits per second could be very large? Does your design scale?

solution: 使用queue<pair<int,int>>来记录，队列每个元素的first是timestamp，second是该时刻hit数。
queue最多包含300个元素。
time complexity: O(1)
space complexity: O(1)

 */
#include <iostream>
#include <queue>
using namespace std;

namespace design_hit_counter {
class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        total = 0;
    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        total++;
        if (record.size() && record.back().first == timestamp)
            record.back().second++;
        else
            record.push(make_pair(timestamp, 1));
        while (record.size() > 300) {
            total -= record.front().second;
            record.pop();
        }
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (record.size() && record.front().first <= timestamp - 300) {
            total -= record.front().second;
            record.pop();
        }
        return total;
    }
private:
    queue<pair<int,int> > record;
    int total;
};
}
