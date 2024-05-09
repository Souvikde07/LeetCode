class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long sum = 0, cnt = -1;
        for(auto i : happiness){
            --k;
            sum += max(0, (int)(i - ++cnt));
            if (k == 0) break; 
        }
        return sum;
    }
};