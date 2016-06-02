/**
 * Bulls and Cows
 * You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

Credits:
Special thanks to @jeantimex for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

solution: 使用两个hashmap分别记录secret和guess每个字母出现的次数（当对应位置的字母相同时不计入hashmap里）。
time complexity: O(n)
space complexity：O(n)
 */

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

namespace bulls_and_cows {
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> record1;
        unordered_map<char, int> record2;
        int bull = 0, cow = 0;
        for (int i=0; i<secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bull++;
            } else {
                record1[secret[i]]++;
                record2[guess[i]]++;
            }
        }
        for (unordered_map<char, int>::iterator iter = record2.begin(); iter != record2.end(); iter++) {
            char key = iter->first;
            if (record1.find(key) != record1.end()) {
                cow += iter->second < record1[key]? iter->second : record1[key];
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
}

int main_bulls_and_cows() {
  string secret = "1123";
  string guess = "0111";
  cout << (new bulls_and_cows::Solution())->getHint(secret, guess);
}
