class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for (int n : nums) {
            count[n] = 1 + count[n];
        }
        for (const auto& entry : count) {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for (int i = freq.size() - 1; i > 0; --i) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};


// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> freq;
//         for(int i = 0; i < nums.size(); i++){
//             freq[nums[i]]++;
//         }

//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
//         for(auto& [key, value] : freq){
//             heap.push({value, key});
//             if(heap.size() > k){
//                 heap.pop();
//             }
//         }

//         vector<int> ans;
//         for(int i = 0; i < k; i++){
//             ans.push_back(heap.top().second);
//             heap.pop();
//         }

//         return ans;
//     }
// };