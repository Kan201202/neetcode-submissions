class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candi = 0;
        int count = 0;

        for(int num: nums){
            if(count==0)candi = num;

            if(num==candi){
                count++;
            }
            else{
                count--;
            }
        }
        return candi;
    }
};