class Solution {
public:
    bool check(char c, char d){
        return ((c == '(' && d == ')') || (c == '[' && d == ']') || (c == '{' && d == '}'));
    }
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else{
                if(st.empty() || !check(st.top(), s[i]))  return false;
                else                        st.pop();
            }
        }

        return st.empty();
    }
};
