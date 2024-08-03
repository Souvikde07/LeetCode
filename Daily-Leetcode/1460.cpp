class Solution {
public:
    bool canBeEqual(vector<int>& targetArray, vector<int>& currentArray) {
        if(targetArray.size()!=currentArray.size()){
            return false;
        }
        vector<int> elementCounts(1001,0);
        for(int i=0; i<targetArray.size(); i++){
            elementCounts[targetArray[i]]++;
            elementCounts[currentArray[i]]--;
        }
        for(int count : elementCounts){
            if(count!=0){
                return false;
            }
        }
        return true;
    }
};