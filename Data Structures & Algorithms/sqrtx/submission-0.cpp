class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        int l=1, r=x;
        while(l<=r){
            int m = l + (r-l)/2;
            long long int t = (long long int) m*m;
            if(t==x)return m;
            else if(t<x){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }

        return r;
    }
};