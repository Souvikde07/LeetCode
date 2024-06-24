//Approach - 1 - TC - O(N), SC = O(1)
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int cur = 0, res = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(i >= k && nums[i-k] > 1){
                cur--;
                nums[i-k] -= 2;
            }
            if(cur % 2 == nums[i]){
                if(i + k > n) return - 1;
                nums[i] += 2;
                cur++;
                res++;
            }
        }
        return res;
    }
};
//Approach - 2 With Space Complexity = O(n)- due to the isFlipped array used.
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flipped = 0;
        int res = 0;
        vector<int> isFlipped(n, 0);
        for(int i = 0; i < n; i++){
            if(i >= k){
                flipped ^= isFlipped[i-k];
            }
            if(flipped == nums[i]){
                if(i + k > n){
                    return -1;
                }
                isFlipped[i] = 1;
                flipped ^= 1;
                res++;
            }
        }
        return res;
    }
};