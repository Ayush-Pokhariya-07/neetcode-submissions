class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0];
        int curr = nums[0];

        for(int i = 0; i + 1 < nums.size(); i++){
            if(nums[i] < nums[i+1]){
                curr += nums[i+1];
            }
            else{
                ans = max(ans, curr);
                curr = nums[i+1];
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};