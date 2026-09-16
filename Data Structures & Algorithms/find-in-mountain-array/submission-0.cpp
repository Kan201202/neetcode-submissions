/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int sear(int target, MountainArray& arr, int left, int right, bool ascend){
        while(left<=right){
            int mid = left + (right-left)/2;
            int midval = arr.get(mid);

            if(midval==target)return mid;

            if(ascend){
                if(midval<target)left = mid+1;
                else right = mid-1;
            }
            else{
                if(midval<target)right = mid-1;
                else left = mid+1;
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int l=0, r=n-1;
        while(l<r){
            int m = l + (r-l)/2;
            if(mountainArr.get(m) < mountainArr.get(m+1))l=m+1;
            else r = m;
        }
        int peak = l;

        int khooshi = sear(target, mountainArr, 0, peak, true);
        if(khooshi != -1)return khooshi;

        return sear(target, mountainArr, peak+1, n-1, false);
    }
};