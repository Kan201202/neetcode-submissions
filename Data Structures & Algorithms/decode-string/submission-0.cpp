class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for(char c: s){
            if(c!=']')st.push(c);
            else{
                string temp = "";
                while(!st.empty() && st.top()!='['){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                reverse(temp.begin(), temp.end());

                string num = "";
                while(!st.empty() && isdigit(st.top())){
                    num+=st.top();
                    st.pop();
                }

                reverse(num.begin(), num.end());
                int k = stoi(num);

                for(int i=0;i<k;i++){
                    for(char ch:temp)st.push(ch);
                }
            }
        }

        string khooshi = "";
        while(!st.empty()){
            khooshi+=st.top();
            st.pop();
        }
        reverse(khooshi.begin(), khooshi.end());
        return khooshi;
    }
};