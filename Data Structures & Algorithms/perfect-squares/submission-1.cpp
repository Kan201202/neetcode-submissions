class Solution {
public:
    int numSquares(int n) {
        int sq = sqrt(n);
        if (sq * sq == n) {
            return 1;
        }
        
        int temp = n;
        while (temp % 4 == 0) {
            temp /= 4;
        }
        if (temp % 8 == 7) {
            return 4;
        }
        
        for (int i = 1; i * i <= n; i++) {
            int remain = n - i * i;
            int r_sq = sqrt(remain);
            if (r_sq * r_sq == remain) {
                return 2;
            }
        }
        
        return 3;
    }
};