class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int ans = 0;
        int l = 0;

        for(int r = 0; r < s.size(); r++){
            while(freq[s[r]] > 0){
                freq[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
            freq[s[r]]++;
        }
        return ans;
    }
};
