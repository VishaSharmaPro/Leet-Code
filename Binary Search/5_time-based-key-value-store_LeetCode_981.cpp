// google apple amazon microsoft meta bloomberg oracle uber databricks axon netflix openai coinbase confluent gusto ebay tiktok airbnb instacart lyft
class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";
        vector<pair<int,string>>& op = mp[key];
        int n = op.size();
        int s = 0;
        int e = n-1;
        int mid;
        int result = -1;
        while(s<=e){
            mid = s + (e-s)/2;
            if(op[mid].first > timestamp){
                e = mid-1;
            }else{
                result = mid;
                s = mid +1;
                
            }
        }
        if(result == -1) return "";
        return op[result].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
