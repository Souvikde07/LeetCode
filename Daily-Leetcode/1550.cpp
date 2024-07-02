class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n-2; i++){
            if(arr[i] % 2 == 1 && arr[i+1] % 2 == 1 && arr[i+2] % 2 == 1){
                return true;
            }
        }
        return false;
    }
};

// Approach - 2 - Using Sliding Window Technique
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int window = 0;
        for(int i = 0; i < 3 && i < n; i++){
            window += arr[i] % 2;
        }
        if(window == 3){
            return true;
        }
        for(int i = 3; i < n; i++){
            window += arr[i] % 2;
            window -= arr[i-3] % 2;
            if(window == 3){
                return true;
            }
        }
        return false;
    }
};