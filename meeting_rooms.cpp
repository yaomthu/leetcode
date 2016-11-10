/**
 * Meeting rooms
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.
 */

#include <iostream>
#include <vector>
using namespace std;

namespace meeting_rooms {
struct Interval {
   int start;
   int end;
   Interval() : start(0), end(0) {}
   Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    class Cmp {
        public:
            bool operator() (const Interval& a, const Interval& b) {
                return a.start < b.start;
            }
    };
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty())
            return true;
        sort(intervals.begin(), intervals.end(), Cmp());
        for (int i = 0; i < intervals.size()-1; i++) {
            if (intervals[i].end > intervals[i+1].start)
                return false;
        }
        return true;
    }
};
}
