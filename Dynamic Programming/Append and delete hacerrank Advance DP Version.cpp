int m;
int n;
int solve(int i, int j, string &s, string &t) {
    if(i >= m || j >= n) return 0;
    
    if(s[i] == t[j]) {
        return 1 + solve(i + 1, j + 1, s, t);
    } else {
        return max(solve(i + 1, j, s, t), solve(i, j + 1, s, t));
    }
}
string appendAndDelete(string s, string t, int k) {
    m = s.length();
    n = t.length();
    
    solve(0,0,s,t);
    int lcs = solve(0, 0, s, t);
    int minOperations = abs(m-lcs) + abs(n-lcs);
    if(k < minOperations) {
        return "No";
    }
    else if(k >= m + n) {
        return "Yes"; // Delete all and append all
    }
    else if((k - minOperations) % 2 == 0) {
        return "Yes"; // Extra moves can be wasted by delete+append on same char
    }
    else {
        return "No";
    }
}
