class Solution {
public:
    int scoreOfString(string s) {
        int res = 0;
        int n = s.size();
        for(int i = 0; i <= n-2; i++){
            res += abs(s[i]-s[i+1]);
        }
        return res;
    }
};