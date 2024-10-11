// Better Approach - Sorting
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        vector<pair<int, int>> vp;
        // storing element with their index
        for (int i = 0; i < n; i++) {
            vp.push_back({nums[i], i});
        }

        sort(vp.begin(), vp.end());

        // Keep track of the minimum index seen so far
        int minIndex = vp[0].second;

        for (int i = 1; i < n; i++) {
            // Calculate the width and update the maximum ramp width
            ans = max(ans, vp[i].second - minIndex);
            // Update the minimum index
            minIndex = min(minIndex, vp[i].second);
        }

        return ans;
    }
};