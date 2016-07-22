/**
 * Add and search word - data structure design
 * Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

solution: build trie tree.
 */

#include <iostream>
#include <vector>
using namespace std;

namespace add_and_search_word {
class WordDictionary {
public:
    class TrieNode {
        public:
            TrieNode(): leaf(false), next(26, NULL) {}
            TrieNode* getNext(char ch) {
                return next[ch-'a'];
            }
            void setNext(char ch) {
                next[ch-'a'] = new TrieNode();
            }
            bool isLeaf() {
                return leaf;
            }
            void setLeaf() {
                leaf = true;
            }
        private:
            vector<TrieNode*> next;
            bool leaf;
    };
    WordDictionary() {
        root = new TrieNode();
    }

    ~WordDictionary() {
        destroyTrieTree(root);
    }

    void destroyTrieTree(TrieNode* root) {
        if (!root)
            return;
        for (char ch='a'; ch <= 'z'; ch++)
            destroyTrieTree(root->getNext(ch));
        delete root;
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        int index = 0;
        TrieNode* cur = root;
        while (index < word.size() && cur->getNext(word[index]))
            cur = cur->getNext(word[index++]);
        while (index < word.size()) {
            cur->setNext(word[index]);
            cur = cur->getNext(word[index]);
            index++;
        }
        cur->setLeaf();
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return dfs(word, 0, root);
    }
    bool dfs(string& word, int index, TrieNode* cur) {
        if (index == word.size()) {
            if (cur->isLeaf())
                return true;
            else
                return false;
        }
        if (word[index] != '.') {
            if (cur->getNext(word[index]) == NULL)
                return false;
            return dfs(word, index+1, cur->getNext(word[index]));
        } else {
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (cur->getNext(ch) && dfs(word, index+1, cur->getNext(ch)))
                    return true;
            }
            return false;
        }
    }
    private:
        TrieNode* root;
};
}
