class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int ans = 0;

        while(r < prices.size()){
            while(r < prices.size() && prices[l] < prices[r]){
                int profit = prices[r] - prices[l];
                ans = max(ans, profit);
                r++;
            }
            if(r < prices.size() && prices[l] > prices[r]){
                l = r;
            }
            r++;
        }
        return ans;
    }
};
