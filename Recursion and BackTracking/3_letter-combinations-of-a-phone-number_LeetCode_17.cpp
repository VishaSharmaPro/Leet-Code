// ggole amazon microsoft meta bloomberg linekdin apple oracle uber tesla accenture ibm zoho  flexport deshaw
class Solution {
public:
    unordered_map<int,string> mp;
    vector<string> ans;
    string temp = "";
    void solve(int i,string digits){
        if(i == digits.length()){
            ans.push_back(temp);
            return;
        }
        int digit = digits[i] - '0';
        string letters = mp[digit];
        for(int j = 0;j<letters.length();j++){
            temp.push_back(letters[j]);
            solve(i+1, digits);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return ans;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        solve(0,digits);
        return ans;
    }
};
