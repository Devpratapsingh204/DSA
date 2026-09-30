#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low = 0;
        int high = (m * n) - 1;

        // Binary Search on 2D Matrix treated as 1D array
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // 1D index ko 2D matrix ke coordinates (row, col) mein convert karna
            int row = mid / n;
            int col = mid % n;
            
            int val = matrix[row][col];

            if (val == target) {
                return true;
            } else if (val < target) {
                low = mid + 1;  // Target bada hai, right jao
            } else {
                high = mid - 1; // Target chota hai, left jao
            }
        }

        return false;
    }
};
