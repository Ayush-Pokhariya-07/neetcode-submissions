class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int ans = 0;
        priority_queue<int> pq(gifts.begin(), gifts.end());

        while(k--){
            int top = pq.top();
            pq.pop();

            int reduced = floor(sqrt(top));
            pq.push(reduced);
        }

        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};