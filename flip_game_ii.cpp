/**
 * Flip game ii
 * You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity.

solution: dfs + record temp result
time complexity: If we don't use hashmap to record the result, time complexity is O(2^n)
T(N) = T(N-2) + T(N-3) + [T(2) + T(N-4)] + [T(3) + T(N-5)] + ...
    [T(N-5) + T(3)] + [T(N-4) + T(2)] + T(N-3) + T(N-2)
   = 2 * sum(T[i])  (i = 3..N-2)
==> T(N) = 2^N.
 */

#include <iostream>
#include <unordered_map>
using namespace std;

namespace flip_game_ii {
class Solution {
public:
    bool canWin(string s) {
        if (s.size() < 2)
            return false;
        unordered_map<string, bool> record;
        if (dfs(s, record))
            return true;
        return false;
    }
    bool dfs(string& s, unordered_map<string,bool>& record) {
        cout << s << endl;
        if (record.find(s) != record.end())
            return record[s];
        for (int i = 0; i < s.size()-1; i++) {
            if (s[i] == '+' && s[i+1] == '+') {
                s[i] = '-';
                s[i+1] = '-';
                if (dfs(s, record) == false) {
                    record[s] = false;
                    s[i] = '+';
                    s[i+1] = '+';
                    return true;
                } else {
                    record[s] = true;
                    s[i] = '+';
                    s[i+1] = '+';
                }
            }
        }
        return false;
    }
};
}

int main_flip_game_ii() {
  string s = "++++";
  flip_game_ii::Solution solution;
  if (solution.canWin(s))
    cout << "true";
  else
    cout << "false";
}
