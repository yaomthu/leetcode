/**
 * Number of connected components
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

solution: 使用union-find算法即可，记得初始化parents数组。
 */

#include <iostream>
#include <vector>
using namespace std;

namespace number_of_connected_components {
class Solution {
public:
    int countComponents(int n, vector<pair<int, int> >& edges) {
        if (edges.empty())
            return n;
        vector<int> parents;
        for (int i = 0; i < n; i++)
            parents.push_back(i);
        int ans = n;
        for (auto edge : edges) {
            int v = edge.first, w = edge.second;
            while (w != parents[w]) {
                parents[w] = parents[parents[w]];
                w = parents[w];
            }
            while (v != parents[v]) {
                parents[v] = parents[parents[v]];
                v = parents[v];
            }
            if (v != w) {
                parents[v] = w;
                ans--;
            }
        }
        return ans;
    }
};
}
