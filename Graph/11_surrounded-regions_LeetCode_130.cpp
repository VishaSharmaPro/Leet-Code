// google amazon microosft meta bloomberg oracle uber adobe andruil nutanix moloco
class Solution {
public:
    int m, n;
    vector<vector<bool>> vec;
    vector<vector<bool>> vis;
    vector<vector<int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    void solve(int i,int j,vector<vector<char>>& board){
        vis[i][j] = true;
        if(board[i][j] == 'O') vec[i][j] = false;
        for(auto & dir : dirs){
            int ni = i + dir[0];
            int nj = j + dir[1];
            if(ni >= 0 && nj >= 0 && ni<m && nj <n && board[ni][nj] == 'O' && !vis[ni][nj]){
                vis[ni][nj] = true;
                solve(ni,nj,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        vec = vector<vector<bool>>(m,vector<bool>(n,true));
        vis = vector<vector<bool>>(m,vector<bool>(n,false));
        for(int j = 0;j<n;j++){
            if(board[0][j] == 'O') solve(0,j,board);
        }
        for(int j =0; j<n;j++){
            if(board[m-1][j] == 'O') solve(m-1,j,board);
        }
        for(int i = 0;i<m;i++){
            if(board[i][0] == 'O') solve(i,0,board);
        }
        for(int i = 0;i<m;i++){
            if(board[i][n-1] == 'O') solve(i,n-1,board);
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(vec[i][j] == true && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};
