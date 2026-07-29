class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int i=0;
        int ans=0;
        while(i<tokens.size()){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/") st.push(stoi(tokens[i]));
            else{
                int b= st.top();
                st.pop();
                int a=st.top();
                st.pop();
                if(tokens[i]=="+") ans=a+b;
                else if(tokens[i]=="-") ans=a-b;
                else if(tokens[i]=="*") ans=a*b;
                else ans=a/b;
                st.push(ans);
            }
            i++;
        }
        return st.top();
    }
};