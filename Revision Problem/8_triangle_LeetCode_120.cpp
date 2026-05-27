// google amazon microsoft meta bloomberg agoda oracle goldman walmart
class Solution {
public:
    int n;
    int t[201][201];
    bool visited[201][201];
    int solve(vector<vector<int>>& triangle,int i,int j){
        if(i>=n) return 0;
        if(visited[i][j]) return t[i][j];
        visited[i][j] = true;
        if(t[i][j] != -1) return t[i][j];
        int leftdown = triangle[i][j] + solve(triangle, i+1, j);
        int rightdown = triangle[i][j] + solve(triangle, i+1, j+1);
        return t[i][j] =  min(leftdown,rightdown);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        memset(t,-1,sizeof(t));
        memset(visited, false, sizeof(visited));
        return solve(triangle, 0, 0);
    }
};
