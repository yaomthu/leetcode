/**
 * Find the celebrity
 * Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n), your function should minimize the number of calls to knows.

Note: There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.

Show Company Tags
Show Tags

solution:
knows(int a, int b) has two outcomes:

true: a knows b, so a is not celebrity, b is the candidate

false: a doesn't know b, so b can't be the celebrity, then a is the candidate.

By calling API n - 1 times, each call we pick one and drop the other one, so in the end,
we have one candidate left. Then we do another pass to check if everyone else know the
candidate, and the candidate knows nobody else. Notes, if the celebrity exists, then it must
be the last candidate.
time complexity: O(n)
space complexity: O(1)
 *
 */

#include <iostream>
using namespace std;

namespace find_celebrity {
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if (n <= 0)
            return -1;
        int candidate = 0;
        for (int i = 1; i < n; i++) {
            if (knows(candidate, i))
                candidate = i;
        }
        for (int i = 0; i < n; i++) {
            if (i == candidate)
                continue;
            if (!knows(i, candidate) || knows(candidate, i))
                return -1;
        }
        return candidate;
    }
};
}
