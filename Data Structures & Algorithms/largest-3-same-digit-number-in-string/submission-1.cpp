class Solution {
public:
    string largestGoodInteger(string nums) {
        char ans = 0;
        int n = nums.size();

        for(int i = 0; i + 2 < n; i++){
            if(nums[i] == nums[i+1] && nums[i] == nums[i+2]){
                ans = max(ans, nums[i]);
            }
        }
        return ans == 0 ? "" : string(3, ans);

    }
};