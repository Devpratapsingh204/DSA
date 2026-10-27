class Solution {
public:
    // Helper function jo kisi specific column mein max element ki row index nikal kar deta hai
    int findMaxRow(vector<vector<int>>& mat, int n, int midCol) {
        int maxVal = -1;
        int maxRowIndex = -1;
        for (int i = 0; i < n; i++) {
            if (mat[i][midCol] > maxVal) {
                maxVal = mat[i][midCol];
                maxRowIndex = i;
            }
        }
        return maxRowIndex;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();       // Total rows
        int m = mat[0].size();    // Total columns
        
        int lowCol = 0, highCol = m - 1;

        while (lowCol <= highCol) {
            int midCol = lowCol + (highCol - lowCol) / 2;
            
            // Middle column ka max element kis row mein hai, woh pata lagao
            int maxRow = findMaxRow(mat, n, midCol);

            // Left aur right neighbours ki values check karo (boundaries ke liye -1 maan lo)
            int leftNeighbor = (midCol - 1 >= 0) ? mat[maxRow][midCol - 1] : -1;
            int rightNeighbor = (midCol + 1 < m) ? mat[maxRow][midCol + 1] : -1;

            // Agar current element apne dono neighbours se bada hai, toh ye peak hai!
            if (mat[maxRow][midCol] > leftNeighbor && mat[maxRow][midCol] > rightNeighbor) {
                return {maxRow, midCol};
            }
            // Agar left neighbor bada hai, toh left half mein jao
            else if (mat[maxRow][midCol] < leftNeighbor) {
                highCol = midCol - 1;
            }
            // Agar right neighbor bada hai, toh right half mein jao
            else {
                lowCol = midCol + 1;
            }
        }
        return {-1, -1};
    }
};