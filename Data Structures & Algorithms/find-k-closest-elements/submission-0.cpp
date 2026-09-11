class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0, right = n-1;
        int index=-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(arr[mid] == x){
                index = mid;
                break;
            }
            else if(arr[mid] > x){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }

        if(index==-1){
            if(left==n && right!=-1)index=right;
            else if(right==-1 && left!=n)index=left;
            else if(right==-1 && left==n){
                return arr;
                // as it means array size is 1
            }
            else{
                int dist1 = abs(arr[left]-x);
                int dist2 = abs(arr[right]-x);
                if(dist1<dist2){
                    index = left;
                }
                else{
                    index = right;
                }
            }
        }

        
        int l=index-1, r=index+1;
        vector<int> ans;
        ans.push_back(arr[index]);
        while(ans.size()<k){
            if(l<0){
                ans.push_back(arr[r]);
                r++;
            }
            else if(r>=n){
                ans.push_back(arr[l]);
                l--;
            }
            else{

                int dist1 = abs(arr[l]-x);
                int dist2 = abs(arr[r]-x);
                if(dist1<=dist2){
                    ans.push_back(arr[l]);
                    l--;
                }
                else{
                    ans.push_back(arr[r]);
                    r++;
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};