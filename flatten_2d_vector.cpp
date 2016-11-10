/**
 * Flatten 2d vector
 * Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].

 space complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

namespace flatten_2d_vector {
class Vector2D {
public:
    Vector2D(vector<vector<int> >& vec2d) {
        i = vec2d.begin();
        iEnd = vec2d.end();
        j = 0;
    }

    int next() {
        return (*i)[j++];
    }

    bool hasNext() {
        while (i != iEnd && j == (*i).size()) {
            i++;
            j = 0;
        }
        return i != iEnd;
    }
private:
    vector<vector<int> >::iterator i, iEnd;
    int j;
};
}
