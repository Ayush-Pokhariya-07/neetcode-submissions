class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;

        for(int i = 0; i < strs.size(); i++){
            ans += to_string(strs[i].size()) + ':' + strs[i];
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string str = "";

        int i = 0;
        while(i < s.size()){
            string len = "";
            while(s[i] != ':'){
                len += s[i];
                i++;
            }
            i++;
            int n = i + stoi(len);

            while(i < n){
                str += s[i];
                i++;
            }

            ans.push_back(str);
            str = "";
        }
        return ans;
    }
};
