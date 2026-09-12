class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size();i++){
            if(tokens[i]=="+"){
                if(st.size()>=2){
                    int temp1 = st.top();
                    st.pop();
                    int temp2 = st.top();
                    st.pop();
                    int res = temp1+temp2;
                    st.push(res);
                }
            }
            else if(tokens[i]=="-"){
                if(st.size()>=2){
                    int temp1 = st.top();
                    st.pop();
                    int temp2 = st.top();
                    st.pop();
                    int res = temp2-temp1;
                    st.push(res);
                }
            }
            else if(tokens[i]=="*"){
                if(st.size()>=2){
                    int temp1 = st.top();
                    st.pop();
                    int temp2 = st.top();
                    st.pop();
                    int res = temp1*temp2;
                    st.push(res);
                }
            }
            else if(tokens[i]=="/"){
                if(st.size()>=2){
                    int temp1 = st.top();
                    st.pop();
                    int temp2 = st.top();
                    st.pop();
                    int res = temp2/temp1;
                    st.push(res);
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};
