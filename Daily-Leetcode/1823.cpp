//Approach-1-Simple Simulation using Array
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr;
        for(int i = 1; i <= n; i++){
            arr.push_back(i);
        }
        int i = 0;
        while(arr.size() > 1){ //O(n)
            int idx = (i+k-1) % arr.size();
            arr.erase(arr.begin() + idx); //O(n)
            i = idx;
        }
        return arr[0];
    }
};
//Approach-2-Using queue
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> que;
        for(int i=1; i<=n; i++){
            que.push(i);
        }
        while(que.size()>1){
            for(int count=1; count <= k-1; count++){
                que.push(que.front());
                que.pop();
            }
            que.pop();
        }
        return que.front();
    }
};

//Approach-3- Recursion
