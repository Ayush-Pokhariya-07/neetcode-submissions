class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        int l = 0;
        unordered_set<char> charSet;

        for(int r = 0; r < n; r++){
            while(charSet.find(s[r]) != charSet.end()){
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            ans = max(ans, r-l+1);
        }

        return ans;
    }
};
