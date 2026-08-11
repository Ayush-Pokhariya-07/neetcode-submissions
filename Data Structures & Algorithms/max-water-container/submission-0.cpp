class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int l = 0; 
        int r = n - 1;
        int ans = INT_MIN;
        int currVol = 0;

        while(l < r){
            currVol = min(heights[l], heights[r]) * (r - l);
            ans = max(ans, currVol);
            
            if(heights[l] < heights[r]){
                l++;
            }
            else{
                r--;
            }
        }

        return ans;
    }
};
