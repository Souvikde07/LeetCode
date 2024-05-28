class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length(); //t.length()
        int i = 0, j = 0;
        int currCost= 0;
        int maxLength = 0;

        while(j<n){
            currCost += abs(s[j] - t[j]);
            while(currCost > maxCost){
                currCost -= abs(s[i]-t[i]);
                i++; // window shift from left side
            }
            maxLength = max(maxLength, j-i+1);
            j++;
        }
        return maxLength;
    }
};