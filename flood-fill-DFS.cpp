#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    // Helper Depth-First Search Function
    void DFS (vector<vector<int>>& matrix, int i, int j, int r, int c, int color, int cellColor) {
            if (i < 0 || i >= r || j < 0 || j >= c || matrix[i][j] != cellColor) return;

            matrix[i][j] = color;

            DFS(matrix, i-1, j, r, c, color, cellColor);
            DFS(matrix, i+1, j, r, c, color, cellColor);
            DFS(matrix, i, j+1, r, c, color, cellColor);
            DFS(matrix, i, j-1, r, c, color, cellColor);
        }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size();
        int c = image[0].size();

        int cellColor = image[sr][sc];

        if (cellColor == color) return image;

        DFS (image, sr, sc, r, c, color, cellColor);

        return image;
    }
};