class Solution {
public:
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int, int>> que;//que of (i,j)
        que.push({entrance[0], entrance[1]});
        //mark visited by making it a wall "+"
        maze[entrance[0]][entrance[1]] = '+';//visited

        int steps = 0;

        while(!que.empty()){
            int N = que.size();
            
            while(N--){
                pair<int, int> temp = que.front();
                que.pop();

                int i = temp.first;
                int j = temp.second;

                if(temp!= make_pair(entrance[0],entrance[1]) && 
                    (i == 0 || i == m-1 ||j == 0 ||j == n-1)){
                    return steps;
                }
                for(auto &dir : directions){
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && maze[new_i][new_j]!='+'){
                        que.push(make_pair(new_i, new_j));
                        maze[new_i][new_j] = '+';
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};