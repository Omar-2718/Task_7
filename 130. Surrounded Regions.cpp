class Solution {
public:
    int n,m;
    bool vis[205][205];
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool valid(int i,int j){
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    void dfs(int i,int j,vector<vector<char>>& grid){
        vis[i][j] = 1;
        for(int k = 0;k<4;k++){
            int ii = i + dx[k];
            int jj = j + dy[k];
            if(valid(ii,jj) && vis[ii][jj] == 0 && grid[ii][jj] == 'O'){
                dfs(ii,jj,grid);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        for(int i =0;i<n;i++){
            if(board[i][0] == 'O')
            dfs(i,0,board);
        }
        for(int i =0;i<n;i++){
            if(board[i][m-1] == 'O')
            dfs(i,m-1,board);
        }
        for(int i =1;i<m-1;i++){
            if(board[0][i] == 'O')
            dfs(0,i,board);
        }
            for(int i =1;i<m-1;i++){
            if(board[n-1][i] == 'O')
            dfs(n-1,i,board);
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
