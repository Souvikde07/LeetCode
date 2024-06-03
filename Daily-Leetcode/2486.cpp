class Solution {
public:
    int appendCharacters(string s, string t) {
        int m = s.length();
        int n = t.length();
        int i = 0, j = 0;
        while(i < m && j < n){
            if(s[i] == t[j]){
                i++;
                j++;
            } else{
                i++;
            }
        }
        return n - j; //remaining characters to be appended at the end of s 
    }
};