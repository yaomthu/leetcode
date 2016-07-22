/**
 * Evaluate reverse polish notation
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

namespace evaluate_reverse_polish_notation {

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty())
            return 0;
        stack<int> nums;
        for (auto token : tokens) {
            if (token.size()==1 && (token[0]=='+' || token[0]=='-' || token[0]=='*' || token[0]=='/')) {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                switch (token[0]) {
                    case '+': nums.push(num1+num2); break;
                    case '-': nums.push(num1-num2); break;
                    case '*': nums.push(num1*num2); break;
                    case '/': nums.push(num1/num2); break;
                }
            } else {
                int temp = 0;
                bool positive = true;
                int index = 0;
                if (token[index] == '+')
                    index++;
                else if (token[index] == '-') {
                    index++;
                    positive = false;
                }
                while (index < token.size())
                    temp = temp*10 + token[index++]-'0';
                if (!positive)
                    temp = -temp;
                nums.push(temp);
            }
        }
        return nums.top();
    }
};
}
