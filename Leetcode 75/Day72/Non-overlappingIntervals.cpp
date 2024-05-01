class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));

        int n = intervals.size();
        int count = 0;
        int i = 0, j=1;
        while(j<n){
            vector<int> curr_interval = intervals[i];
            vector<int> next_interval = intervals[j];

            int cs = curr_interval[0];
            int ce = curr_interval[1];

            int ns = next_interval[0];
            int ne = next_interval[1];

            if(ce<=ns){
                i=j;
                j++;
            } else if(ce <= ne){
                j++;
                count++;
            } else if(ce > ne){
                i=j;
                j++;
                count++;
            }
        }
    return count;
    }
};
//approach - 2
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));

        int n = intervals.size();
        int count = 0;
        int i = 1;
        vector<int> L = intervals[0];

        while(i<n){
            int curr_end = intervals[i][1];
            int curr_start = intervals[i][0];;
            int last_end = L[1];

            if(curr_start>=last_end){
                L = intervals[i];
            } else if(curr_end >= last_end){
                count++;
            } else if(curr_end < last_end){
                L = intervals[i];
                count++;
            }
            i++;
        }
    return count;
    }
};