// Meta (4), Microsoft (3), Amazon (2), Bloomberg (2), Google (2), IBM (3), Zoho (3), Accenture (3), Flipkart (2), Walmart Labs (2), EPAM Systems (2), Target (2), Wipro (2), Visa (2).
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        for(char & ch : s){
            mp[ch]++;
        }
        for(auto & it : mp){
            char ch = it.first;
            int freq = it.second;
            pq.push({freq,ch});
        }
        string ans = "";
        while(!pq.empty()){
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            while(freq--){
                ans += ch;
            }
        }
        return ans;
    }
};
