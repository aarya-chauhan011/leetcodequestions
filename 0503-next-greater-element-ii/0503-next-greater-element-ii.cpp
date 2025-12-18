class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        vector<int> res(n, -1);
        stack<int> st;  
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && st.top() <= a[i])
                st.pop();
            st.push(a[i]);
        }
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && st.top() <= a[i])
                st.pop();

            if (st.empty())
                res[i] = -1;
            else
                res[i] = st.top();

            st.push(a[i]);
        }
        return res;
    }
};
