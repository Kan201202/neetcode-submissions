class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        
        // Treat the 2D matrix as a flat 1D array
        int l = 0;
        int r = (ROWS * COLS) - 1;
        
        while(l <= r) {
            int mid = l + (r - l) / 2;
            
            // Map the 1D mid index directly back to 2D coordinates
            int row = mid / COLS;
            int col = mid % COLS;
            int midValue = matrix[row][col];
            
            if(midValue == target) {
                return true;
            }
            else if(midValue < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        
        return false;
    }
};