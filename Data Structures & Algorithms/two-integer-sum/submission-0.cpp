class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans(2);

        for(int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if(map.find(diff) != map.end()){
                ans[0] = map[diff];
                ans[1] = i;
            }
            map[nums[i]] = i;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
