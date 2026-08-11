class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i + 2 < nums.size(); i++){
            if(i != 0 && nums[i] == nums[i-1])  continue;

            int l = i + 1, h = nums.size() - 1;

            while(l < h){
                if(nums[i] + nums[l] + nums[h] == 0){
                    ans.push_back({nums[i], nums[l], nums[h]});
                    h--; 
                    l++;
                    while(l < h && nums[l] == nums[l-1]){
                        l++;
                    }
                }
                else if(nums[i] + nums[l] + nums[h] > 0){
                    h--;
                }
                else if(nums[i] + nums[l] + nums[h] < 0){
                    l++;
                }
            }
        }

        return ans;
    }
};


