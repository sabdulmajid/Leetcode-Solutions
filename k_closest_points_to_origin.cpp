#include <iostream>
#include <vector>

using namespace std;

/* Code Explanation

The C++ code defines a class Solution with a public method kClosest, which takes a 2D vector points representing Cartesian coordinates of points and an integer k, and returns a 2D vector containing k closest points to the origin (0, 0). The method uses a max-heap (priority_queue) to maintain the k closest points based on their Euclidean distance squared (xx + yy). For each point in points, its distance squared along with its coordinates are pushed onto the max-heap. If the heap's size exceeds k, the farthest point (at the top of the max-heap) is removed. Finally, the remaining k points in the max-heap are popped into the result vector, which is returned.

*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result(k);
        priority_queue<vector<int>> maxHeap;

        for (auto& p : points) {
            int x = p[0], y = p[1];
            maxHeap.push({x*x + y*y, x, y});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        for (int i = 0; i < k; ++i) {
            vector<int> top = maxHeap.top();
            maxHeap.pop();
            result[i] = {top[1], top[2]};
        }
        
        return result;
    }
};