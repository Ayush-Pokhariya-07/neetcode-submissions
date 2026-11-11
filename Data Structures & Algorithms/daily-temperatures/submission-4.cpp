// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temp) {
//         int n = temp.size();
//         vector<int> ans(n);

//         for(int i = 0; i < n; i++){
//             int cnt = 1;
//             int j = i+1;
//             while(j < n){
//                 if(temp[j] > temp[i]){
//                     break;
//                 }
//                 else    cnt++;
//                 j++;
//             }
//             if(i == n-1 || j >= n)   ans[i] = 0;
//             else                     ans[i] = cnt;
//         }

//         return ans;
//     }
// };



class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && temp[i] >= temp[st.top()]){
                st.pop();
            }
            if(i == n-1 || st.empty()){
                ans[i] = 0;
            }
            else{
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        
        return ans;
    }
};
