class Graph {

public:
    bool vis[100005];
    bool is_cyclic(int v,int p,vector<int> adj[]){
        vis[v] = true;
        bool res = false;
        for(int u : adj[v]){
            if(vis[u] && u != p)
                return true;
            if (!vis[u]) {
                res |= is_cyclic(u,v,adj);
            }
        }
        return res;
    }
    bool detectCycle(int V, vector<int> adj[]) {
        // Write your code here.
        return is_cyclic(1,-1, adj);
    }
};