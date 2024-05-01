//Approach-1
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip = 0;

        while(a!=0||b!=0 || c!=0){
            if((c & 1) == 1){ //Right Most Bit(MSB) == 1
                if((a&1) == 0 && (b&1)==0){
                    flip++;
                }
            }
            else{ //Right Most Bit(MSB) == 0
                if((a&1)==1) flip++;
                if((b&1)==1) flip++;
            }
            a>>=1;
            b>>=1;
            c>>=1;
        }
        return flip;
    }
};
//Aproach-2
class Solution {
public:
    int minFlips(int a, int b, int c) {
        return __builtin_popcount(((a|b)^c)) + __builtin_popcount((a&b)&((a|b)^c));
    }
};