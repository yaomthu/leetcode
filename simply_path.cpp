/**
 * Simply path
 * Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

namespace simply_path {
class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) {
            return "/";
        }
        stack<string> record;
        vector<string> tokens;
        splitPath(tokens, path);
        for (auto token : tokens) {
            if (token == ".") {
                continue;
            }
            if (token == ".." ) {
                if (record.size()) {
                    record.pop();
                }
            } else {
                record.push(token);
            }
        }
        string ans;
        while (record.size()) {
            ans = '/' + record.top() + ans;
            record.pop();
        }
        if (ans.empty()) {
            return "/";
        }
        return ans;
    }

    void splitPath(vector<string>& tokens, string& path) {
        int start = 0;
        int end = 1;
        while (end < path.size()) {
            while (end < path.size() && path[end] != '/') {
                end++;
            }
            if (end > start + 1) {
                tokens.push_back(path.substr(start + 1, end - start - 1));
            }
            start = end;
            end++;
        }
    }
};
}
