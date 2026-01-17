// company tags = Amazon, Google, Microsoft, Meta, Apple, Bloomberg, IBM, Nvidia, Oracle, Visa, Adobe, Slaesforce, Zoho, turing , Servicenow, Accenture, Uber, Tesla, Walmart, GoldmanSachs, Yandex, Netfilx
class Solution {
public:
    vector<int> vec;
    bool check(char ch){
        if(vec[ch] != 0) return false;
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        vec = vector<int>(128, 0);
        int i = 0;
        int j = 0;
        int maxl = 0;
        int n = s.length();
        while(j < n){
            if(check(s[j]) == false){
                vec[s[i]]--;
                i++;
            }
            else{
                vec[s[j]]++;
                j++;
            }
            maxl = max(maxl, j - i);
        }
        return maxl;
    }
};
