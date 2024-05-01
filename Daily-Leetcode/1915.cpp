class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long cnt[1024]; //2^10
        memset(cnt, 0, sizeof(cnt));
        int mask = 0;
        cnt[0]=1;
        long long ans = 0;
        for(auto c:word){
            int val = c- 'a';
            mask ^=(1<<val);
            ans += cnt[mask]; // even number of occurences for all chars

            for(int i=0;i<10;i++){
                int temp_mask = mask ^(1<<i);
                ans += cnt[temp_mask]; //for adding occurences atmost 1 time
            }
            cnt[mask]++;
        }
        return ans;


    }
};