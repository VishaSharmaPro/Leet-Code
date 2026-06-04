// amazon microsoft google
class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        for(int i = 0;i<n;i++) mp[s[i]] = 0;
        int i = 0;
        int j = 0;
        int count = 1;
        while(j<n){
            if(mp[s[j]] == 0){
                mp[s[j]]++;
                j++;
            }else{
                count++;
                while(i<j){
                    mp[s[i]]--;
                    i++;
                }
            }
        }
        return count;
    }
};
