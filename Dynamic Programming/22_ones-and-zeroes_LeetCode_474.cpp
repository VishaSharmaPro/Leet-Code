// google meta bloomberg amazon uber
class Solution {
public:
    int t[601][101][101];
    unordered_map<int,pair<int,int>> mp;
    int solve(int i, int zero, int one, vector<string>& strs, int m, int n){
        if(i >= strs.size()) return 0;
        if(t[i][zero][one] != -1) return t[i][zero][one];
        int take = 0;
        if(zero + mp[i].first <= m && one + mp[i].second <= n){  // first=zero, second=one
            take = 1 + solve(i+1, zero + mp[i].first, one + mp[i].second, strs, m, n);
        }
        int skip = solve(i+1, zero, one, strs, m, n);
        return t[i][zero][one] = max(take, skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        for(int i = 0; i < strs.size(); i++){
            int one = 0, zero = 0;
            for(char& ch : strs[i]){
                if(ch == '0') zero++;
                else one++;
            }
            mp[i] = {zero, one};  // fix: zero pehle, one baad
        }
        memset(t,-1,sizeof(t));
        return solve(0, 0, 0, strs, m, n);
    }
};
