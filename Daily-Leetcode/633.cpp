class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c);
        while(left <= right){
            long long total = left * left + right * right;
            if(total == c){
                return true;
            }else if(total > c){
                right--;
            }else{
                left++;
            }
        }
        return false;
    }
};