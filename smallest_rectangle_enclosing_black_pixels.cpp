/**
 * Smallest rectangle enclosing black pixels
 * An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

For example, given the following image:

[
  "0010",
  "0110",
  "0100"
]
and x = 0, y = 2,
Return 6.
solution : bfs method
time complexity: O(m*n)
space complexity: O(m*n)

solution2: binary search
time complexity: O(mlogn + nlogm)
space complexity: O(1)
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

namespace smallest_rectangle_enclosing_black_pixels {
class Solution {
public:
    int minArea(vector<vector<char> >& image, int x, int y) {
        if (image.empty() || image[0].empty())
            return 0;
        int xmin = INT_MAX, ymin = INT_MAX, xmax = INT_MIN, ymax = INT_MIN;
        int m = image.size(), n = image[0].size();
        queue<pair<int,int> > Q;
        Q.push(make_pair(x, y));
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        while (Q.size()) {
            auto cur = Q.front();
            Q.pop();
            if (cur.first < xmin)
                xmin = cur.first;
            if (cur.second < ymin)
                ymin = cur.second;
            if (cur.first > xmax)
                xmax = cur.first;
            if (cur.second > ymax)
                ymax = cur.second;
            for (int i = 0; i < 4; i++) {
                int nextx = cur.first + dx[i];
                int nexty = cur.second + dy[i];
                if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && image[nextx][nexty] == '1') {
                    image[nextx][nexty] = '2';
                    Q.push(make_pair(nextx, nexty));
                }
            }
        }
        return (xmax - xmin + 1) * (ymax - ymin +1);
    }
};

class Solution2 {
public:
    int minArea(vector<vector<char> >& image, int x, int y) {
        if (image.empty() || image[0].empty())
            return 0;
        int m = image.size(), n = image[0].size();
        int l = binarySearch(true, false, 0, y, 0, m-1, image);
        int r = binarySearch(true, true, y, n-1, 0, m-1, image);
        int u = binarySearch(false, false, 0, n-1, 0, x, image);
        int d = binarySearch(false, true, 0, n-1, x, m-1, image);
        return (r-l+1)*(d-u+1);
    }
    int binarySearch(bool horization, bool increase, int left, int right, int top, int bottom, vector<vector<char> >& image) {
        int m = image.size(), n = image[0].size();
        if (horization) {
            int ans;
            while (left <= right) {
                int mid = (left + right)/2;
                int index = top;
                while (index <= bottom && image[index][mid] == '0')
                    index++;
                if (index <= bottom) {
                    ans = mid;
                    if (increase)
                        left = mid + 1;
                    else
                        right = mid - 1;
                } else {
                    if (increase)
                        right = mid - 1;
                    else
                        left = mid + 1;
                }
            }
            return ans;
        } else {
            int ans;
            while (top <= bottom) {
                int mid = (top + bottom)/2;
                int index = left;
                while (index <= right && image[mid][index] == '0')
                    index++;
                if (index <= right) {
                    ans = mid;
                    if (increase)
                        top = mid + 1;
                    else
                        bottom = mid - 1;
                } else {
                    if (increase)
                        bottom = mid - 1;
                    else
                        top = mid + 1;
                }
            }
            return ans;
        }
    }
};
}
