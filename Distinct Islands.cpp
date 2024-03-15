#include "vector"
#include "bits/stdc++.h"
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool vis[1005][1005];
int n,m;

set<string>st;
bool valid(int i,int j){
    return i>=0 && i < n && j >=0 && j <m;
}
string dfs(int i,int j,int** arr){
    vis[i][j] = 1;
    string ans = "";
    for(int k =0;k<4;k++){
        int ii = i + dx[k];
        int jj = j + dy[k];
        if (valid(ii, jj) && !vis[ii][jj] && arr[ii][jj] == 1) {
            string t;
            if(k == 0){
                t = "D";
            }
            else if(k == 1){
                t = "U";
            }
            else if(k == 2){
                t = "R";
            }
            else{
                t = "L";
            }
            ans += t + dfs(ii, jj, arr);
        }
    }
    return ans + "B";
}
int distinctIslands(int **arr, int na, int ma)
{
    n = na;m=ma;
    int cnt = 0;
    map<string,int>mp;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if (arr[i][j] == 1 && !vis[i][j]) {

                st.insert("S"+dfs(i,j,arr));
            }
        }
    }
    return st.size();
}