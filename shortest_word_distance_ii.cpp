/**
 * shortest word distance ii
 * This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace shortest_word_distance_ii {
class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            record[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        if (record[word1].size() > record[word2].size())
            return shortest(word2, word1);
        int ans = INT_MAX;
        for (int i = 0; i < record[word1].size(); i++) {
            int index = calDis(record[word1][i], record[word2]);
            if (abs(record[word2][index] - record[word1][i]) < ans)
                ans = abs(record[word2][index] - record[word1][i]);
        }
        return ans;
    }

    int calDis(int key, vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        int minimum = INT_MAX;
        int index;
        while (left <= right) {
            int mid = (left + right)/2;
            if (abs(nums[mid] - key) < minimum) {
                minimum = abs(nums[mid] - key);
                index = mid;
            }
            if (nums[mid] > key)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return index;
    }
private:
    unordered_map<string, vector<int> > record;
};
}
