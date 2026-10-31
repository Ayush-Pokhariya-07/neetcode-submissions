// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int lmax = height[0];
//         int ans = 0;
//         int n = height.size();

//         for(int i = 1; i < n-1; i++){
//             int rmax = 0;
//             for(int j = i+1; j < n; j++){
//                 rmax = max(rmax, height[j]);
//             }
//             lmax = max(lmax, height[i]);
//             if(rmax >= height[i]){
//                 ans += (min(lmax, rmax) - height[i]);
//             }
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();

        vector<int> prefix(n,0);
        prefix[0] = height[0];

        vector<int> suffix(n,0);
        suffix[n-1] = height[n-1];

        for(int i = 1; i < n; i++){
            prefix[i] = max(height[i], prefix[i-1]);
        }
        for(int i = n-2; i >= 0; i--){
            suffix[i] = max(height[i], suffix[i+1]);
        }

        for(int i = 1; i < n-1; i++){
            if(suffix[i] >= height[i]){
                ans += (min(prefix[i], suffix[i]) - height[i]);
            }
        }

        return ans;
    }
};
