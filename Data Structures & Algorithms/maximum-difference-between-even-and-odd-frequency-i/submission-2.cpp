class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26,0);

        for(int i = 0; i < s.size(); i++){
            freq[s[i]-'a']++;
        }

        int maxOdd = INT_MIN, minOdd = INT_MAX;
        int maxeven = INT_MIN, mineven = INT_MAX;

        for(int i = 0; i < 26; i++){
            if(freq[i]!= 0){
                if(freq[i]%2 == 0){
                    maxeven = max(maxeven, freq[i]);
                    mineven = min(mineven, freq[i]);
                }
                else{
                    maxOdd = max(maxOdd, freq[i]);
                    minOdd = min(minOdd, freq[i]);
                }
            }
        }

        return maxOdd - mineven;
    }
};