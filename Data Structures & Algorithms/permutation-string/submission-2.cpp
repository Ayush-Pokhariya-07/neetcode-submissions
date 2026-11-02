// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         unordered_map<char, int> freq;
//         for(char c : s1){
//             freq[c]++;
//         }
        
//         int n1 = s1.size();
//         int n2 = s2.size();
        
//         for(int i = 0; i <= n2 - n1; i++){
//             unordered_map<char, int> f;
//             for(int j = i; j < i + n1; j++){
//                 f[s2[j]]++;
//             }
//             int flag = 1;
//             for(int j = i; j < i + n1; j++){
//                 if(freq[s2[j]] != f[s2[j]])     flag = 0;
//             }

//             if(flag == 1)   return true;
//         }

//         return false;
//     }
// };



class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq;
        for(char c : s1){
            freq[c]++;
        }
        
        int n1 = s1.size();
        int n2 = s2.size();
        int l = 0;
        unordered_map<char, int> f;

        for(int r = 0; r < n2; r++){
            f[s2[r]]++;
            if(r-l+1 > n1){
                f[s2[l]]--;
                if(f[s2[l]] == 0){
                    f.erase(s2[l]);
                }
                l++;
            }

            if(f == freq)   return true;
        }

        return false;
    }
};
