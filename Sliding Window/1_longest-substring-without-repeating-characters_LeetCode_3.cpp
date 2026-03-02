// amazon google micrsoft bloomberg meta ibm oracle zoho tiktok apple walmart yandex goldman morgan netfix adobe turing accenture  flipkart cisco tesla
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0) return 0;
        unordered_map<char,int> mp;
        int count = 0;
        int maxcount = 1;
        int i = 0;
        int j = 0;
        while(j<n){
                if(mp.find(s[j]) == mp.end()){
                    mp[s[j]]++;
                    count++;
                    maxcount = max(maxcount,count);
                    j++;
                }
                else{
                    mp.erase(s[i]);
                    count--;
                    i++;
                }
        }
        return maxcount;
    }
};
