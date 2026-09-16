class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size() > nums2.size())return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size();
        int n = nums2.size();
        int total = m+n;
        int half = (total+1)/2;

        int left = 0, right = m;
        while(left<=right){
            int i = left + (right-left)/2;
            int j = half - i;

            int lefta = (i>0) ? nums1[i-1]: INT_MIN;
            int righta = (i<m) ? nums1[i]:INT_MAX;

            int leftb = (j>0) ? nums2[j-1]: INT_MIN;
            int rightb = (j<n) ? nums2[j]: INT_MAX;

            if(lefta<=rightb && leftb<=righta){
                if((total&1) !=0){
                    return max(lefta, leftb);
                }

                return (max(lefta,leftb) + min(righta,rightb))/2.0;
            }
            else if(lefta>rightb){
                right = i-1;
            }
            else{
                left = i+1;
            }
        }

        return 0.0;

    }
};
