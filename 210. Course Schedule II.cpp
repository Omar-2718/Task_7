class Solution {
public:
    int vis[2009];
    bool is_cycle(int u,vector<vector<int>>&adj){
        vis[u] = 1;
        bool res = false;
        for(auto v : adj[u]){
            if(!vis[v])
            res |= is_cycle(v,adj);
            else if (vis[v] == 1)
            return true;
        }
        vis[u] = 2;
        return res;
    }
    vector<int> order;
    bool vis2[2009];
    void dfs(int u,vector<vector<int>>&adj){
        vis2[u] = 1;
        for(int v : adj[u]){
            if(!vis2[v])
                dfs(v,adj);
        }
        order.push_back(u);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto e : prerequisites){
            adj[e[0]].push_back(e[1]);
        }
        bool cycle = false;
        for(int i =0;i<numCourses;i++){
            if(!vis[i])
            cycle |= is_cycle(i,adj);
        }
        if(cycle){
            return order;
        }
        else{
            for(int i =0;i<numCourses;i++){
            if(!vis2[i])
            dfs(i,adj);
            }
            return order;
        }

    }
};