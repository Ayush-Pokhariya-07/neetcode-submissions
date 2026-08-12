class Solution {
public:
    bool check(char c, char s){
        if (s == '(' && c == ')') return true;
        if (s == '{' && c == '}') return true;
        if (s == '[' && c == ']') return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else{
                if(st.empty() || !check(s[i], st.top()))    return false;
                st.pop();
            }
        }

        return st.empty();
    }
};
