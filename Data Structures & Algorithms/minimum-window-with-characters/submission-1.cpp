// class Solution {
// public:
//     string minWindow(string s, string t) {
//         int n1 = s.size();
//         int n2 = t.size();

//         if(n2 > n1)     return "";

//         unordered_map<char, int> freq;
//         for(char c : t){
//             freq[c]++;
//         }

//         int mini = INT_MAX;
//         int start = -1;

//         for(int i = 0; i < n1; i++){
//             unordered_map<char, int> f;
//             for(int j = i; j < n1; j++){
//                 f[s[j]]++;
//                 if(j-i+1 >= n2){
//                     int flag = 1;
//                     for(auto& [key, val] : freq){
//                         if(f[key] < val){
//                             flag = 0;
//                             break;
//                         }
//                     }
//                     if(flag){
//                         if(j-i+1 < mini){
//                             mini = j-i+1;
//                             start = i;
//                         }
//                         break;
//                     }
//                 }
//             }
//         }
//         if(start == -1)     return "";
//         return s.substr(start, mini);
//     }
// };


class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        if(n2 > n1)     return "";

        unordered_map<char, int> freq;
        unordered_map<char, int> f;
        for(char c : t){
            freq[c]++;
        }

        int mini = INT_MAX;
        int start = -1;
        int cnt = 0;
        int l = 0;
        int required_unique = freq.size();
        for(int r = 0; r < n1; r++){
            f[s[r]]++;
            if(freq[s[r]] > 0 && f[s[r]] == freq[s[r]]){
                cnt++;
            }

            while(cnt == required_unique) {
                if(r - l + 1 < mini) {
                    mini = r - l + 1;
                    start = l;
                }

                char left_char = s[l];
                f[left_char]--;

                if(freq[left_char] > 0 && f[left_char] < freq[left_char]) {
                    cnt--;
                }

                l++;
            }
            
        }
        if(start == -1)     return "";
        return s.substr(start, mini);
    }
};
