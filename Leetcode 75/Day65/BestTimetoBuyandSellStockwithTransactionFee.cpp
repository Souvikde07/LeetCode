// Using DP : Recursion and Memoization
class Solution {
public:
    int dp[50001][2];
    int f(vector<int>& nums,int i ,int buy,int fee)
    {
        if(i==nums.size())return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
       if(buy)
       {
           return  dp[i][buy]= max(-nums[i]+f(nums,i+1,0,fee),f(nums,i+1,1,fee));
       }
        else
        {
            return  dp[i][buy]= max(nums[i]-fee+f(nums,i+1,1,fee),f(nums,i+1,0,fee));
        }
    }
    int maxProfit(vector<int>& nums, int fee) {
        memset(dp,-1,sizeof(dp));
     return f(nums,0,1,fee);   
    }
};

// Using Bottom-up Approach
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int prev1=0, prev2=INT_MIN; 
        for(int i=0;i<prices.size();i++) 
        {
            int tmp=prev1;
            prev1= max(prev1,prev2+prices[i]);
            prev2=max(prev2,tmp-prices[i]-fee);
        }
        return prev1;
    }
};