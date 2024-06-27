//Approach-1: Using a map - TC - O(n), SC - O(n)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> degree;
        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];
            degree[u]++;
            degree[v]++;
        }
        for(auto &it : degree){
            if(it.second == edges.size()){
                return it.first;
            }
        }
        return -1;
    }
};

//Approach-2: TC - O(1), SC - O(1)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> first = edges[0]; //{a,b}
        vector<int> second = edges[1]; //{c,a}
        if(first[0] == second[0] || first[0] == second[1]){
            return first[0];
        }
        return first[1];
    }
};