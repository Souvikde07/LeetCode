class Solution {
public:
    int ourLowerBound(int l, int r, vector<int>& potions, int minPotion){
        int possibleIndex = -1;
        int mid = 0;
        while(l<=r){
            mid = l+(r-l)/2;
            if(potions[mid]>=minPotion){
                possibleIndex = mid;
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }
        return possibleIndex;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        int n = potions.size();

        sort(begin(potions),end(potions));

        int maxPotionValue = potions[n-1];

        vector<int> answer;

        for(int i = 0; i<m; i++){
            int spell = spells[i];
            //minpotion = spell>=success
            long long minPotion = ceil((1.0*success)/spell);
            if(minPotion > maxPotionValue){
                answer.push_back(0);
                continue;
            }

            int index = ourLowerBound(0,n-1, potions, minPotion);
            int count = n-index;
            answer.push_back(count);
        }
        return answer;
    }
}; 