// google amazon meta microsoft bloomberg
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0) return 1.0;
        if(n > k-1+maxPts) return 1.0;
        vector<double> dp(n+1,0.0);
        double probability = 0.0;
        double windowsum = 1.0;
        dp[0] = 1.0;
        for(int i =1;i<=n;i++){
            dp[i] = windowsum/maxPts;
            if(i<k) windowsum += dp[i];
            else probability += dp[i];
            if(i>= maxPts) windowsum -= dp[i-maxPts];
        }
        return probability;
    }
};
