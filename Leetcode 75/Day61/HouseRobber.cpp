class Solution {
 // using Recursion and Memoization
    int t[101];

    int solve(vector<int>& nums, int i, int n){
        if(i>=n)
         return 0;
        if(t[i]!=-1){
            return t[i];
        }

        int steal = nums[i] + solve(nums, i+2, n);
        int skip = solve(nums, i+1,n);
        return t[i] = max(steal,skip);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums, 0 , n);
    }
};

// using bottom-up approach :
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1)
            return nums[0];

        vector<int> t(n+1,0);

        //t[i] = max stolen money till i house
        //no house : i=1
        t[0] = 0;
        //1 house : i=1
        t[1] = nums[0];

        for(int i = 2; i<=n; i++){
            int steal = nums[i-1] + t[i-2];
            int skip = t[i-1];
            t[i] = max(steal,skip);
        }
        return t[n];
    }
};