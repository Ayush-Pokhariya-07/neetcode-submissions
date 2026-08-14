class Solution {
public:
    int check(int mid, vector<int>& piles){
        int cnt = 0;
        for(int i = 0; i < piles.size(); i++){
            if(piles[i]%mid == 0){
                cnt += (piles[i] / mid);
            }
            else{
                cnt += (piles[i] / mid) + 1;
            }
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        int ans = INT_MAX;

        while(l <= r){
            int mid = l+(r-l)/2;
            if(check(mid, piles) <= h){
                ans = min(ans, mid);
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};
