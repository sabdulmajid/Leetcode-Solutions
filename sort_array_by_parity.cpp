#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Code Explanation

The code defines a method sortArrayByParity, which takes a vector A as input and returns a vector. The method aims to sort the array so that all the even numbers come before all the odd numbers. It initializes two pointers i and j at the beginning of the array. i traverses the array, and whenever an even number is encountered, it swaps this number with the element at index j, and then increments j. This way, all even numbers are moved to the beginning of the array as i traverses through the array, keeping the relative order of all encountered even numbers. Once the traversal is complete, it returns the modified vector A. This is an in-place sorting algorithm with a linear time complexity of O(n), where n is the length of the input vector.

*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
    int j = 0;
    for(int i = 0; i < A.size(); i++)
	{
        if(A[i] % 2 == 0)
		{
            swap(A[i], A[j]);
            j++;
		}
	}
    
    return A;
    }
};