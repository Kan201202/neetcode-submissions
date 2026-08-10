class Solution {
public:

    int dirs[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& memo){
        if(memo[i][j] > 0)return memo[i][j];

        int maxi = 1;

        for(auto& dir:dirs){
            int x = i + dir[0];
            int y = j + dir[1];

            if(x>=0 && x<matrix.size() && y>=0 && y<matrix[0].size() && matrix[x][y] > matrix[i][j]){
                maxi = max(maxi, 1 + dfs(matrix, x, y, memo));
            }
        }

        return memo[i][j] = maxi;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> memo(m, vector<int> (n,0));
        int longest = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                longest = max(longest, dfs(matrix, i, j, memo));
            }
        }

        return longest;
    }
};
