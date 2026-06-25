// google amazon microsoft meta bloomberg lyft oracle linkedin goldman molco tiktok uber adobe airbnb zeta
// method 1
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


// method 2
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(m > n) return "";
        
        unordered_map<char,int> mp;
        for(int i = 0; i < m; i++) {
            mp[t[i]]++;
        }
        
        int i = 0;
        int j = 0;
        int count = 0;
        int minlen = n+1;
        int start = 0;  
        
        while(j < n) {
            if(mp.find(s[j]) != mp.end()) {
                mp[s[j]]--;                    
                if(mp[s[j]] >= 0){             
                    count++;
                }  
            }
            j++;
            while(count == m) {
                if(j - i < minlen) {
                    minlen = j - i;
                    start = i;
                }
                if(mp.find(s[i]) != mp.end()){  
                    mp[s[i]]++;
                    if(mp[s[i]] > 0) {         
                        count--;
                    }
                }
                i++;
            }
        }
        return minlen == n+1 ? "" : s.substr(start, minlen);
    }
};
/*
Aspect	                  Theoretical           	Practical (LeetCode/CF)
unordered_map::find()	   O(n)                    worst-case	O(1) average
Your Code Complexity	   O(n²)	                           O(n)
Will it pass?	           Maybe not	                     ✅ Yes
*/
