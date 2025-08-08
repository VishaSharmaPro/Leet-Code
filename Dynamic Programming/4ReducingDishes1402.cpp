//Company Tags  : MICROSOFT
class Solution {
public:
    int td[501][501];
    int solve(vector<int>& sat, int i, int n, int t) {
        if (i >= n) return 0;
        if (td[i][t] != -1) return td[i][t];
        int include = (t * sat[i]) + solve(sat, i + 1, n, t + 1);
        int exclude = solve(sat, i + 1, n, t);
        return td[i][t] = max(include, exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        memset(td,-1,sizeof(td));
        return solve(satisfaction, 0, n, 1);
    }
};
