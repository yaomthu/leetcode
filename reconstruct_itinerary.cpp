/**
 * Reconstruct Itinerary
 * Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.

solution: 此题的思路是从A点出发一直dfs到某个点D（下一跳为空），输出点D并回溯, 每访问一个点的下一跳时，就把该ticket删除。
最终对输出序列进行reverse。
solution 1: 递归解法，思路如上
  time complexity: O(n)
  space complexity: O(n)
solution 2：非递归解法，思路如上，但具体实现需要一个栈stack<string>记录当前需要处理的城市。如果当前城市存在下一跳，
则将下一跳压入栈，并把ticket删除。如果当前城市的下一跳为空，则将当前城市出栈并记录到输出序列里。
  time complexity:O(n)
  space complexity: O(n), n是ticket数量。
则将
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <stack>
using namespace std;

namespace reconstruct_itinerary {
class Solution_recursive {
public:
    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        vector<string> ans;
        if (tickets.empty()) return ans;
        unordered_map<string, multiset<string> > maps;
        for (auto ticket : tickets) {
            maps[ticket.first].insert(ticket.second);
        }
        dfs(ans, maps, "JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
    void dfs(vector<string>& ans, unordered_map<string, multiset<string> >& maps, string cur) {
        while (maps[cur].size()) {
            string next = *(maps[cur].begin());
            maps[cur].erase(maps[cur].begin());
            dfs(ans, maps, next);
        }
        ans.push_back(cur);
    }
};

class Solution_iterative {
public:
    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        vector<string> ans;
        if (tickets.empty())
            return ans;
        unordered_map<string, multiset<string> > maps;
        for (auto ticket : tickets) {
            maps[ticket.first].insert(ticket.second);
        }
        stack<string> record;
        record.push("JFK");
        while (record.size()) {
            string cur = record.top();
            if (maps[cur].size()) {
                record.push(*(maps[cur].begin()));
                maps[cur].erase(maps[cur].begin());
            } else {
                ans.push_back(cur);
                record.pop();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
}

int main_reconstruct_itinerary() {
  vector<pair<string, string> > tickets;
  tickets.push_back(make_pair("MUC", "LHR"));
  tickets.push_back(make_pair("JFK", "MUC"));
  tickets.push_back(make_pair("SFO", "SJC"));
  tickets.push_back(make_pair("LHR", "SFO"));
  vector<string> ans = (new reconstruct_itinerary::Solution_recursive())->findItinerary(tickets);
  for (auto city : ans) {
    cout << city << " ";
  }
}
