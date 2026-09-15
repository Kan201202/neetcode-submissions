class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            // Ask the hidden API about our current mid
            int result = guess(mid);
            
            if(result == 0) {
                return mid; // We found the picked number
            }
            else if(result == -1) {
                // Our guess was too high
                right = mid - 1;
            }
            else {
                // Our guess was too low (result == 1)
                left = mid + 1;
            }
        }
        
        return -1;
    }
};