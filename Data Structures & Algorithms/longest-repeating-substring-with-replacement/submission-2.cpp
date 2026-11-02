class Solution {
public:
    int characterReplacement(string s, int k) {
        // int ans = 0;

        // for(int i = 0; i < s.size(); i++){
        //     unordered_map<char, int> freq;
        //     int maxi = 0;
        //     for(int j = i; j < s.size(); j++){
        //         freq[s[j]]++;
        //         maxi = max(maxi, freq[s[j]]);
        //         if((j-i+1)-k-maxi > 0)   break;
        //         ans = max(ans, (j-i+1));
        //     }
        // }

        unordered_map<char, int> freq;
        int l = 0;
        int ans = 0;
        int maxi = 0;
        for(int r = 0; r < s.size(); r++){
            freq[s[r]]++;
            maxi = max(maxi, freq[s[r]]);
            while((r-l+1)-k-maxi > 0){
                freq[s[l]]--;
                l++;
            }
            ans = max(ans, (r-l+1));
        }
        return ans;
    }
};
