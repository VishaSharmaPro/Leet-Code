// ggole microsft amazon meta bloomberg uber goldman yandex flipkart apple adobe
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        if(n == 0) return 0;
        int count = 0;
        unordered_map<char,int> mp;
        int i = 0;
        int j = 0;
        while(j<n){
            mp[s[j]]++;
            int maxf = 0;
            int sum = 0;
            for(auto & it : mp){
                maxf = max(maxf,it.second);
                sum += it.second;
            }
            int require = sum - maxf;
            if(require <= k){
                count = max(count,j-i+1);
            }else{
                mp[s[i]]--;
                i++;
            } 
            j++;   
        }
        return count;
    }
};
