/**
 * Graph valid tree
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

solution1 : 典型的dfs求法
solution2 ： 使用unionfind方法，一开始每个节点的父节点为其本身。
 */

#include <iostream>
#include <vector>
using namespace std;

namespace graph_valid_tree {
class Solution {
public:
    bool validTree(int n, vector<pair<int, int> >& edges) {
        if (n == 0 || edges.size() < n - 1)
            return false;
        vector<int> state(n, 0);
        vector<vector<bool> > graph(n, vector<bool>(n, false));
        for (auto edge : edges) {
            graph[edge.first][edge.second] = true;
            graph[edge.second][edge.first] = true;
        }
        if (!dfs(0, graph, state))
            return false;
        for (int i = 0; i < n; i++)
            if (state[i] == 0)
                return false;
        return true;
    }
    bool dfs(int cur, vector<vector<bool> >& graph, vector<int>& state) {
        state[cur] = 1;
        for (int j = 0; j < graph.size(); j++) {
            if (graph[cur][j] == true) {
                if (state[j] == 1)
                    return false;
                graph[cur][j] = false;
                graph[j][cur] = false;
                if (!dfs(j, graph, state))
                    return false;
            }
        }
        state[cur] = 2;
        return true;
    }
};

class Solution2 {
public:
    bool validTree(int n, vector<pair<int, int> >& edges) {
        if (n < 1 || edges.size() < n - 1)
            return false;
        vector<int> uf(n, 0);
        for (int i = 0; i < n; i++)
            uf[i] = i;
        for (auto edge : edges) {
            int parent1 = find(uf, edge.first);
            int parent2 = find(uf, edge.second);
            if (parent1 == parent2)
                return false;
            uf[parent1] = parent2;
            n--;
        }
        return n == 1? true : false;
    }
    int find(vector<int>& uf, int x) {
        while (x != uf[x]) {
            uf[x] = uf[uf[x]];
            x = uf[x];
        }
        return x;
    }
};
}

int main() {
  graph_valid_tree::Solution2 solution;
  vector<pair<int,int> > edges;
  edges.push_back(make_pair(0,1));
  if (solution.validTree(2, edges))
    cout << "yes";
  else
    cout << "no";
}
