// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int speed = 1;

//         while(true){
//             int time = 0;
//             for(int i = 0; i < piles.size(); i++){
//                 time += (piles[i]+speed-1)/speed;
//             }
//             if(time <= h){
//                 return speed;
//             }
//             speed++;
//         }
//     }
// };


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;

        while(l <= r){
            int mid = l+(r-l)/2;

            long long time = 0;
            for(int i = 0; i < piles.size(); i++){
                time += (piles[i]+mid-1)/mid; 
            }
            if(time <= h){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};
