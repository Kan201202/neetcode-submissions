class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==1){
            return strs[0];
        }
        string common = "";
        int j=0;
        while(j<strs[0].size() && j<strs[1].size()){
            if(strs[0][j] == strs[1][j]){
                common += strs[0][j];
                j++;
            }
            else break;
        }

        if(n==2)return common;
        for(int i=2;i<strs.size();i++){
            string temp="";
            int k=0;
            while(k<strs[i].size() && k<common.size()){
                if(strs[i][k] == common[k]){
                    temp += strs[i][k];
                    k++;
                }
                else break;
            }
            common = temp;
        }

        return common;
    }
};