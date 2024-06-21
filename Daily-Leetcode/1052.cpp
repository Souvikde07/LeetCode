class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int init = 0, maxi = 0, curr = 0;
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0){
                init += customers[i];
            } else if(i < minutes){
                curr += customers[i];
            }
        }
        maxi = curr;
        for(int i = minutes; i < n; i++){
            curr += customers[i] * grumpy[i];
            curr -= customers[i-minutes] * grumpy[i-minutes];
            maxi = max(maxi, curr);
        }
        return init + maxi;
    }
};