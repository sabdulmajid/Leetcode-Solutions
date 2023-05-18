#include <iostream>
#include <vector>

using namespace std;

/*

This code implements the flood-fill algorithm using depth-first search (DFS) to fill a region in an image with a specified color. The 'Solution' class contains a floodFill function that takes an image, starting position, and target color as parameters. The DFS function is a helper function that performs a depth-first search and updates the color of the cells in the image. It checks if the current cell is within the image boundaries and has the same color as the target cell. If so, it updates the cell's color and recursively calls itself for the adjacent cells. The floodFill function initializes variables and checks if the starting cell already has the target color. If not, it calls the DFS function to perform the flood-fill operation. Finally, the modified image is returned

*/

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