class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();

        int counta = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == 'a')
                counta++;
        }

        int count = INT_MAX;
        int countb = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'a')
                counta--;
            count = min(count, countb + counta);

            if(s[i] == 'b')
                countb++;
        }

        return count;
    }
};