// google amazon mcirosoft meta bloomberg databricks oracle adobe tiktok goldman accenture yandex walmart
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n > m) return false;
        
        unordered_map<char, int> mp;
        for(int i = 0; i < n; i++) {
            mp[s1[i]]++;
        }
        
        int i = 0;
        int j = 0;
        int count = 0;
        
        while(j < m) {
            if(mp.find(s2[j]) != mp.end() && mp[s2[j]] > 0) {
                mp[s2[j]]--;
                count++;
                if(count == n) {
                    return true;
                }
                j++;
            }
            else {
                if(i < j) {
                    mp[s2[i]]++;
                    count--;
                    i++;
                } else {
                    j++;
                    i++;
                }
            }
        }
        return false;
    }
};
