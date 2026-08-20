class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string answer = "";
        int i=0, j=0;

        bool turn = 0;
        while(i<word1.size() && j<word2.size()){
            if(turn==0){
                answer+=word1[i];
                i++;
                turn=1;
            }
            else{
                answer+=word2[j];
                j++;
                turn=0;
            }
        }

        while(i<word1.size()){
            answer+=word1[i];
            i++;
        }

        while(j<word2.size()){
            answer+=word2[j];
            j++;
        }

        return answer;
    }
};