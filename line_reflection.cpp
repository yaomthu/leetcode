/**
 * Line reflection
 * Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:
Given points = [[1,1],[-1,1]], return true.

Example 2:
Given points = [[1,1],[-1,-1]], return false.

Follow up:
Could you do better than O(n2)?

Show Hint
solution 1: 不使用hashmap和set，首先求出最小的x值和最大的x值，从而得到对称轴x的值。将对称轴左边的元素
和右边的元素分开，分别进行排序和去重，然后对左边的元素从左到右，右边的元素从右到左进行判断。
time complexity: O(nlogn)
space complexity: O(n)

solution 2: 使用unordered_map<int, set<int>>，key为点的y值，value为x值的集合。首先求出对称轴x值
的2倍为xCenter，然后针对hashmap里的每个entry，value集合里的元素按前后指针形式来进行判断，记得在循环里
处理 start == end时候就要break，不然会进入死循环。
time complexity: O(nlogn)
space complexity: O(n)
 *
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <set>
using namespace std;

namespace line_reflection {
class Solution {
public:
    struct LeftCmp {
        bool operator() (const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first < b.first || (a.first == b.first && a.second > b.second))
                return true;
            return false;
        }
    };
    struct RightCmp {
        bool operator() (const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first < b.first || (a.first == b.first && a.second < b.second))
                return true;
            return false;
        }
    };
    bool isReflected(vector<pair<int, int> >& points) {
        if (points.empty())
            return true;
        int xMin = INT_MAX, xMax = INT_MIN;
        for (auto point : points) {
            if (point.first < xMin)
                xMin = point.first;
            if (point.first > xMax)
                xMax = point.first;
        }
        float xCenter = (float)(xMin + xMax)/2;
        vector<pair<int,int> > leftSide, rightSide;
        for (auto point : points) {
            if (abs(point.first - xCenter) > 0.01) {
                if (point.first < xCenter)
                    leftSide.push_back(point);
                else
                    rightSide.push_back(point);
            }
        }
        sort(leftSide.begin(), leftSide.end(), LeftCmp());
        sort(rightSide.begin(), rightSide.end(), RightCmp());
        unifyPoints(leftSide);
        unifyPoints(rightSide);
        if (leftSide.size() != rightSide.size())
            return false;
        if (leftSide.empty())
            return true;
        int i = 0, j = rightSide.size()-1;
        while (i < leftSide.size() && j >= 0) {
            if (abs(xCenter - leftSide[i].first - rightSide[j].first + xCenter) > 0.01 || leftSide[i].second != rightSide[j].second)
                return false;
            i++;
            j--;
        }
        return true;
    }
    void unifyPoints(vector<pair<int,int> >& points) {
        if (points.empty())
            return;
        int index = 0;
        for (int i = 1; i < points.size(); i++) {
            if (!equalPoints(points[i], points[index])) {
                index++;
                points[index] = points[i];
            }
        }
        points.resize(index + 1);
    }
    bool equalPoints(pair<int,int>& a, pair<int,int>& b) {
        return a.first == b.first && a.second == b.second;
    }
};

class Solution_hashmap {
public:
    bool isReflected(vector<pair<int, int> >& points) {
        if (points.empty())
            return true;
        unordered_map<int, set<int> > record;
        int xMin = INT_MAX, xMax = INT_MIN;
        for (auto point : points) {
            if (point.first < xMin)
                xMin = point.first;
            if (point.first > xMax)
                xMax = point.first;
            record[point.second].insert(point.first);
        }
        float xCenter = xMin + xMax;
        for (auto entry : record) {
            for (auto start = entry.second.begin(), end = entry.second.end(); start != end; start++) {
                if (abs(*start + *(--end) - xCenter) > 0.01)
                    return false;
                if (start == end)
                    break;
            }
        }
        return true;
    }
};
}

int main_line_reflection() {
  vector<pair<int,int> > points;
  points.push_back(make_pair(0,0));
  points.push_back(make_pair(1,0));
  if ((new line_reflection::Solution())->isReflected(points)) {
    cout << "true";
  } else {
    cout << "false";
  }
}
