class Solution {
public:
    int v[1001];
    int solve(int i, vector<int> &nums, int k){
        if(i == nums.size())
            return 1;
        int taken = 0;
        if(nums[i]-k < 0 || v[nums[i]-k]==0){
            v[nums[i]]++;
            taken = solve(i+1,nums, k);
            v[nums[i]]--;
        }
        int notTaken = solve(i+1, nums, k);
        return taken + notTaken;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        memset(v, 0, sizeof(v));
        return solve(0, nums, k) - 1;
    }
};