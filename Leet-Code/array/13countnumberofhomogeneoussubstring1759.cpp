class Solution {
public:
    int sub = 0;
    const int mod = 1e9+7;
    long long pnc(int n){
        if(n == 0 || n== 1) return 1;
        return (n + pnc(n-1))%mod;
    }
    int countHomogenous(string s) {
        int n = s.length();
        int count = 1;
        char prev = s[0];
        int i;
        for(i =0; i<n;i++){
            if(s[i] == prev && i>0) count++;
            if(s[i] != prev){
                sub = (sub + pnc(count)) % mod;
                count = 1;
                prev = s[i];
            }
        }
        if(i == n){
            sub = (sub + pnc(count)) % mod;
        }
        return sub;
    }
};
