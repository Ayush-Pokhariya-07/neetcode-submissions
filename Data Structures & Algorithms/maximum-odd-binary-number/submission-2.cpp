class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1') cnt++;
        }

        string ans = "";
        ans.append(cnt - 1, '1');
        ans.append(n - cnt, '0');
        ans.append(1, '1');
        return ans;
    }
};