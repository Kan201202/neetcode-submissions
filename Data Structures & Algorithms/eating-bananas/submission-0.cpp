class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1;
        int r = 0;
        for(int pile: piles)r = max(r,pile);

        int khooshi = r;

        while(l<=r){
            int m = l + (r-l)/2;

            int total = 0;
            for(int pile:piles){
                total += (pile + m - 1)/m;
            }

            if(total<=h){
                khooshi = min(khooshi, m);
                r=m-1;
            }
            else{
                l=m+1;
            }
        }

        return khooshi;
    }
};
