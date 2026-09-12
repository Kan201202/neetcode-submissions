class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="C"){
                st.pop();
            }
            else if(operations[i]=="+"){
                if(st.size()>=2){
                    int temp1 = st.top();
                    st.pop();
                    int temp2 = st.top();
                    st.push(temp1);
                    st.push(temp1+temp2);
                }
            }
            else if(operations[i]=="D"){
                int temp =st.top();
                st.push((2*temp));
            }
            else{
                st.push(stoi(operations[i]));
            }
        }

        int khooshi = 0;
        while(!st.empty()){
            khooshi+=st.top();
            st.pop();
        }

        return khooshi;
    }
};