// google amazon microsoft meta bloomberg tiktok yandex walmart baidu meesho
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.length() == 0) return 0;
        unordered_map<char,int> mp;
        for(int i = 0;i<s.length();i++){
            mp[s[i]]++;
        }
        int i = 0;
        while(i<s.length() && mp[s[i]] >= k) i++;
        if(i == s.length()) return s.length();
        int left =  longestSubstring(s.substr(0,i), k);
        int right = longestSubstring(s.substr(i+1,s.length()-i+1), k);
        return max(left,right);
    }
};

/* jab bhi substring vale problem hote hain hai usme do conexpt lagte hain ya toh sliding window ya divide conquer , question mei agar yeh lage sliding window lagana both hard 
hai sliding window nhi lagpayegi toh turant divide and conquer ka mei cocnept lagao.
*/
