// google amazon microsoft meta bloomberg
/*
Method1 =
maxel ko DP mein store kyun nahi karte?
Kyunki maxel actually i aur count se deterministically derive ho jaata hai — agar same i aur same count pe pahunche ho, to maxel hamesha same hoga.
Socho: count batata hai ki current group mein kitne elements hain, aur woh elements arr[i-count] se arr[i-1] tak hain (fixed). Toh unka maximum bhi fixed hai.
  */
class Solution {
public:
    int n;
    int dp[501][501];  // dp[i][count] = max sum from i with current group size count
    
    int dfs(int i, int count, int maxel, vector<int>& arr, int k) {
        // Base case
        if(i >= n) {
            return count * maxel;
        }
        
        if(dp[i][count] != -1) return dp[i][count];
        
        int maxi = max(maxel, arr[i]);
        int ans = 0;
        
        // Option 1: Continue current group
        if(count < k) {
            ans = max(ans, dfs(i+1, count+1, maxi, arr, k));
        }
        
        // Option 2: Partition here (end current group)
        int currentGroupSum = count * maxel;
        ans = max(ans, currentGroupSum + dfs(i+1, 1, arr[i], arr, k));
        
        return dp[i][count] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(dp, -1, sizeof(dp));
        return dfs(1, 1, arr[0], arr, k);
    }
};

// Method = 2 
class Solution {
public:
    int n;
    int dp[501];  // dp[i][count] = max sum from i with current group size count
    
    int dfs(int i, vector<int>& arr, int k) {
        // Base case
        if(i >= n) {
            return 0;
        }
        
        if(dp[i] != -1) return dp[i];
        
        int maxval = 0;
        int ans = 0;
        
        for(int j = i;j<min(n,i+k);j++){
            maxval = max(maxval,arr[j]);
            int size = j-i+1;
            ans = max(ans,size*maxval + dfs(j+1,arr,k));
        }
        
        return dp[i] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(dp, -1, sizeof(dp));
        return dfs(0,arr, k);
    }
};
