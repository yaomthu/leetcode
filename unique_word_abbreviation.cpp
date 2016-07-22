/**
 * Unique word abbreviation
 * An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example:
Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

namespace unique_word_abbreviation {
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto word : dictionary) {
            string abbr = abbreviate(word);
            record[abbr].insert(word);
        }
    }

    string abbreviate(string word) {
        if (word.size() < 3)
            return word;
        string ans;
        ans += word[0];
        ans += to_string(word.size() - 2);
        ans += word.back();
        return ans;
    }

    bool isUnique(string word) {
        string abbr = abbreviate(word);
        if (record.find(abbr) == record.end())
            return true;
        if (record[abbr].size() < 2 && *(record[abbr].begin()) == word)
            return true;
        return false;
    }
private:
    unordered_map<string, set<string> > record;
};

class ValidWordAbbr2 {
public:
    ValidWordAbbr2(vector<string> &dictionary) {
        for (auto word : dictionary) {
            string abbr = abbreviate(word);
            record[abbr]++;
            record['#' + word]++;
        }
    }

    string abbreviate(string word) {
        if (word.size() < 3)
            return word;
        string ans;
        ans += word[0];
        ans += to_string(word.size() - 2);
        ans += word.back();
        return ans;
    }

    bool isUnique(string word) {
        return record['#' + word] == record[abbreviate(word)];
    }
private:
    unordered_map<string, int> record;
};
}
