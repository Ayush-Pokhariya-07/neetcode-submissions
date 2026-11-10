class Solution {
public:
    int cal(int a, int b, char c){
        switch(c){
            case '+' : return b + a;
            case '-' : return b - a;
            case '*' : return b * a;
            case '/' : return b / a;
            default: return 0; 
        }
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> st; 
        
        for(const string& c : tokens){
            if(c == "+" || c == "-" || c == "*" || c == "/"){
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(cal(a, b, c[0]));
            }
            else{
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};
