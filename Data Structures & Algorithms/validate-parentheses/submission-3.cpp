class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(c==']' || c=='}' || c==')'){
                if(st.empty())return false;
                char t = st.top();
                if(c==']' && t=='[')st.pop();
                else if(c=='}' && t=='{')st.pop();
                else if(c==')' && t=='(')st.pop();
                else return false;
            }
            else{
                st.push(c);
            }
        }

        if(st.empty())return true;
        else return false;
    }
};
