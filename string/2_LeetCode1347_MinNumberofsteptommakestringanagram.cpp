// company == Google
class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp;
        for(char &ch : t){
            mp[ch]++;
        }
        for(char &ch :s){
            if(mp.find(ch) != mp.end()){
                mp[ch]--;
                if(mp[ch] == 0){
                    mp.erase(ch);
                } 
            }
        }
        int result = 0;
        for(auto &p : mp){
            result += p.second;
        }
        return result;
    }
};
