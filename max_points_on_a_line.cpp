/**
 * Max points on a line
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace max_points_on_a_line {
struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.empty())
            return 0;
        int ans = 0;
        unordered_map<float, int> record;
        int duplicate = 0;
        for (int i=0; i<points.size(); i++) {
            record[INT_MAX] = 0;
            duplicate = 1;
            for (int j=0; j<points.size(); j++) {
                if (j == i)
                    continue;
                if (points[j].x == points[i].x) {
                    if (points[j].y == points[i].y)
                        duplicate++;
                    else
                        record[INT_MAX]++;
                } else {
                    float slope = (float)(points[j].y-points[i].y)/(points[j].x-points[i].x);
                    record[slope]++;
                }
            }
            for (auto entry : record) {
                if (entry.second + duplicate > ans)
                    ans = entry.second + duplicate;
            }
            record.clear();
        }
        return ans;
    }
};
}
