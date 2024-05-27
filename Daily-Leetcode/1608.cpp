class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int l = 0; 
        int r = n;

        while(l <= r){
            int mid_x = l + (r-l)/2;
            int idx = lower_bound(begin(nums), end(nums), mid_x)-begin(nums);
            int count = n - idx;
            if(count == mid_x){
                return mid_x;
            } else if (count > mid_x)
            {
                l = mid_x + 1;
            } else {
                r = mid_x - 1;
            }
        }
        return -1;
    }
};