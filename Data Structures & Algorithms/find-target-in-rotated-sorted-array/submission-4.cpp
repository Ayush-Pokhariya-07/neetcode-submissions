// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int ans = -1;

//         for(int i = 0; i < nums.size(); i++){
//             if(nums[i] == target){
//                 ans = i;
//                 break;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        int l = 0;
        int h = nums.size() - 1;

        while(l <= h){
            int mid = l+(h-l)/2;

            if(nums[mid] == target){
                ans = mid;
                break;
            }
            else if(nums[l] <= nums[mid]){
                if(target < nums[l] || target > nums[mid]){
                    l = mid + 1;
                }
                else{
                    h = mid - 1;
                }
            }
            else{
                if(target > nums[h] || target < nums[mid]){
                    h = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
        }
        return ans;
    }
};
