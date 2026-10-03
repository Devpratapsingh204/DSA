class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n - 1;

        // Top-right corner se start karke search karna
        while (row < m && col >= 0) {
            int current = matrix[row][col];

            if (current == target) {
                return true;
            } else if (current > target) {
                col--; // Agar current bada hai, toh left column mein jao
            } else {
                row++; // Agar current chota hai, toh niche wali row mein jao
            }
        }

        return false;
    }
};