class Solution {
public:
int n;
bool vis[205];
void dfs(int u,vector<vector<int>>& roads){
    vis[u] = true;
    for(int i = 1;i<=n;i++){
        if(roads[u-1][i-1] == 1 && !vis[i]){
            dfs(i,roads);
        }
    }
}
    int findCircleNum(vector<vector<int>>& roads) {
    n =roads.size();
    int ans = 0;
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            ans++;
            dfs(i,roads);
        }
    }
    return ans;
    }
};