#include <iostream>
#include <vector>

using namespace std;

/* Code Explanation

The class has a helper function isvalid that checks if a given coordinate is within matrix bounds. The main function updateMatrix initializes a queue to store coordinates of zero-valued cells and a 2D vector dis to store distances. It first populates dis with -1 and the queue with the coordinates of zero-valued cells. Then, it uses Breadth-First Search (BFS) starting from these zero-valued cells to update dis with the minimum distances to a zero for each cell in the matrix. The updated dis vector is returned.

*/

class Solution {
public:
    bool isvalid(int i,int j,int m,int n)
    {
        if(i==m||j==n||j<0||i<0)
            return false;
        return true;
    }
    
    vector<vector<int>> dir={{1,0},{0,1},{0,-1},{-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
        queue<pair<int,int>> q;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dis(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                { 
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        while(!q.empty())
        {
            pair<int,int> curr=q.front();
            q.pop();
            for(auto& x:dir)
            {
                int a=curr.first+x[0];
                int b=curr.second+x[1];
                if(isvalid(a,b,m,n)&&dis[a][b]==-1)
                {
                    q.push({a,b});
                    dis[a][b]=dis[curr.first][curr.second]+1;
                }
            }
        }
        return dis;
    }
};