#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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