class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        for (int i = 0;i<n+1;i++){
            result[i] = __builtin_popcount(i);
        }
        return result; 
    }
};
//Time Complexity : nlog(n)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        if(n==0)
            return result;
        result[0] = 0; //Binary of O has 0 number of bits set as 1
        for(int i = 1;i<=n;i++){
            if(i%2 != 0){
                result[i] = result[i/2]+ 1;
            }                
            else{
                result[i] = result[i/2];
            }
        }
    return result;
    }
};
//T.C = O(n)