class Solution {
public:

    void dfs(vector<vector<char>>& grid, const int& i, const int& j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]!='1')
            return;

        grid[i][j] = 's';

        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        int myCount{0};

        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    myCount++;
                    dfs(grid,i,j);
                }
            }
        }
        return myCount;
    }
};