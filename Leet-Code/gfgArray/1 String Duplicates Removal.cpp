// User function template for C++
// Amazon, Microsoft, Adobe
class Solution {
  public:
    string removeDuplicates(string &s) {
        // code here
        int n = s.length();
        string sr;
        unordered_map<char,int> mp;
        for(int i = 0;i<n;i++){
            char ch = s[i];
            mp[ch]++;
            if(mp[ch]==1){
                sr += s[i];
            }
        }
        return sr;
    }
};
