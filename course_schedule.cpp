#include <iostream>
#include <vector>

using namespace std;

/* Code Explanation

The code basically contains a function named canFinish which determines if it's possible to finish all courses given a total number of courses n and a list of course prerequisites. The prerequisites are represented as pairs, where one course is dependent on another. The function constructs an adjacency list (adj) representing the course dependency graph and computes the in-degree (number of prerequisites) for each course. Using a queue, the function then performs a topological sort on the courses: it starts by enlisting all courses with no prerequisites (in-degree 0) and iteratively processes courses, reducing the in-degree of their dependents. If all courses can be taken, the result of the topological sort (ans) should have n courses, and the function returns true; otherwise, it returns false, indicating that there are courses that cannot be completed due to cyclic dependencies.

*/

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        vector<int> ans;

        for(auto x: prerequisites){
            adj[x[0]].push_back(x[1]);
            indegree[x[1]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto t = q.front();
            ans.push_back(t);
            q.pop();

            for(auto x: adj[t]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }
        return ans.size() == n;
    }
};