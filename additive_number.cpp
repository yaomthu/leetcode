/**
 * Additive number
 * Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers?

Credits:
Special thanks to @jeantimex for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
solution: 穷举 num1 和 num2 的长度，首先判断num1 和 num2 是否符合，然后使用dfs开始判断后续字符串是否符合。
time complexity: O(n^2)
space complexity:
 */

#include <iostream>
#include <string>
using namespace std;

namespace additive_number {
class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num.size() < 3)
            return false;
        for (int i=1; i<=num.size()/2; i++) {
            for (int j=1; j<=(num.size()-i)/2; j++) {
                string num1 = num.substr(0, i);
                string num2 = num.substr(i, j);
                if (valid(num1) && valid(num2) && dfs(num, i+j, num1, num2))
                    return true;
            }
        }
        return false;
    }
    bool valid(string num) {
        if (num.size()>1 && num[0]=='0')
            return false;
        return true;
    }
    bool dfs(string& num, int start, string num1, string num2) {
        if (start == num.size())
            return true;
        string sum = add(num1, num2);
        if (sum.size() > num.size()-start)
            return false;
        string num3 = num.substr(start, sum.size());
        if (sum != num3)
            return false;
        return dfs(num, start+sum.size(), num2, num3);
    }
    string add(string num1, string num2) {
        if (num1.size() < num2.size())
            return add(num2, num1);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans;
        int carry = 0;
        int i = 0, j = 0;
        while (i<num1.size() && j<num2.size()) {
            int temp = num1[i]-'0'+num2[j]-'0'+carry;
            if (temp >= 10) {
                carry = 1;
                temp -= 10;
            } else {
                carry = 0;
            }
            char ch = temp+'0';
            ans += ch;
            i++;
            j++;
        }
        while (i < num1.size()) {
            int temp = num1[i]-'0'+carry;
            if (temp >= 10) {
                carry = 1;
                temp -= 10;
            } else {
                carry = 0;
            }
            char ch = temp+'0';
            ans += ch;
            i++;
        }
        if (carry > 0)
            ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
}

int main_additive_number() {
  if ((new additive_number::Solution())->isAdditiveNumber("198019823962"))
    cout << "true";
  else
    cout << "false";
}
