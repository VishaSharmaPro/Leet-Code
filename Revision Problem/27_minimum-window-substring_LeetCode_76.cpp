// google amazon microsoft meta bloomberg lyft oracle linkedin goldman molco tiktok uber adobe airbnb zeta
class Solution {
public:
    unordered_map<char,int> need;
    unordered_map<char,int> have;
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        for(int i = 0;i<n;i++){
            need[t[i]]++;
        }
        
        int i = 0, j = 0, ans = INT_MAX;
        int start = 0, formed = 0; 
        while(j<m){     
            char c = s[j];
            if(need.count(c)){
                have[c]++;
                if(have[c] == need[c]) formed++;
            }
            while(formed == (int)need.size()){
                if(j-i+1 < ans){
                    ans = j-i+1;
                    start = i;  // start save karo
                }
                char left = s[i];
                if(need.count(left)){
                    have[left]--;
                    if(have[left] < need[left]) formed--;
                }
                i++;
            }
            j++;
        }
        if(ans == INT_MAX) return "";
        return s.substr(start, ans);  // int ki jagah string return karo
    }
};
