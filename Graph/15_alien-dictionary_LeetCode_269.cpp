/*
Uber (6), Amazon (4), Google (3), Meta (2), Bloomberg (2), TikTok (7), Microsoft (5), Apple (4), Airbnb (4), Coupang (3), Wix (2), X (2), Nuro (2), Snap (2), Pocket Gems (2).
  */
class Solution {
public:
    int n;
    unordered_map<char, vector<char>> mp;
    unordered_map<char, bool> vis;
    unordered_map<char, bool> path;  
    stack<char> st;
    set<char> cset;
    bool hasCycle = false;           
    
    void topsort(char ch) {          
        for(char ne : mp[ch]) {
            if(path[ne] == true) {    
                hasCycle = true;
                return;
            }
            if(!vis[ne]) {
                vis[ne] = true;
                path[ne] = true;
                topsort(ne);
                if(hasCycle) return;
                path[ne] = false;
            }
        }
        
        path[ch] = false;             
        st.push(ch);                  
    }
    
    string alienOrder(vector<string>& words) {
        n = words.size();
        
        for(string& w : words) {
            for(char c : w) {
                cset.insert(c);
            }
        }
        
        int i = 0, j = 1;
        while(j<n){
            int id = 0;
            bool founddiff = false;
            while(id < min(words[i].size(), words[j].size())){
                if(words[i][id] != words[j][id]){
                    mp[words[i][id]].push_back(words[j][id]);
                    founddiff = true;
                    break;
                }
                id++;
            }
            if(!founddiff && words[i].size() > words[j].size()) return "";
            i++; 
            j++;
        }

        for(char c : cset) {
            if(!vis[c]) {
                vis[c] = true;
                path[c] = true;
                topsort(c);
                if(hasCycle) return "";
                path[c] = false;
            }
        }
        
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
