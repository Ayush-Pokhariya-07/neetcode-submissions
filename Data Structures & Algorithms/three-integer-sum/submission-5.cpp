class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i < n - 2; i++){
            if(i > 0 && nums[i] == nums[i-1])   continue;

            int target = (-nums[i]);
            int l = i + 1;
            int r = n - 1;

            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum == target){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < n && nums[l-1] == nums[l])      l++;
                    while(l < r && nums[r] == nums[r+1])      r--;
                }
                else if(sum > target)   r--;
                else if(sum < target)   l++;
            }
        }
        return ans;
    }
};
