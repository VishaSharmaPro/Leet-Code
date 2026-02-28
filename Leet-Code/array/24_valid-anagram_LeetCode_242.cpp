// amazon google meta oracle microsoft bloomberg apple lg nvidia nokia ibm accenture
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> arrs(26,0);
        vector<int> arrt(26,0);
        for(char & ch :s){
            arrs[ch-'a'] += 1;
        }
        for(char & ch :t){
            arrt[ch-'a'] += 1;
        }
        for(int i = 0;i<26;i++){
            if(arrs[i] != arrt[i]){
                return false;
                break;
            }
        }
        return true;
    }
};
