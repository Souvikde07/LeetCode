class Solution {
public:

    vector<vector<int>> result;

    void solve(int i, vector<int>& nums, vector<int>& temp){
        if(i >= nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]); // Take the ith element
        solve(i+1, nums, temp);
        temp.pop_back(); //No take ith element
        solve(i+1, nums, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp; //store subset
        solve(0, nums, temp);
        return result;
    }
};