// Company Tags  : Microsoft, Amazon, Meta
class Solution {
public:
    int m;
    int n;
    int t[501][501];
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2){
        if(i>=m || j>=n) return 0;
        if(t[i][j] != -1) return t[i][j];
        int taken = 0;
        if(nums1[i] == nums2[j]) taken = 1 + solve(i+1,j+1,nums1,nums2);
        int nottakenm = solve(i+1,j,nums1,nums2);
        int nottakenn = solve(i,j+1,nums1,nums2);
        return t[i][j] = max({taken,nottakenm,nottakenn});
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        memset(t,-1,sizeof(t));
        return solve(0,0,nums1,nums2);
    }
};

//Bottom Up
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> t(m+1,vector<int>(n+1));
        for(int i=1;i<m+1;i++){
            for(int j =1;j<n+1;j++){
                if(nums1[i-1] == nums2[j-1]) t[i][j] = 1+ t[i-1][j-1];
                else t[i][j] = max(t[i][j-1],t[i-1][j]);
            }
        }
        return t[m][n];
    }
};
