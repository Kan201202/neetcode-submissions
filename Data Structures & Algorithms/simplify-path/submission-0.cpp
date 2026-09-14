class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string token;

        while(getline(ss, token, '/')){
            if(token=="" || token==".")continue;
            else if(token==".."){
                if(!st.empty())st.pop_back();
            }
            else{
                st.push_back(token);
            }
        }

        string khooshi = "";
        for(const string& dir:st) khooshi+="/"+dir;

        return khooshi.empty() ? "/" : khooshi;
    }
};