/**
 * Repeated DNA sequences
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
solution: 使用一个int来记录十个字母所表示的数，其中A=‘00’, B='01', C='10', D='11'
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

namespace repeated_dna_sequences {
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if (s.size() < 10)
            return ans;
        unordered_map<int, int> record;
        int subString = 0;
        for (int i = 0; i < s.size(); i++) {
            subString <<= 2;
            switch (s[i]) {
                case 'C': subString |= 1; break;
                case 'G': subString |= 2; break;
                case 'T': subString |= 3; break;
                default: break;
            }
            subString &= 0xfffff;
            if (i >= 9) {
                record[subString]++;
            }
        }
        for (auto iter = record.begin(); iter != record.end(); iter++)
            if (iter->second > 1)
                ans.push_back(deserialization(iter->first));
        return ans;
    }
    string deserialization(int subString) {
        string ans;
        for (int i = 1; i<= 10; i++) {
            switch (subString & 3) {
                case 0: ans = "A" + ans; break;
                case 1: ans = "C" + ans; break;
                case 2: ans = "G" + ans; break;
                case 3: ans = "T" + ans; break;
            }
            subString >>= 2;
        }
        return ans;
    }
};
}
