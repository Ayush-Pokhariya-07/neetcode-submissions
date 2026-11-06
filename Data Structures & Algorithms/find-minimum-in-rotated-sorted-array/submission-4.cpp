// class Solution {
// public:
//     int findMin(vector<int> &nums) {
//         int ans = INT_MAX;
//         for(int n : nums){
//             ans = min(ans, n);
//         }
//         return ans;
//     }
// };



// class Solution {
// public:
//     int findMin(vector<int> &nums) {
//         sort(nums.begin(), nums.end());
//         return nums[0];
//     }
// };



// class Solution {
// public:
//     int findMin(vector<int> &nums) {
//         int ans = *min_element(nums.begin(), nums.end());
//         return ans;
//     }
// };



class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int h = nums.size() - 1;

        while(l < h){
            int mid = l + (h - l)/2;

            if(nums[mid] >= nums[h])     l = mid+1;
            else                        h = mid ;
        }
        return nums[l];
    }
};
