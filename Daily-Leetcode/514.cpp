class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &ring, string &key, int ptr, int index){
        int n = ring.size();
        int m = key.size();
        //base
        if(index>=m) return 0;

        if(dp[index][ptr]!=-1){
            return dp[index][ptr];
        }

        //choice
        int steps = 1e9;
        for(int i=0;i<n;i++){
            if(ring[i]==key[index]){
                steps = min(steps, min(abs(i-ptr),n-abs(i-ptr))+1+solve(ring,key,i,index+1));
            }
        }
        return dp[index][ptr] = steps;
    }

    int findRotateSteps(string ring, string key) {
        int ptr = 0;
        int index = 0;
        int n = ring.size();
        int m = key.size();
        dp.assign(m+1,vector<int>(n+1,-1));
        return solve(ring,key, ptr,index);
    }
};