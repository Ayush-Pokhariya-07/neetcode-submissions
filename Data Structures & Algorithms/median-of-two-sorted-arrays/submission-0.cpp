class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0, j = 0;

        int targetIndex = (n1+n2)/2;
        int prevElement = 0;
        int currElement = 0;
        int cnt = 0;

        while(cnt <= targetIndex){
            prevElement = currElement;
            if(i < n1 && (j >= n2 || nums1[i] < nums2[j])){
                currElement = nums1[i];
                i++;
            }
            else{
                currElement = nums2[j];
                j++;
            }
            cnt++;
        }

        if((n1+n2)%2 == 0){
            ans = (currElement + prevElement) / 2.0;
        }
        else{
            ans = currElement;
        }

        return ans;
    }
};
