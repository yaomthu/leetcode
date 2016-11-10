/**
 * mini parser
 *
 * Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Note: You may assume that the string is well-formed:

String is non-empty.
String does not contain white spaces.
String contains only digits 0-9, [, - ,, ].
Example 1:

Given s = "324",

You should return a NestedInteger object which contains a single integer 324.
Example 2:

Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.
Subscribe to see which companies asked this question


solution: use a stack<NestedInteger> to record the current layer. When encounter a '[', just push
NestedInteger() into stack, when encounter number, just add a NestedInteger(num) to current layer,
when encounter a ']', pop the current layer, add the current layer to previous layer (Notes, if there
is only one layer in stack, don't pop). When encounter a ',', just ignore it.
time complexity: O(n)
space complexity: O(n)
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

namespace mini_parser {
class NestedInteger {
   public:
     // Constructor initializes an empty nested list.
     NestedInteger();

     // Constructor initializes a single integer.
     NestedInteger(int value);

     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Set this NestedInteger to hold a single integer.
     void setInteger(int value);

     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
     void add(const NestedInteger &ni);

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        int index = 0;
        if (s[0] != '[') {
            return NestedInteger(atoi(s.c_str()));
        }
        while (index < s.size()) {
            if (s[index] == '[') {
                record.push(NestedInteger());
                index++;
            } else if (s[index] == '-' || (s[index] >= '0' && s[index] <= '9')) {
                bool positive = true;
                if (s[index] == '-') {
                    positive = false;
                    index++;
                }
                int temp = 0;
                while (index < s.size() && s[index] >= '0' && s[index] <= '9') {
                    temp = temp*10 + s[index] - '0';
                    index++;
                }
                record.top().add(NestedInteger(positive? temp : -temp));
            } else {
                if (record.size() > 1 && s[index] == ']') {
                    NestedInteger top = record.top();
                    record.pop();
                    record.top().add(top);
                }
                index++;
            }
        }
        return record.top();
    }
private:
    stack<NestedInteger> record;
};
}
