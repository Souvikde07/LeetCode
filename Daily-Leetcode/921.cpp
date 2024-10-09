class Solution {
public:
    int minAddToMakeValid(string s) {
        int openingB = 0;
        int closingB  = 0;
        for(const char& ch : s){
            if(ch == ')'){
                if(openingB >=1){
                    openingB--;
                }
                else{
                    closingB++;
                }
            }
            else{
                openingB++;
            }
        }
        return openingB+closingB;
    }
};