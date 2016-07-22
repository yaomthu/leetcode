/**
 * Basic caculator ii
 * Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.
 */

#include <iostream>
#include <stack>
using namespace std;

namespace basic_caculator_ii {
class Solution {
public:
    int calculate(string s) {
        if (s.empty())
            return 0;
        stack<int> nums;
        stack<char> opers;
        opers.push('#');
        s += "#";
        int index = 0;
        while (index < s.size()) {
            if (s[index] == ' ') {
                index++;
                continue;
            }
            if (s[index] >= '0' && s[index] <= '9') {
                int num = 0;
                while (index < s.size() && s[index] >= '0' && s[index] <= '9') {
                    num = num*10+s[index]-'0';
                    index++;
                }
                nums.push(num);
            } else {
                if (judge(opers.top(), s[index]) == -1) {
                    opers.push(s[index]);
                    index++;
                } else if (judge(opers.top(), s[index]) == 0) {
                    opers.pop();
                    index++;
                } else {
                    char oper = opers.top();
                    opers.pop();
                    int num2 = nums.top();
                    nums.pop();
                    int num1 = nums.top();
                    nums.pop();
                    switch (oper) {
                        case '+' : nums.push(num1+num2);
                            break;
                        case '-': nums.push(num1-num2);
                            break;
                        case '*': nums.push(num1*num2);
                            break;
                        case '/': nums.push(num1/num2);
                            break;
                        default:
                            break;
                    }
                }
            }
        }
        return nums.top();
    }

    int judge(char a, char b) {
        switch (a) {
            case '*':
            case '/': return 1;
            case '+':
            case '-': if (b == '*' || b == '/')
                        return -1;
                      else
                        return 1;
            case '#': if (b == '#')
                        return 0;
                      else
                        return -1;
            default:
                break;
        }
        return 0;
    }
};
}
