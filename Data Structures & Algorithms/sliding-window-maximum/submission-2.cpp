// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> ans;
//         int n = nums.size();

//         for(int i = 0; i <= n-k; i++){
//             int maxi = INT_MIN;
//             for(int j = i; j < i+k; j++){
//                 maxi = max(maxi, nums[j]);
//             }
//             ans.push_back(maxi);
//         }

//         return ans;
//     }
// };



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();

        priority_queue<pair<int, int>> maxHeap; // pair<nums[i], i>

        int l = 0;
        int maxi = INT_MIN;
        for(int r = 0; r < n; r++){
            maxHeap.push({nums[r], r});
            if(r-l+1 == k){
                while(maxHeap.top().second < l)     maxHeap.pop();
                maxi = maxHeap.top().first;
                ans.push_back(maxi);
                l++;
            }
        }

        return ans;
    }
};
