//Company Tags  : Google, Amazon, OYO Rooms, Microsoft, Adobe, Flipkart, Siemens(MentorGraphics), meta , amd,  zoho, accenture , tiktok , goldman , nvidia, oracle , deloitte, accolite
class Solution {
public:
    int t[46];
    int solve(int n){
        if(n<0) return 0;
        if(n == 0) return 1;
        if(t[n] != -1) return t[n];
        int onestep = solve(n-1);
        int twostep = solve(n-2);
        return t[n] =  onestep + twostep;
    }
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};

// bottom up on 21 march 2026
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        vector<int> t(n,0);
        t[0] = 1;
        t[1] = 2;
        for(int i=2;i<n;i++){
            t[i] = t[i-1] + t[i-2];
        }
        return t[n-1];
    }
};
