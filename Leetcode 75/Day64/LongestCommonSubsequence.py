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