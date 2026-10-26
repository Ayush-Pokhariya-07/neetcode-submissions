// class Solution {
// public:
//     int ansConsecutive(vector<int>& nums) {
//         if(nums.size() == 0)    return 0;
//         int ans = 1;
//         int cnt = 1;
//         sort(nums.begin(), nums.end());

//         for(int i = 1; i < nums.size(); i++){
//             if(nums[i] == nums[i-1] + 1){
//                 cnt++;
//                 ans = max(ans, cnt);
//             }
//             else if(nums[i] == nums[i-1]){
//                 continue;
//             }
//             else{
//                 ans = max(ans, cnt);
//                 cnt = 1;
//             }
//         }

//         return ans;
//     }
// };




class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int ans = 0;

        for(int n : set){
            if(set.find(n - 1) == set.end()){
                int len = 1;
                while(set.find(n + len) != set.end()){
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};