class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(int i = 0 ; i<s.size();i++){
            char ch = s[i];
            if(st.empty()||st.top().first!=ch){
                st.push({ch,1});
            }
            else{
                st.top().second++;
                if(st.top().second==k){
                    st.pop();
                }
            }
        }
        string res = "";
        while(!st.empty()){
            auto p = st.top();// iski jgah pair<char,int>p = st.top() bhi likhskte thy
            st.pop();
            while(p.second--){
                res.push_back(p.first);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};