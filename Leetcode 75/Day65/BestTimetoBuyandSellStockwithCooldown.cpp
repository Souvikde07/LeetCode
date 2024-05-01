class Solution {
public:
    int maxP(vector<int>& prices, int& n){
        if(n == 0 ||n == 1)
            return 0;
        /*
            if you notice, while finding the best j from 0 to i-1 (i.e. best buy day)
            t[i] = max(t[i], prices[i] - prices[j] + prev_profit);
            Here, (prices[i] - prices[j] + prev_profit) in this, prices[i] is not changing
            So, it can be written as (prices[i] + (prev_profit - prices[j]))
            We need maximum (prev_profit - prices[j]) = maxDiff
            i.e. (prices[i] + maxDiff)
            SO, we maintain maxDiff through out.
            
            Notice, (when j < 2), prev_profit = 0;
            
            we get, (prices[i] - prices[j])
            So, when j < 2, maxDiff = -prices[j];
            
        */
        vector<int> t(n,0);
        int maxDiff = INT_MIN;
        for(int i=0; i<n;i++){
            if(i<2)
                maxDiff = max(maxDiff, -prices[i]);
            if(i==0)
                t[i] = 0;
            else if(i==1)
                t[i] = max(prices[i]-prices[0],0);
            else {
                //t[i] = max(cooldown, best buy privously to gain max profit after selling now);
                t[i] = max(t[i-1],prices[i]+maxDiff);
                maxDiff = max(maxDiff, t[i-2] - prices[i]);
            }
        }
        return t[n-1];
    }
    

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return maxP(prices, n);
    }
};