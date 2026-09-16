class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;

        for(int num:nums){
            left = max(left,num);
            right+=num;
        }

        int khooshi = right;

        while(left<=right){
            int mid = left + (right-left)/2;

            int split = 1;
            int curr=0;
            for(int num:nums){
                if(curr+num > mid){
                    curr=num;
                    split++;
                }
                else curr+=num;
            }

            if(split<=k){
                khooshi=mid;
                right=mid-1;
            }
            else left = mid+1;
        }
        return khooshi;
    }
};