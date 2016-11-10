/**
 * meeting rooms ii
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
 */

#include <iostream>
#include <vector>
using namespace std;

namespace meeting_rooms_ii {

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
            bool operator() (const pair<int,int>& a, const pair<int,int>& b) {
                if (a.first < b.first || (a.first == b.first && a.second == 0))
                    return true;
                return false;
            }
    };
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty())
            return 0;
        vector<pair<int,int> > points;
        for (auto interval : intervals) {
            points.push_back(make_pair(interval.start, 1));
            points.push_back(make_pair(interval.end, 0));
        }
        sort(points.begin(), points.end(), Cmp());
        int ans = INT_MIN;
        int sum = 0;
        for (auto point : points) {
            if (point.second == 1)
                sum++;
            else
                sum--;
            if (sum > ans)
                ans = sum;
        }
        return ans;
    }
};
}
