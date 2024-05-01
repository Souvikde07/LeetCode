class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();

        sort(begin(points),end(points));

        vector<int> prev = points[0];
        int count = 1;
        for(int i = 1; i<n; i++){
            int currStartPoint = points[i][0];
            int currEndPoint = points[i][1];

            int prevStartPoint = prev[0];
            int prevEndPoint = prev[1];

            if(currStartPoint>prevEndPoint){
                count++;
                prev = points[i];
            } else {
                prev[0] = max(prevStartPoint, currStartPoint);
                prev[1] = min(currEndPoint, prevEndPoint);
            }
        }
        return count;
    }
};