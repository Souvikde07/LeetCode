class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return{0};
        vector<unordered_set<int>> adj(n);
        for(auto& e:edges){
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        queue<int> Q;
        for(int i=0;i<adj.size();i++)
            if(adj[i].size()==1) Q.push(i);
        
        while(n>2){
            int len = Q.size();
            n=n-len;
            for(int i = 0;i<len;i++){
                int node = Q.front();
                Q.pop();
                for(auto& a:adj[node]){
                    adj[a].erase(node);
                    if(adj[a].size()==1)
                        Q.push(a);
                }
            }
        }
        vector<int> result;
        while(!Q.empty()){
            result.push_back(Q.front());
            Q.pop();
        }
        return result;
    }
};