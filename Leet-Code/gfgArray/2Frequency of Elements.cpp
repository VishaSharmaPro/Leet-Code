class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        // code here
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            int num = arr[i];
            mp[num]++;
        }
        vector<vector<int>> result;
        for(auto &it : mp){
            int numb = it.first;
            int freq = it.second;
            result.push_back({numb,freq});
        }
        return result;
    }
};
