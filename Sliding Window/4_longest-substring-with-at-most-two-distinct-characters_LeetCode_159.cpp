// meta google amazon microsoft tiktok
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int count = 0;
        unordered_map<char,int> mp;
        while(j<n){
            mp[s[j]]++;
            while(mp.size() >2){
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            count = max(count,j-i+1);
            j++;
        }
        return count;
    }
};
