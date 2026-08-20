class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int i=0;
        int j=numbers.size()-1;
        int temp=0;
        while(i<j){
            temp = numbers[i] + numbers[j];
            if(temp==target){
                ans.insert(ans.end(), {i+1,j+1});
                break;
            }
            else if(temp < target) i++;
            else j--;
        }
        return ans;
    }
};
