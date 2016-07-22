/**
 * Word search ii
 * Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.

solution: 对words数组建立Trie树，然后再对矩阵进行dfs搜索。
time complexity: 假设 words 个数为k，矩阵大小为mxn.
buildTrieTree time complexity O(k*avg_length), space complexity: O(26^avg_length)
search time complexity: O(mn*4^(mn)).

 */

#include <iostream>
#include <vector>
using namespace std;

namespace word_search_ii {
class Solution {
    class TrieNode {
        public:
            TrieNode() : isWord(false), next(26, NULL) {}
            bool getIsWord() {
                return isWord;
            }
            void setIsWord(bool type) {
                isWord = type;
            }
            TrieNode* getNext(char ch) {
                return next[ch-'a'];
            }
            void setNext(char ch) {
                next[ch-'a'] = new TrieNode();
            }
        private:
            bool isWord;
            vector<TrieNode*> next;
    };

public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> ans;
        if (board.empty() || board[0].empty() || words.empty())
            return ans;
        TrieNode* root = buildTrieTree(words);
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (root->getNext(board[i][j]) != NULL) {
                    dfs(ans, board, i, j, root->getNext(board[i][j]), "");
                }
            }
        }
        destroyTrieTree(root);
        return ans;
    }
    TrieNode* buildTrieTree(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string word : words) {
            int index = 0;
            TrieNode* cur = root;
            while (index < word.size() && cur->getNext(word[index]) != NULL) {
                cur = cur->getNext(word[index]);
                index++;
            }
            while (index < word.size()) {
                cur->setNext(word[index]);
                cur = cur->getNext(word[index]);
                index++;
            }
            cur->setIsWord(true);
        }
        return root;
    }
    void dfs(vector<string>& ans, vector<vector<char> >& board, int x, int y, TrieNode* root, string record) {
        record += board[x][y];
        if (root->getIsWord()) {
            ans.push_back(record);
            root->setIsWord(false);
        }
        char cache = board[x][y];
        board[x][y] = '#';
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int m = board.size(), n = board[0].size();
        for (int i=0; i<4; i++) {
            int nextx = x + dx[i];
            int nexty = y + dy[i];
            if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && board[nextx][nexty] != '#' && root->getNext(board[nextx][nexty])) {
                dfs(ans, board, nextx, nexty, root->getNext(board[nextx][nexty]), record);
            }
        }
        board[x][y] = cache;
    }
    void destroyTrieTree(TrieNode* root) {
        if (!root)
            return;
        for (int i=0; i<26; i++) {
            destroyTrieTree(root->getNext('a' + i));
        }
        delete root;
    }
};
}

