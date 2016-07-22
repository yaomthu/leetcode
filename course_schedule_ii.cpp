/**
 * Course schedule II
 * There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

solution: topology sort
time complexity: O(n^2)
space complexity: O(n^2)
 */



#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <queue>
using namespace std;

namespace course_schedule_ii {
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> ans;
        if (numCourses <= 0)
            return ans;
        unordered_map<int, set<int> > graph;
        vector<int> degree(numCourses, 0);
        for (auto request : prerequisites) {
            if (graph[request.second].find(request.first) == graph[request.second].end()) {
                graph[request.second].insert(request.first);
                degree[request.first]++;
            }
        }
        queue<int> Q;
        for (int i=0; i<degree.size(); i++)
            if (degree[i] == 0)
                Q.push(i);
        while (Q.size()) {
            int cur = Q.front();
            Q.pop();
            ans.push_back(cur);
            if (graph.find(cur) != graph.end()) {
                for (auto iter = graph[cur].begin(); iter != graph[cur].end(); iter++) {
                    degree[*iter]--;
                    if (degree[*iter] == 0)
                        Q.push(*iter);
                }
            }
        }
        if (ans.size() < numCourses)
            return vector<int>();
        else
            return ans;
    }
};
}
