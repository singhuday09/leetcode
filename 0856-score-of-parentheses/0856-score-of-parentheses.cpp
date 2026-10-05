class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> st;
        int scr = 0, cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } 
            else if(s[i-1]=='('){
                st.pop();
                scr+=pow(2, st.size());
            }
            else
            st.pop();
        }

        return scr;
    }
};
