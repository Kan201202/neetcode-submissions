class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        // Optimization: Pre-allocate memory. 
        // In RPN, numbers take up at most half the tokens + 1.
        st.reserve(tokens.size() / 2 + 1); 

        for(const string& token : tokens) {
            // Check if token is an operator
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                // Extract operands exactly once
                int temp1 = st.back(); 
                st.pop_back();
                int temp2 = st.back(); 
                st.pop_back();
                
                // Apply operation and push back
                if(token == "+") st.push_back(temp2 + temp1);
                else if(token == "-") st.push_back(temp2 - temp1);
                else if(token == "*") st.push_back(temp2 * temp1);
                else if(token == "/") st.push_back(temp2 / temp1);
            } 
            else {
                // Convert string to int and push
                st.push_back(stoi(token));
            }
        }

        return st.back();
    }
};