/**
 * Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Space complexity: O(1)
Time complexity: O(n)
 */

#include <iostream>
using namespace std;

namespace reverse_vowels_of_a_string {
class Solution {
public:
    string reverseVowels(string s) {
        if (s.empty()) {
            return s;
        }
        int left = 0, right = s.size()-1;
        while(left < right) {
            while(left < right && isVowel(s[left]) == false) {
                left++;
            }
            while(right > left && isVowel(s[right]) == false) {
                right--;
            }
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U') {
            return true;
        } else {
            return false;
        }
    }
};
}

int main_reverse_vowels_of_a_string() {
  string s = "hello";
  cout << (new reverse_vowels_of_a_string::Solution())->reverseVowels(s) << endl;
}
