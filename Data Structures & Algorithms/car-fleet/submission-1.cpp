class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> arr;
        for(int i = 0; i < n; i++){
            arr.push_back({position[i], speed[i]});
        }

        sort(arr.begin(), arr.end());

        stack<double> st;

        for(int i = n-1; i >= 0; i--){
            double t = (double)(target - arr[i].first)/ arr[i].second;
            if(st.empty() || t > st.top()){
                st.push(t);
            }
        }

        return st.size();
    }
};
