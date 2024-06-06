class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0)
            return false;
        map<int, int> count;
        for(int card : hand)
            count[card]++;
        
        for(auto i = count.begin(); i != count.end(); i++){
            if(i->second > 0){
                int c = i->second;
                for(int j = 0; j < groupSize; j++){
                    if(count[i->first + j] < c){
                        return false;
                    }
                    count[i->first + j] -= c;
                }
            }
        }
        return true;
    }
};