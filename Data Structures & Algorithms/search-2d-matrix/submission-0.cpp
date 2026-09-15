class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> row(matrix.size());
        for(int i=0;i<matrix.size();i++){
            row[i] = matrix[i][0];
        }

        int l = 0, r=matrix.size()-1;

        bool khooshi = false;

        int currow = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(row[mid]==target){
                khooshi=true;
                return khooshi;
            }
            else if(row[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }

        currow = r;
        if(currow<0)return false;
        vector<int> column(matrix[0].size());

        for(int i=0;i<matrix[0].size();i++){
            column[i] = matrix[currow][i];
        }

        int a = 0, b=matrix[0].size()-1;

        while(a<=b){
            int mid = a + (b-a)/2;
            if(column[mid]==target){
                khooshi=true;
                return khooshi;
            }
            else if(column[mid]<target){
                a=mid+1;
            }
            else{
                b=mid-1;
            }
        }

        return khooshi;

    }
};
