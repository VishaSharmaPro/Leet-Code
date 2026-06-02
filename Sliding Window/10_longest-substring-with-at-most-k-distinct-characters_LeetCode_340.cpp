// google microsoft amazon meta apple oracel yandex tiktok coupang
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.length();
        unordered_map<char,int> mp;
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j<n){
            mp[s[j]]++;
            
            if(mp.size() > k){
                ans = max(ans,j-i);
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            j++;
        }
        ans = max(ans,j-i);
        return ans;
    }
};
