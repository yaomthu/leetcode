/*
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

Space complexity: O(1)
Time complexity: O(n)
*/

#include<iostream>
using namespace std;

namespace reverse_string {
class Solution {
public:
    string reverseString(string s) {
        if (s.empty()) {
            return s;
        }
        int left = 0, right = s.size()-1;
        while(left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
        return s;
    }
};
}

int main_reverse_string() {
  string s = "helloworld";
  cout << (new reverse_string::Solution())->reverseString(s) << endl;
}
