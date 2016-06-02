/**
 * Minimum Height Trees
 * For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]

solution: 每次把入度为1的点放入dels数组，砍掉dels数组里的元素，并更新入度数组。一直循环到只剩下1或2个点。
time complexity: O(ne), 其中 e 为edges的数目
space complexity: O(n + e)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

namespace minimum_height_tree {
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        vector<int> ans;
        unordered_map<int, vector<int> > graph;
        vector<int> in(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
            in[edges[i].first]++;
            in[edges[i].second]++;
        }
        int total = n;
        while (total > 2) {
            vector<int> dels;
            for (int i=0; i<n; i++) {
                if (in[i] == 1) {
                    dels.push_back(i);
                    in[i] = -1;
                }
            }
            for (int i=0; i<dels.size(); i++) {
                for (int j=0; j<graph[dels[i]].size(); j++) {
                    in[graph[dels[i]][j]]--;
                }
            }
            total -= dels.size();
        }
        for (int i=0; i<n; i++)
            if (in[i] >= 0)
                ans.push_back(i);
        return ans;
    }
};
}

int main_minimum_height_tree() {
  vector<pair<int, int> > edges;
  edges.push_back(make_pair(0,1));
  edges.push_back(make_pair(0,2));
  edges.push_back(make_pair(0,3));
  edges.push_back(make_pair(3,4));
  edges.push_back(make_pair(4,5));
  vector<int> ans = (new minimum_height_tree::Solution())->findMinHeightTrees(6, edges);
}
