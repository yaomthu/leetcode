/**
 * Strobogrammatic number ii
 *
 */

#include <iostream>
#include <vector>
using namespace std;

namespace strobogrammatic_number_ii {
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> ans;
        if (n <= 0)
            return ans;
        string choice = "01689";
        string mid = n%2 == 0? "": "018";
        dfs(ans, 0, "", choice, mid, n);
        return ans;
    }

    void dfs(vector<string>& ans, int start, string left, string& choice, string& mid, int n) {
        if (start == n/2) {
            string right = convert(left);
            if (n%2 == 1) {
                for (int i = 0; i < mid.size(); i++) {
                    ans.push_back(left + mid[i] + right);
                }
            } else {
                ans.push_back(left + right);
            }
            return;
        }
        int size = left.size();
        for (int i = 0; i < choice.size(); i++) {
            if (start == 0 && i == 0)
                continue;
            left += choice[i];
            dfs(ans, start+1, left, choice, mid, n);
            left.resize(size);
        }
    }

    string convert(string left) {
        if (left.empty())
            return "";
        string right;
        for (int i = left.size()-1; i >= 0; i--) {
            if (left[i] == '0' || left[i] == '1' || left[i] == '8')
                right += left[i];
            else
                right += left[i] == '6'? '9' : '6';
        }
        return right;
    }
};
}

int main_strobogrammatic_number_ii() {
  vector<string> ans = (new strobogrammatic_number_ii::Solution())->findStrobogrammatic(3);
  for (auto num : ans)
    cout << num << endl;
}
