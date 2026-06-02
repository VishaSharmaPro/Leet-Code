// microsoft amazon bloomberg google linkedin meta grammarly
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        unordered_map<string,int> mp;
        int j = 9;
        int i = 0;
        set<string> st;
        while(j<n){
            string temp = s.substr(i,j-i+1);
            mp[temp]++;
            if(mp[temp] > 1){
                st.insert(temp);
            }
            i++;
            j++;
        }
        vector<string> vec;
        for(auto & it : st){
            vec.push_back(it);
        }
        return vec;
    }
};
