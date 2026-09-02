class Solution {
public:
    string simplifyPath(string path) { // TC : O(N) & SC : O(N)

        string token = "";// SC : O(N)

        stringstream ss(path);//input stream // TC : O(N) & SC : O(N)
        stack<string>st;//SC : O(N)

        while(getline(ss,token,'/')){// getline(from where to read,where to store,delimeter) // TC : O(N)

            if(token == "" || token == "."){
                continue;
            }

            if(token != ".."){

                st.push(token);

            }else if(!st.empty()){

                st.pop();

            }
        }

        if(st.empty()){

            return "/";

        }

        string result = "";// SC : O(N)

        while(!st.empty()){

            result = "/"+st.top()+result;// O(1+2+3+...+N) = O(N^2) in worst case
            st.pop();

        }

        return result;
    }
};