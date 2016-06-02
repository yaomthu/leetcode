/**
 * Expression add operators
 * Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples:
"123", 6 -> ["1+2+3", "1*2*3"]
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []

solution: dfs解法，需要及时记录前一个元素和前一个符号。
void dfs(vector<string>& ans, string& num, int start, int target, long long sum, string record, int prenum, char preop)
 time complexity: O(3^n)
 space complexity: O(n).
 */

#include <iostream>
#include <vector>
using namespace std;

namespace expresssion_add_operartors {
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (num.empty())
            return ans;
        dfs(ans, num, 0, target, 0, "", 0, '#');
        return ans;
    }
    void dfs(vector<string>& ans, string& num, int start, int target, long long sum, string record, int prenum, char preop) {
        if (start == num.size()) {
            if (target == sum)
                ans.push_back(record);
            return;
        }
        for (int i = start; i<num.size(); i++) {
            string temp = num.substr(start, i-start+1);
            if (temp.size()>1 && temp[0] == '0')
                break;
            long long curNum = atol(temp.c_str());
            if (record.empty())
                dfs(ans, num, i+1, target, curNum, record+temp, curNum, '#');
            else {
                dfs(ans, num, i+1, target, sum+curNum, record+"+"+temp, curNum, '+');
                dfs(ans, num, i+1, target, sum-curNum, record+"-"+temp, curNum, '-');
                if (preop == '+')
                    dfs(ans, num, i+1, target, sum-prenum+prenum*curNum, record+"*"+temp, prenum*curNum, '+');
                else if (preop == '-')
                    dfs(ans, num, i+1, target, sum+prenum-prenum*curNum, record+"*"+temp, prenum*curNum, '-');
                else
                    dfs(ans, num, i+1, target, prenum*curNum, record+"*"+temp, prenum*curNum, '#');
            }
        }
    }
};
}

int main_expression_add_operators() {
  string num = "123";
  vector<string> ans = (new expresssion_add_operartors::Solution())->addOperators(num, 6);
  for (auto ss : ans)
    cout << ss << endl;
}

