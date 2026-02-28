// Asked in: Amazon, Google, Facebook, Microsoft, Apple, Uber, Walmart Labs, and more
class Solution {
public:
    
    unsigned long long getasciiproduct(const string &word){
        unsigned long long sum = 1;
        unsigned long long product= 1;
        for(char ch : word){
            product *= (int)ch;
            sum += (int)ch;
        }
        return sum + product;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<unsigned long long,vector<string>> mp;
        vector<vector<string>> result;

        for(int i=0;i<n;i++){
            unsigned long long pr = getasciiproduct(strs[i]);
            mp[pr].push_back(strs[i]);
        }
        for(auto &it : mp){
            result.push_back(it.second);
        }
        return result;
    }
};

//const string &word   Iska matlab: function reference le raha hai par modify nahi karega string ko

// unsigned long long Kya Hota Hai?
//🔸 long long → 64-bit signed integer
//Range: −9,223,372,036,854,775,808 to +9,223,372,036,854,775,807

//🔸 unsigned long long → 64-bit unsigned integer
//Range: 0 to 18,446,744,073,709,551,615 

// 2nd approach on 28 February 2026
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        int n = strs.size(); 
        for (int i = 0; i < n; i++) {
            string a = strs[i]; 
            sort(a.begin(), a.end());
            mp[a].push_back(strs[i]); 
        }
        vector<vector<string>> ans;
        for (auto& it : mp) {
            vector<string> b = it.second; 
            vector<string> temp;
            for (string& s : b) {
                temp.push_back(s); 
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
