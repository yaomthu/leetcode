/**
 * Largest number
 * Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
solution: 快速排序变种，string a 和 string b的比较函数为 return a+b > b+a
cornet case：所有元素为都0，记得返回"0"
 */

#include <iostream>
#include <vector>
using namespace std;

namespace largest_number {
class Solution {
public:
    struct cmp {
        bool operator() (const string& a, const string& b) const {
            return a+b > b+a;
        }
    };
    string largestNumber(vector<int>& nums) {
        if (nums.empty())
            return "";
        vector<string> words;
        for (auto num : nums)
            words.push_back(to_string(num));
        sort(words.begin(), words.end(), cmp());
        string ans;
        int index = 0;
        while (index < words.size() && words[index] == "0")
            index++;
        while (index < words.size())
            ans += words[index++];
        if (ans.empty())
            return "0";
        return ans;
    }
};
}
