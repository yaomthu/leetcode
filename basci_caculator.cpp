/*
 * Basic caculator
 * Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
 *
 */

#include <iostream>
#include <stack>
using namespace std;

namespace basic_caculator {
class Solution {
public:
    int calculate(string s) {
        if (s.empty())
            return 0;
        s += "#";
        stack<int> nums;
        stack<char> opers;
        opers.push('#');
        int index = 0;
        while (index < s.size()) {
            if (s[index] == ' ') {
                index ++;
                continue;
            }
            if (s[index] >= '0' && s[index] <= '9') {
                int num = 0;
                while (index < s.size() && s[index] >= '0' && s[index] <= '9') {
                    num = num*10 + s[index]-'0';
                    index++;
                }
                nums.push(num);
            } else {
                if (judge(opers.top(), s[index]) == 0) {
                    opers.pop();
                    index++;
                } else if (judge(opers.top(), s[index]) < 0) {
                    opers.push(s[index]);
                    index++;
                } else {
                    char oper = opers.top();
                    opers.pop();
                    int num2 = nums.top();
                    nums.pop();
                    int num1 = nums.top();
                    nums.pop();
                    switch (oper) {
                        case '+': nums.push(num1+num2); break;
                        case '-': nums.push(num1-num2); break;
                    }
                }
            }
        }
        return nums.top();
    }
    int judge(char a, char b) {
        switch (a) {
            case '+':
            case '-': if (b=='(')
                        return -1;
                      else
                        return 1;
            case '(': if (b==')')
                        return 0;
                      else
                        return -1;
            case '#': if (b=='#')
                        return 0;
                      else
                        return -1;
        }
        return 0;
    }
};
}
