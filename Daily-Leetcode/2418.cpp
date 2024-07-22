//Brute Force:
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        for(int i = 0; i<n-1; i++){
            for(int j = 0; j<n-i-1; j++){
                if(heights[j]<heights[j+1]){
                    int temp = heights[j];
                    heights[j] = heights[j+1];
                    heights[j+1] = temp;
                    string temp1 = names[j];
                    names[j] = names[j+1];
                    names[j+1] = temp1;
                }
            }
        }
        return names;
    }
};
//Efficient Soln:
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        priority_queue<pair<int,string>>maxh;
        vector<string>res;
        int n=heights.size();
        for(int i=0;i<n;i++)
        {
            maxh.push({heights[i],names[i]});
        }
        while(maxh.size()>0)
        {
            res.push_back(maxh.top().second);
            maxh.pop();
        }
        return res;
    }
};
