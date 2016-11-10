/**
 * longest absolute file path
 * Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.

Note:
The name of a file contains at least a . and an extension.
The name of a directory or sub-directory will not contain a ..
Time complexity required: O(n) where n is the size of the input string.

Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

namespace longest_absolute_file_path {
class Solution {
public:
    int lengthLongestPath(string input) {
        if (input.empty()) {
            return 0;
        }
        vector<pair<string, bool> > tokens;
        splitString(tokens, input);
        stack<int> length;
        int totalLength = 0;
        int ans = 0;
        for (int i = 0; i < tokens.size(); i++) {
            int curLevel = getLevel(tokens[i].first);
            int curLength = tokens[i].first.size() - curLevel;
            while (length.size() > curLevel) {
                totalLength -= (length.top() + 1);
                length.pop();
            }
            totalLength += curLength;
            if (curLevel > 0) {
              totalLength++;
            }
            length.push(curLength);
            if (tokens[i].second == true && totalLength > ans) {
                ans = totalLength;
            }
        }
        return ans;
    }
    void splitString(vector<pair<string, bool> >& tokens, string& input) {
        int start = 0;
        while (start < input.size()) {
            int end = start + 1;
            bool isFile = false;
            while (end < input.size() && input[end] != '\n') {
                if (input[end] == '.') {
                    isFile = true;
                }
                end++;
            }
            tokens.push_back(make_pair(input.substr(start, end - start), isFile));
            start = end + 1;
        }
    }
    int getLevel(string& token) {
        int count = 0;
        while (token[count] == '\t') {
            count++;
        }
        return count;
    }
};
}

int main_longest_absolute_file_path() {
  string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
  cout << (new longest_absolute_file_path::Solution)->lengthLongestPath(input);
}
