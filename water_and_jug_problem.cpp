/**
 * Water and Jug Problem
 * You are given two jugs with capacities x and y litres. There is an infinite amount of water supply available. You need to determine whether it is possible to measure exactly z litres using these two jugs.

If z liters of water is measurable, you must have z liters of water contained within one or both buckets by the end.

Operations allowed:

Fill any of the jugs completely with water.
Empty any of the jugs.
Pour water from one jug into another till the other jug is completely full or the first jug itself is empty.
Example 1: (From the famous "Die Hard" example)

Input: x = 3, y = 5, z = 4
Output: True
Example 2:

Input: x = 2, y = 6, z = 5
Output: False

solution:
Quote from wiki:

Bézout's identity (also called Bézout's lemma) is a theorem in the elementary theory of numbers: let a and b be nonzero integers and let d be their greatest common divisor. Then there exist integers x and y such that ax+by=d
In addition, the greatest common divisor d is the smallest positive integer that can be written as ax + by
every integer of the form ax + by is a multiple of the greatest common divisor d.
If a or b is negative this means we are emptying a jug of x or y gallons respectively.

Similarly if a or b is positive this means we are filling a jug of x or y gallons respectively.

x = 4, y = 6, z = 8.

GCD(4, 6) = 2

8 is multiple of 2

so this input is valid and we have:

-1 * 4 + 6 * 2 = 8

In this case, there is a solution obtained by filling the 6 gallon jug twice and emptying the 4 gallon jug once. (Solution. Fill the 6 gallon jug and empty 4 gallons to the 4 gallon jug. Empty the 4 gallon jug. Now empty the remaining two gallons from the 6 gallon jug to the 4 gallon jug. Next refill the 6 gallon jug. This gives 8 gallons in the end)
 */

#include <iostream>
using namespace std;

namespace water_and_jug_problem {
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0)
            return true;
        if (x == 0 || y == 0)
            return x == 0? y == z : x == z;
        if (z > x + y)
            return false;
        return z % gcd(x,y) == 0;
    }
    int gcd(int x, int y) {
        if (y == 0)
            return x;
        if (x < y)
            return gcd(y, x);
        return gcd(y, x%y);
    }
};
}
