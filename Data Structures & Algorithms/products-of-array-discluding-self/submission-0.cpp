class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), prefix(n), suffix(n);

        for(int i = 0; i < n; i++){
            if(i == 0)          prefix[i] = nums[0];
            else if(i == 1)     prefix[i] = prefix[0];
            else{
                prefix[i] = prefix[i-1] * nums[i-1];
            }    
        }
        for(int i = n-1; i >= 0; i--){
            if(i == n-1)          suffix[i] = nums[n-1];
            else if(i == n-2)     suffix[i] = suffix[n-1];
            else{
                suffix[i] = suffix[i+1] * nums[i+1];
            }    
        }

        for(int i = 0; i < n; i++){
            if(i == 0)          ans[i] = suffix[i];
            else if(i == n-1)   ans[i] = prefix[i];
            else{
                ans[i] = prefix[i] * suffix[i];
            }
        }

        return ans;
    }
};
