/**
 * Data stream as disjoint intervals
 * Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.

For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
Follow up:
What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?
 Solution 1: 使用vector，addNum复杂度为O(n), getIntervals复杂度为O(1).
 solution 2：使用set，addNum复杂度为O(logn), getIntervals复杂度为O(n)

 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;
namespace data_stream_as_disjoint_intervals {
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
public:
    struct Cmp {
        bool operator() (const Interval& a, const Interval& b) const {
            return a.start < b.start;
        }
    };
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        auto iter = lower_bound(record.begin(), record.end(), Interval(val, val), Cmp());
        int start = val, end = val;
        if (iter != record.begin() && (iter-1)->end + 1 >= val)
            iter--;
        while (iter != record.end() && val >= iter->start-1 && val <= iter->end+1) {
            start = start < iter->start? start : iter->start;
            end = end > iter->end? end : iter->end;
            iter = record.erase(iter);
        }
        record.insert(iter, Interval(start, end));
    }

    vector<Interval> getIntervals() {
        return record;
    }
private:
    vector<Interval> record;
};

class SummaryRanges_set {
public:
    struct Cmp {
        bool operator() (const Interval& a, const Interval& b) const {
            return a.start < b.start;
        }
    };
    /** Initialize your data structure here. */
    SummaryRanges_set() {

    }

    void addNum(int val) {
        auto iter = record.lower_bound(Interval(val, val));
        int start = val, end = val;
        if (iter != record.begin() && prev(iter)->end + 1 >= val)
            iter--;
        while (iter != record.end() && val >= iter->start - 1 && val <= iter->end+1) {
            start = start < iter->start? start : iter->start;
            end = end > iter->end? end : iter->end;
            iter = record.erase(iter);
        }
        record.insert(iter, Interval(start, end));
    }

    vector<Interval> getIntervals() {
        vector<Interval> ans;
        for (auto interval : record)
            ans.push_back(interval);
        return ans;
    }
private:
    set<Interval, Cmp> record;
};
}

int main_data_stream_as_disjoint_intervals() {
  data_stream_as_disjoint_intervals::SummaryRanges range;
  range.addNum(1);
  range.addNum(3);
  range.addNum(7);
  range.addNum(2);
  vector<data_stream_as_disjoint_intervals::Interval> ans = range.getIntervals();
  for (auto interval : ans) {
    cout << "(" << interval.start << "," << interval.end << ")";
  }
}
